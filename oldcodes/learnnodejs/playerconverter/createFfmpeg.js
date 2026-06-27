const child_process = require('child_process');
const path = require('path');
/**
 * @param {string} file input video: 'video.mp4' recomended vp9
 * @param {{
 * quality?: '1080' | '720' | '480' | '360',
 * height: string | number,
 * width: string | number,
 * bitrate?: string | number,
 * args?: string[]
 * }} config
 * @returns {child_process.ChildProcess}
 * @example
 * const createFfmpeg = require('./createFfmpeg.js');
 * const fs = require('fs');
 * 
 * const FFMPEG = createFfmpeg("testvideo.mp4", { quality: '720' });
 * 
 * const stream = fs.createWriteStream('./out.mp4');
 * 
 * FFMPEG.stdout.on('data', function (chunk) {
 *  stream.write(chunk);
 * });
 * FFMPEG.stderr.pipe(process.stdout);
 * 
 * // or FFMPEG.pipe(stream);
 */
module.exports = function (file, config) {
    const args = ['-i', `${path.join(__dirname, 'videos', file)}`, '-c:a', 'copy', '-c:v', 'h264', '-movflags', 'frag_keyframe+empty_moov', '-pix_fmt', 'yuv420p', ];
    if(config.quality) {
        const opt = {
            "1080": "1920:1080",
            "720": "1280:720",
            "480": "720:480",
            "360": "640:360",
        }
        if(!opt[config.quality]) {
            config.quality = '360';
        }
        args.push('-vf', `scale=${opt[config.quality]}`);
    } else {
        if(!config.height) {
            config.height = '640';
        }
        if(!config.width) {
            config.width = '360';
        }
        args.push('-vf', `scale=${config.height}:${config.width}`);
    }
    if(config.args) {
        args.push(config.args);
    }
    args.push('-f', 'mp4', 'pipe:1');
    const FFMPEG = child_process.spawn('ffmpeg', args);
    return FFMPEG;
}