const express = require('express');
const socketio = require('socket.io');
const http = require('http');
const path = require('path');


const app = express();//instancia de express
const server = http.createServer(app);//creando el server con http y express como handle request
const io = socketio(server);//iniciando el server de socket.io
const PORT = process.env.PORT || 3000

app.use(express.static(path.join(__dirname, 'public')));

app.get('/', async (req, res) => {
    res.sendFile(path.join(__dirname, 'public/login/index.html'));
});

app.get('/chat', async (req, res) => {
    res.sendFile(path.join(__dirname, 'public/index/index.html'));
});

/*app.get('/dashboard', async (req, res) => {
    srv.guildid = `${req.query.guildid}`;
    srv.channelid = `${req.query.channelid}`;
    //if(req.query.guildid == 'id de opnetwork') {}
    res.sendFile(path.join(__dirname, 'public/botcontrol/index.html'));
});*/

io.on('connection', async (socket) => {
    console.log(`Se conecto el cliente: ${socket.id}, con la ip: ${socket.handshake.address.replace('::ffff:', '')}`);

    socket.on('client/start', async (info) => {
        console.log(info);
        socket.broadcast.emit('server/start', info);
    });

    socket.on('client/msg', async (data) => {
        const by = data.by;
        const text = data.text;
        console.log(by + ": " + text);
        socket.broadcast.emit('server/msg', data);
    });
});

//corriendo el servidor
server.listen(PORT, () => {
    console.log(`Server running in http://localhost:${PORT}`)
});