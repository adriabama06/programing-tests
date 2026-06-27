const express = require('express');
const socketio = require('socket.io');
const http = require('http');
const path = require('path');

const app = express();//instancia de express
const server = http.createServer(app);//creando el server con http y express como handle request
const io = socketio(server);//iniciando el server de socket.io
const PORT = process.env.PORT || 3000

var connection = {};

app.use(express.static(path.join(__dirname, 'public')));

const MData = require('./modules/data.js');
const User = require('./modules/Usuario.js');

const Data = new MData();

app.get('/register', async (req, res) => {
    res.sendFile(path.join(__dirname, 'public/register/index.html'));
});

app.get('/log', async (req, res) => {
    res.send('<h1>OK</h1>');
    console.log(Data.keys());
});

app.get('/', async (req, res) => {
    const id = req.query.id;
    if(!connection[id]) {
        res.redirect('/register');
        return
    }
    const usr = Data.get(connection[id].mail);
    res.send(`${usr.mail} - ${usr.pass} - ${usr.nick}`);
});

app.get('/login', async (req, res) => {
    res.sendFile(path.join(__dirname, 'public/login/index.html'));
});

/*app.get('/dashboard', async (req, res) => {
    srv.guildid = `${req.query.guildid}`;
    srv.channelid = `${req.query.channelid}`;
    //if(req.query.guildid == 'id de opnetwork') {}
    res.sendFile(path.join(__dirname, 'public/botcontrol/index.html'));
});*/

io.on('connection', async (socket) => {
    console.log(`Se conecto el cliente: ${socket.id}, con la ip: ${socket.handshake.address.replace('::ffff:', '')}`);

    socket.on('reg', async (data) => {
        User(data.mail, data.pass, data.nick, Data);
    });

    socket.on('login', async (data) => {
        const usr = await Data.get(data.mail);
        if(!usr.pass == data.pass) return;

        console.log(data.num)

        if(!connection[data.num]) {
            connection[data.num] = {
                num: `${data.num}`,
                mail: `${data.mail}`
            };
        }

        socket.emit('gologin', `${data.num}`);
    });
});

//corriendo el servidor
server.listen(PORT, () => {
    console.log(`Server running in http://localhost:${PORT}`)
});