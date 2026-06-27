const net = require('net');

const connection = net.connect(1818, 'localhost');

connection.pipe(process.stdout);

process.stdin.pipe(connection);