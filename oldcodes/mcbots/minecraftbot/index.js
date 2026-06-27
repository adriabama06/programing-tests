const mineflayer = require('mineflayer');
const modules = require('./modules/index.js');
const config = require('./config.json');

const bot = mineflayer.createBot({
    host: config.host, // optional
    port: config.port,       // optional
    username: config.username, // email and password are required only for
    //password: '12345678',          // online-mode=true servers
    version: 1.8,                 // false corresponds to auto version detection (that's the default), put for example "1.8.8" if you need a specific version
    //auth: 'mojang'      // optional; by default uses mojang, if using a microsoft account, set to 'microsoft'
});

var cmds = require('./cmds.js')();

modules.load(bot);

bot.on('chat', function (username, message) {
    console.log(`${username}: ${message}`);
    if(!message.startsWith(config.prefix)) return;

    const args = message.slice(config.prefix.length).trim().split(/ +/g);
    const cmd = args.shift();
    if(cmds.has(cmd)) {
        cmds.get(cmd).run(bot, username, message, config.prefix, modules);
    }
});

process.stdin.on('data', function (data) {
    if(data.toString().startsWith(config.prefix)) {
        bot.emit('chat', config.username, data.toString());
        return;
    }
    bot.chat(data.toString());
    // bot.chat only send the msg, don't go to the .on('chat') event
    return;
});