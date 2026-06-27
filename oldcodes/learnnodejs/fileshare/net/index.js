const net = require('net');
const server = net.createServer();
const fs = require('fs');
server.on('connection', async (socket) => {
    fs.createReadStream("./tosend/"+fs.readdirSync('./tosend')[0])
    .pipe(socket)
    .on('close', async () => {
        socket.end();
    });
});
server.listen(3000, '192.168.1.114');