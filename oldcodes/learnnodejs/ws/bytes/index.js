const WebSocket = require('ws');
const fs = require('fs');

const wss = new WebSocket.Server({ port: 8080 });

var stream = fs.createWriteStream('./bytes/t.txt');;

wss.on('connection', async (ws) => {
    console.log(`New connection: ${ws.url}`)
    ws.on('message', async (message) => {
        if(message.toString() === 'finish') return stream.close();
        stream.write(message.toString());
    });
});