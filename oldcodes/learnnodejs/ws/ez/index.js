const WebSocket = require('ws');
const fs = require('fs');

const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', async (ws) => {
    ws.on('message', async (message) => {
        fs.writeFileSync('./ex.jpg', message);
        //console.log(`received: ${message}`);
    });

    ws.send('something');
});