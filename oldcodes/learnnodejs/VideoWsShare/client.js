const fs = require('fs');
const net = require('net');

var size = 65536;
var video;

const port = process.argv[2] ? parseInt(process.argv[2]) : 9999;

const socket = net.createConnection({
    port,
    host: '192.168.1.114'
});

socket.on('connect', async () => {
    socket.write('Hello, world!\n');
});

socket.once('data', (data) => {
    size = parseInt(data.toString());
    video = Buffer.alloc(size, Buffer, 'utf8');
    socket.on('data', async (data) => {
        video.write(data);
    });
    socket.write('OK');
});

socket.on('end', async () => {
    fs.writeFileSync('out.mp4', video, { encoding: 'utf8' });
});