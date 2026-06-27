const config = require('./config.json');

const mysql = require('mysql').createConnection({
        host: config.mysqlhost,
        user: config.mysqluser,
        password: config.mysqlpass,
        database: config.mysqldb
    });
mysql.connect();
const express = require('express');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const socketio = require('socket.io');
const http = require('http');
const path = require('path');

const app = express();

const server = http.createServer(app);
const io = socketio(server);
const PORT = process.env.PORT || 3000;

app.use(cookieParser());
app.use(session({secret: "oknoseporquedebedeserlo"}));
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'ejs');

app.get('/login', async (req, res) => {
    if(req.query.l && req.query.p) {

        const sql = `SELECT * FROM ${config.mysqldb}.users WHERE \`user\` = '${req.query.l}' && \`pass\` = '${req.query.p}'`;

        mysql.query(sql, async (err, results, fields) => { // RESULTS == RowDataPacket { user: 'adria', pass: 'mypass' }
            if(err || !results[0]) {
                res.redirect('/login');
            } else {
                console.log(results[0].user + ' : '+ results[0].pass);
                res.send('ok');
            }
        });
    } else {
        res.render(path.join(__dirname, "public\\login\\index.html"));
    }
});

io.on('connection', async (socket) => {
    console.log(`Se conecto el cliente: ${socket.id}, con la ip: ${socket.handshake.address.replace('::ffff:', '')}`);
});

server.listen(PORT, () => {
    console.log(`Server running in http://localhost:${PORT}`)
});