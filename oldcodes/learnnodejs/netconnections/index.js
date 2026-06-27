const net = require('net');

const server = net.createServer();

server.on('connection', (socket) => {
    socket.write('hola\n');
    process.stdin.pipe(socket);
    socket.pipe(process.stdout);
});

server.listen(1818, 'localhost');