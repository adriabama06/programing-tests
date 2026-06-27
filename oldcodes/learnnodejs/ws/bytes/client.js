const WebSocket = require('ws');
const fs = require('fs');

const ws = new WebSocket('ws://localhost:8080');

ws.on('open', async () => {
    //var f = fs.createReadStream('./bytes/img.jpg');
    //f.on('data', sendchunk);
    //f.on('end', () => console.log('EnD') && ws.send('finish'));
    ws.send('hola');
    ws.send("que tal");
    ws.send('finish');
});