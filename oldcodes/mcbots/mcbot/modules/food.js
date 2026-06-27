const mineflayer = require('mineflayer');
const { sleep } = require('../modules');
const { bestfood } = require('./util');



/**
 * @returns {Promise<boolean>}
 * @param {mineflayer.Bot} bot 
 */
module.exports.foodevent = async (bot) => {
    setInterval(async () => {
        if(bot.food <= 8 || bot.health <= 6) {
            var item = await this.autofood(bot);
            if(item === false) return;
            await bot.clickWindow(item.slot, 0, 0, async (err) => {
                if(err) console.log(err);
            });
            await bot.clickWindow(1 + 35, 0, 0, async (err) => {
                if(err) console.log(err);
            });
            await bot.clickWindow(item.slot, 0, 0, async (err) => {
                if(err) console.log(err);
            });
        };
    }, 5000);
    return true;
};



/**
 * returns {Promise<boolean>}
 * @param {mineflayer.Bot} bot 
 */
module.exports.autofood = (bot) => {
    var items = bot.inventory.items().filter(item => item.name.startsWith('baked_potato')
    || item.name.startsWith('cooked_chicken')
    || item.name.startsWith('bread')
    || item.name.startsWith('cooked_mutton')
    || item.name.startsWith('cooked_beef')
    || item.name.startsWith('cooked_porkchop')
    || item.name.startsWith('apple')
    || item.name.startsWith('golden_carrot')
    || item.name.startsWith('carrot')
    || item.name.startsWith('golden_apple'));
    if(!items || items.length === 0) return false;
    /**
     * @type {'heal' | 'food'} type
     */
    var type = 'food';

    if(bot.health <= 6) {
        type = 'heal';
    };

    var to = {
        valor: bestfood(items[0].name ? items[0].name : items[0].displayName, type),
        name: items[0].name ? items[0].name : items[0].displayName,
        slot: items[0].slot,
        count: items[0].count,
        displayName: items[0].displayName,
        metadata: items[0].metadata,
        ntb: items[0].nbt,
        stackSize: items[0].stackSize,
        type: items[0].type,
    };

    for(const i of items) {
        if(bestfood(i.name, type) > to.valor) {
            to.valor = bestfood(i.name, type);
            to.name = i.name;
            to.slot = i.slot;
            to.count = i.count;
            to.displayName = i.displayName;
            to.metadata = i.metadata;
            to.ntb = i.ntb;
            to.stackSize = i.stackSize;
            to.type = i.type;
        };
    };
    return to;
};