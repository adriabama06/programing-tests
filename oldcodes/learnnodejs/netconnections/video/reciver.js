const net = require('net');
const fs = require('fs');

const ws = fs.createWriteStream('./recived.txt');

const connection = net.connect(1818, 'localhost');

/*connection.on('data', async (data) => {
    ws.write(data);
});*/

connection.pipe(ws);