async function sleep(ms) {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
};

var __log = true;

const child_process = require('child_process');
var child = child_process.spawn('cmd');
child.stdin.setDefaultEncoding('utf-8');
const Discord = require('discord.js');

const prefix = "sell ";

const client = new Discord.Client();

client.on('ready', async () => {
    console.log('Ready');
    client.guilds.cache.get('752574985880600788').channels.cache.get('769603232501858386')
    .send('Bot iniciado');
});

client.on('message', async (message) => {
    if(message.author.bot) return;
    if(!message.channel.id == '793884631429808139') {
        return;
    };

    const args = message.content.slice(0).trim().split(/ +/);
    child.stdin.write(`${args.join(' ')}`+ '\n');
});

client.on('message', async (message) => {
    if(!message.content.toLowerCase().startsWith('sell') || !message.guild || message.author.bot) {
        return;
    };

    const args = message.content.slice(prefix.length).trim().split(/ +/);
    const command = args.shift().toLowerCase();

    switch (command) {
        case 'args':
            message.channel.send(args + " --- " + command);
            console.log(args + " --- " + command);
            break;


        case 'start':
            message.channel.send('Iniciando log');
            __log = true;
            break;


        case 'stop':
            message.channel.send('Desactivando log');
            __log = false;
            break;


        case 'log':
            message.channel.send(__log);
            break;


        case 'send':
            child.stdin.write(`${args.join(' ')}`+ '\n');
            break;
        

        case 'restart':
            message.channel.send('Reiniciado!');
            child.kill('SIGTERM');
            await sleep(500);
            child = child_process.spawn('cmd');
            break;
        
        
        
        default:
            return;
    };
});

child.stdout.on('data', async (data) => {
    console.log(data.toString());
    if(__log == false) {
        return;
    };
    client.guilds.cache.get('752574985880600788').channels.cache.get('793884631429808139')
    .send(data.toString());
});

child.stderr.on('data', async (data) => {
    console.log(data.toString());
    if(__log == false) {
        return;
    };
    client.guilds.cache.get('752574985880600788').channels.cache.get('793884631429808139')
    .send("Error: " + data.toString());
});

child.on('close', async (code) => {
    console.log(code);
    if(__log == false) {
        return;
    };
    client.guilds.cache.get('752574985880600788').channels.cache.get('793884631429808139')
    .send("Exit code: " + code);
});

client.login('TOKEN_ELIMINADO');