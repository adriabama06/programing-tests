const WebSocket = require('ws');
const fs = require('fs');

const ws = new WebSocket('ws://localhost:8080');

ws.on('open', async () => {
    var f = fs.readFileSync('img.jpg');
    ws.send(f);
});