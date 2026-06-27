const mineflayer = require('mineflayer');
const { mineflayer: mineflayerViewer } = require('prismarine-viewer')
const config = require('./config.json');
const fs = require('fs');
const pathfinder = require('mineflayer-pathfinder').pathfinder;
const Movements = require('mineflayer-pathfinder').Movements;

const bot = mineflayer.createBot({
    host: config.ip,             // minecraft server ip
    username: config.nick, // minecraft username
    // password: '12345678',          // minecraft password, comment out if you want to log into online-mode=false servers
    port: config.port,                // only set if you need a port that isn't 25565
    version: 1.8,             // only set if you need a specific version or snapshot (ie: "1.8.9" or "1.16.5"), otherwise it's set automatically
    // auth: 'mojang'              // only set if you need microsoft auth, then set this to 'microsoft'
});

bot.loadPlugin(pathfinder);

const cmds = new Map();

for(const file of fs.readdirSync('./cmds').filter(d => d.endsWith('.js'))) {
    const m = require(`./cmds/${file}`);
    cmds.set(m.cmd, m)
}

bot.on('chat', async (username, message) => {
    if(!message.startsWith(config.prefix));
    const args = message.slice(config.prefix.length).split(/ +/g);
    const cmd = args.shift();

    if(cmds.has(cmd)) {
        cmds.get(cmd).run(bot, username, message, args);
    }
});

bot.once('spawn', async () => {
    const mcData = require('minecraft-data')(bot.version);

    const defaultMove = new Movements(bot, mcData);

    bot.pathfinder.setMovements(defaultMove);

    mineflayerViewer(bot, { port: 3007, firstPerson: true }) // port is the minecraft server port, if first person is false, you get a bird's-eye view
});