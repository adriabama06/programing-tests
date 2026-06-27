async function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}
async function optimize(input, output) {

    // -r 60 == 60 FPS
    /*
    SLOW BUT HAVE MORE CONTROL:

    primer map es para la primera pista de video y el segundo para la primera pista de audio :D
    ffmpeg -i "video.mp4" -map 0:0 -map 0:1 -acodec mp3 -vcodec MPEG4 makosta vp9 h264 (buscar con ffmpeg -codecs para ver la lista) "out.mp4"

    NVIDIA:
    ffmpeg -i songvideo.mp4 -map 0:0 -map 0:1 -acodec mp3 -vcodec h264_nvenc -profile high -preset medium ou.mp4
    */

    const { exec } = require('child_process'); // h264 CPU / h264_nvenc GPU
    exec(`ffmpeg -i "${input}" -map 0:0 -map 0:1 -acodec mp3 -vcodec h264_nvenc -profile high -preset medium "${output}"`, async (error, stdout, stderr) => {
        if (error) {
            console.log(`error: ${error.message}`);
            return;
        }
        if (stderr) {
            console.log(`stderr: ${stderr}`);
            return;
        }
        console.log(`stdout: ${stdout}`);
    });
};

const ChromecastAPI = require('chromecast-api');

const express = require('express');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const socketio = require('socket.io');
const http = require('http');
const path = require('path');
const multer = require('multer');
const fs = require('fs');

const app = express();

const server = http.createServer(app);
const io = socketio(server);
const PORT = process.env.PORT || 3002;

app.use(cookieParser());
app.use(session({secret: "oknoseporquedebedeserlo"}));
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'ejs');

const storage = multer.diskStorage({
    destination: (req, file, cb) => {
      cb(null, path.join(__dirname, 'video'));
    },
    filename: (req, file, cb) => {
      cb(null, `in.mkv`);
    }
});

const upload = multer({storage});

const client = new ChromecastAPI();

var chrome;

client.on('device', async (device) => {

    chrome = device;
/*
    //console.log(client.devices);
    var mediaURL = "http://mysql-opnetwork.ddns.net:3001/Minecraftsurvival3.mp4";
    //var mediaURL = 'https://www.youtube.com/watch?v=mFCYZS71kEM';

    device.play(mediaURL, async (err) => {
        if (!err) console.log('Playing in your chromecast')
    });
*/
    device.on('finished', async (err) => {
        if(!err) console.log('I finished');
    });
});

app.get('/css', async (req, res) => {
    res.sendFile(path.join(__dirname, 'public\\css.css'));
});

app.get('/index', async (req, res) => {
    res.download();
});

app.get('/', async (req, res) => {
    var c;
    if(chrome) {
        c = "<h3>Chromecast detectado</h3>";
    } else {
        c = "<h3>Chromecast no detectado</h3>";
    }
    res.render(path.join(__dirname, "public\\index.html"), { c });
});

app.get('/player', async (req, res) => {
    res.render(path.join(__dirname, "public\\player.html"));
});

app.get('/upload', async (req, res) => {
    res.render(path.join(__dirname, "public\\upload.html"));
});

app.get('/video', async (req, res) => {
    res.sendFile(path.join(__dirname, "video\\chro.mp4"));
});

app.post('/up', upload.single('file'), async (req, res) => {

    optimize(path.join(__dirname, `video\\in.mkv`), path.join(__dirname, `video\\chro.mp4`));

    res.redirect('/player');

    

    /*if(!req.files || Object.keys(req.files).length === 0) {
        return res.status(400).send('No have files.');
    }
    
      // The name of the input field (i.e. "sampleFile") is used to retrieve the uploaded file
      console.log(req.files);

      let video = req.files.video;
    
      // Use the mv() method to place the file somewhere on your server
      video.mv(path.join(__dirname, `video\\${video.name}`), async (err) => {
          if (err) {
              return res.status(500).send(err);
          }
          res.send('Cargando...');
          optimize(path.join(__dirname, `video\\${video.name}`), path.join(__dirname, `video\\chro.mp4`));
          await sleep(5000);
          res.redirect('/player');
      });*/
});

io.on('connection', async (socket) => {
    socket.on('pause', async () => {
        chrome.pause();
    });

    socket.on('resume', async () => {
        chrome.resume();
    });

    socket.on('skip', async (data) => {
        chrome.seekTo(data);
    });

    socket.on('play', async () => {
        var mediaURL = 'http://mysql-opnetwork.ddns.net:3002/video';

        chrome.play(mediaURL, async (err) => {
            if (!err) console.log('Playing in your chromecast')
        });
    });

    socket.on('stop', async () => {
        chrome.stop();
    });
});

server.listen(PORT, () => {
    console.log(`Server running in http://localhost:${PORT}`)
});