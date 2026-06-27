const createFfmpeg = require('./createFfmpeg.js');
const fs = require('fs');

const FFMPEG = createFfmpeg("testvideo.mp4", { quality: '360' });

const stream = fs.createWriteStream('./out.mp4');

FFMPEG.stdout.on('data', function (chunk) {
    stream.write(chunk);
});
FFMPEG.stderr.pipe(process.stdout);