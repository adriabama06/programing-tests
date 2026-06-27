const mineflayer = require('mineflayer');
const modules = require('../modules/index.js');

module.exports = {
    cmd: 'come',
    /**
     * @param {mineflayer.Bot} bot
     * @param {string} username
     * @param {string} message
     * @param {string} prefix
     * @param {modules} modules
     */
    run: async function (bot, username, message, prefix, modules) {
        bot.chat('come command');
    }
}