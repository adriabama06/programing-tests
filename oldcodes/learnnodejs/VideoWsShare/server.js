const fs = require('fs');
const net = require('net');

const size = 65536;

const port = process.argv[2] ? parseInt(process.argv[2]) : 9999;

const video = fs.createReadStream("video.mp4", { encoding: 'utf8' });

const server = net.createServer(async (socket) => {
    socket.on('connect', async () => {
        socket.write(fs.statSync("video.mp4").size.toString());
    });
    socket.on('data', async (data) => {
        if(data.toString() === 'end') {
            socket.end();
        }
        while(video.destroyed == false) {
            socket.write(video.read(size));
        }
    });
});

server.listen(port, '0.0.0.0')