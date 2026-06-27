const WebSocketServer = require('websocket').server;
const http = require('http');
const fs = require('fs');

const server = http.createServer(function (request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(8080, function () {
    console.log((new Date()) + ' Server is listening on port 8080');
});

const wsServer = new WebSocketServer({
    httpServer: server,
    // You should not use autoAcceptConnections for production
    // applications, as it defeats all standard cross-origin protection
    // facilities built into the protocol and the browser.  You should
    // *always* verify the connection's origin and decide whether or not
    // to accept it.
    autoAcceptConnections: false
});

function originIsAllowed(origin) {
     // put logic here to detect whether the specified origin is allowed.
    return true;
};

wsServer.on('request', async function (request) {
    if (!originIsAllowed(request.origin)) {
        // Make sure we only accept requests from an allowed origin
        request.reject();
        console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
        return;
    };
    
    const connection = request.accept('echo-protocol', request.origin);
    console.log((new Date()) + ' Connection accepted.');
    connection.on('message', async function (message) {
        /**
         * @type {{
         * on: string,
         * message: any
         * }}
         */
        const msg = JSON.parse(message.binaryData.toString());
        
        if(msg.on === 'start') {
            fs.createReadStream(fs.readdirSync('./tosend')[0])
            .on()
        };
    });
    connection.on('close', async function (reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
    });
});