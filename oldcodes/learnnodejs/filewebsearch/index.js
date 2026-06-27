const express = require('express');
const fileUpload = require('express-fileupload');
const socketio = require('socket.io');
const http = require('http');
const path = require('path');
const fs = require('fs');


const app = express();//instancia de express
const server = http.createServer(app);//creando el server con http y express como handle request
const io = socketio(server);//iniciando el server de socket.io
const PORT = process.env.PORT || 3001

app.use(express.static(path.join(__dirname, 'public')));
app.use(fileUpload());
app.get('/', async (req, res) => {
    var data = `<link rel="stylesheet" href="http://mysql-opnetwork.ddns.net:3000/css.css">\n<ul style="list-style-type:none;" >`;
    const files = fs.readdirSync(path.join(__dirname, 'public'));
    for(const file of files) {
        var ico;
        if(file.endsWith('js')) {
            ico = ``
        }
        data = data + `\n<li><a href="/${file}">${file} </a><a href="/download?f=${file}">Download</a></li>`;
    }
    data = data + `</ul>`
    res.send(data);
});

app.get('/download', async (req, res) => {
    const file = req.query.f;
    const data = path.join(__dirname, 'public');
    if(!fs.existsSync(data + "/" + file)) {
        res.send("<p>Error 404 File not found</p>");
        return;
    }
    res.download(data + "\\" + file);
});

app.get('/upload', async (req, res) => {
    res.send(`
        <html>
        <body>
        <form ref='uploadForm' id='uploadForm' action='/up' method='post' encType="multipart/form-data">
            <input type="file" name="sampleFile" />
            <input type='submit' value='Upload!' />
        </form>     
        </body>
        </html>
    `)
});
app.post('/up', async (req, res) => {
    if (!req.files || Object.keys(req.files).length === 0) {
        return res.status(400).send('No files were uploaded.');
      }
    
      // The name of the input field (i.e. "sampleFile") is used to retrieve the uploaded file
      let sampleFile = req.files.sampleFile;
    
      // Use the mv() method to place the file somewhere on your server
      sampleFile.mv(path.join(__dirname, `public\\${sampleFile.name}`), function(err) {
        if (err)
          return res.status(500).send(err);
    
        res.send('File uploaded!');
      });
});

/*app.get('/dashboard', async (req, res) => {
    srv.guildid = `${req.query.guildid}`;
    srv.channelid = `${req.query.channelid}`;
    //if(req.query.guildid == 'id de opnetwork') {}
    res.sendFile(path.join(__dirname, 'public/botcontrol/index.html'));
});*/

io.on('connection', async (socket) => {
    console.log(`Se conecto el cliente: ${socket.id}, con la ip: ${socket.handshake.address.replace('::ffff:', '')}`);

    socket.on('getdir', async (info) => {
        console.log(info);
        socket.broadcast.emit('server/start', info);
    });
});

//corriendo el servidor
server.listen(PORT, () => {
    console.log(`Server running in http://localhost:${PORT}`)
});