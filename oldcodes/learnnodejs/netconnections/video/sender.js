const net = require('net');
const fs = require('fs');

const server = net.createServer();

server.on('connection', (socket) => {
    const rs = fs.createReadStream('./tosend.txt');
    /*rs.on('data', async (data) => {
        socket.write(data);
    });*/
    rs.pipe(socket);
    rs.on('close', async () => {
        socket.end();
    });
});

server.listen(1818, 'localhost');