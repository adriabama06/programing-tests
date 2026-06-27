const mineflayer = require('mineflayer');

/**
* @returns {Promise<number>}
* @param {number} ms 
*/

module.exports.sleep = async (ms) => {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
};

/**
 * @param {string} name
 * @returns {number}
 */
module.exports.swordvalor = (name) => {
    if(name.startsWith('netherite')) {
        return 6;
    };
    if(name.startsWith('diamond')) {
        return 5;
    };
    if(name.startsWith('iron')) {
        return 4;
    };
    if(name.startsWith('stone')) {
        return 3;
    };
    if(name.startsWith('wooden')) {
        return 2;
    };
    if(name.startsWith('golden')) {
        return 1;
    };
};

/**
 * @param {mineflayer.Bot} bot
 * @returns {{name: string, valor: number, slot: number}}
 */
module.exports.bestsword = async (bot) => {
    var items = bot.inventory.items().filter(item => item.name.endsWith('_sword'));

    var to = {
        name: items[0].name,
        valor: this.swordvalor(items[0].name),
        slot: items[0].slot,
    };

    for(const i of items) {
        if(this.swordvalor(i.name) > to.valor) {
            to.name = i.name;
            to.valor = this.swordvalor(i.name);
            to.slot = i.slot;
        };
    };

    return to;
};