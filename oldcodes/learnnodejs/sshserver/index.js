const allowedUser = 'opnetvs'
const allowedPassword = 'XLu8EoNd';

const { Server } = require('ssh2');
const fs = require('fs');

const server = new Server({
    hostKeys: [{
            key: fs.readFileSync(require('path').join(__dirname, 'host.key')),
        },
    ],
});

server.on('connection', async function (client) {
    client.on('authentication', async function (ctx) {
        ctx.accept();
        var allow = true;
        if(!Buffer.from(ctx.username) === Buffer.from(allowedUser)) {
            allow = false;
        };
        switch(ctx.method) {
            case "password":
                if(!Buffer.from(ctx.password) === Buffer.from(allowedPassword)) {
                    ctx.reject();
                };
                break;
            default:
                return ctx.reject();
        };
        if(allow === true) {
            ctx.accept();
        } else {
            ctx.reject();
        };
    });
    client.on('ready', async function() {
        client.on('session', async function (accept, reject) {
            const session = accept();
            session.once('exec', (accept, reject, info) => {
                console.log('Client wants to execute: ' + info.command);
                const stream = accept();
                stream.stderr.write('Oh no, the dreaded errors!\n');
                stream.write('Just kidding about the errors!\n');
                stream.exit(0);
                stream.end();
            });
        });
    });
    client.on('close', async function(err) {
        if(err) console.log(err);
    });
});

server.listen(8080, "0.0.0.0");