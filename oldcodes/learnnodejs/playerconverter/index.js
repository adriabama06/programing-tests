const fs = require('fs');
const express = require('express');
const child_process = require('child_process');
const createFfmpeg = require('./createFfmpeg.js');
const path = require('path');

const app = express();

const PORT = 8080;

app.get('/', async (req, res) => {

});

app.get('/get/:video', async (req, res) => {
    
});

app.get('/v/:video', async (req, res) => {
    var range = req.headers.range;
    if(!range) {
        //res.status(400).send("Requires range header");
        range = "0";
    }
    if(!req.params.video) {
        return res.status(404).send("Video not found");
    }
    const Video = path.join(__dirname, `videos/${req.params.video}`);
    const VideoInfo = fs.statSync(Video);

    /*
        Parse range of load
    */
    var CHUNK_SIZE = 50 ** 6; // 5MB as max for one connexion
    if(req.params.video.endsWith("-4k")) {
        CHUNK_SIZE = 200 ** 6;
    };
    const start = Number(range.replace(/\D/g, ""));
    const end = Math.min(start + CHUNK_SIZE, VideoInfo.size - 1);

    const contentLength = end - start + 1;
    const headers = {
        "Content-Range": `bytes ${start}-${end}/${VideoInfo.size}`,
        "Accept-Ranges": "bytes",
        "Content-Type": "video/mp4",
        "Content-Length": contentLength,
    }

    res.writeHead(206, headers);

    if(req.query.quality) {
        const VideoStream = createFfmpeg(req.params.video, {
            quality: req.query.quality,
        });
        VideoStream.stdout.pipe(res);
    } else {
        const VideoStream = fs.createReadStream(Video, { start, end });
        VideoStream.pipe(res);
    }
});


app.listen(PORT, async () => {
    console.log('Started !');
});