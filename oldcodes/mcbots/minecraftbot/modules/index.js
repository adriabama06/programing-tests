const mineflayer = require('mineflayer');
const moviment = require('./moviment.js');
const util = require('./util.js');
module.exports = {
    /**
     * @type {mineflayer.Bot}
     */
    bot: false,
    moviment,
    util,
}

/**
 * @param {mineflayer.Bot} bot 
 */
module.exports.load = function (bot) {
    moviment.load(bot);
    this.bot = bot;
}