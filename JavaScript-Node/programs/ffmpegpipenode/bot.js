const Discord = require('discord.js');
const ytdl = require('ytdl-core');
const child_process = require('child_process');
const path = require('path');
const fs = require('fs');

function normalize(text = "") {
    return text.replace(/[/:?*|&<>"], /g, '');
};

const client = new Discord.Client();

/**
 * @type {Discord.VoiceConnection}
 */
var connection;
/**
 * @type {Discord.StreamDispatcher}
 */
var dispatcher;

client.on('message', async (message) => {

    if(message.content.toLowerCase().startsWith('!play')) {
        //var name = path.join(__dirname, `temp/${Math.random().toString().replace('.', '')}.opus`);
        const audio = ytdl('https://youtu.be/dQw4w9WgXcQ', { quality: 'highestaudio', filter: 'audioonly' });
        const ffmpeg = child_process.exec(`ffmpeg -i pipe:1 -map 0:a -c:a libopus -b:a 96k pipe:2`,
        {
            stdio: ['pipe', 'pipe'],
        });
        audio.pipe(ffmpeg.stdio[1]);
        connection = await message.member.voice.channel.join();
        dispatcher = connection.play();
        //dispatcher.on('finish', fs.unlinkSync(name));
    };

});

client.login('');