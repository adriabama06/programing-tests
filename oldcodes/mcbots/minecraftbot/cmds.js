const mineflayer = require('mineflayer');
const fs = require('fs');
const path = require('path');
const modules = require('./modules/index.js');

module.exports = function () {
    const files = fs.readdirSync(path.join(__dirname, 'cmds')).filter(f => f.endsWith('.js'));
    /**
     * @type {Map<string, { cmd: string, run: (bot: mineflayer.Bot, username: string, message: string, prefix: string, modules: modules) => void }>}
     */
    var cmds = new Map();
    for(const file of files) {
        const cmd = require(path.join(__dirname, 'cmds', file));
        cmds.set(cmd.cmd, cmd);
    }
    return cmds;
}