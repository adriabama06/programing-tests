const ytdl = require('ytdl-core');
const child_process = require('child_process');
const path = require('path');


const audio = ytdl('https://youtu.be/bWLgA4jUkuw', { quality: 'highestaudio', filter: 'audioonly' });

const ffmpeg = child_process.exec('ffmpeg -i pipe:1 -map 0:a -c:a libmp3lame -b:a 192k {file}'.replace('{file}', `${path.join(__dirname, 'audios/auido.mp3')}`),
{
    stdio: ['pipe'],
});

audio.pipe(ffmpeg.stdio[1]);