const mineflayer = require('mineflayer');
const { toolvalor } = require('./util.js');

/**
 * @param {mineflayer.Bot} bot
 * @param {'sword' | 'armor'} type
 * @returns {Promise<{valor: number,name: string,slot: number,count: number,displayName: string,metadata: number,ntb: Buffer,stackSize: number,type: number,}>}
 */
module.exports.bestininv = async (bot, type) => {

    var fn = toolvalor;

    var items = bot.inventory.items().filter(item => item.name.endsWith('_sword'));
    
    if(type === 'armor') {
        fn = toolvalor;
        items = bot.inventory.items().filter(item => item.name.endsWith('_leggings') || item.name.endsWith('_boots') || item.name.endsWith('_helmet') || item.name.endsWith('_chestplate'));
    };

    var to = {
        valor: fn(items[0].name),
        name: items[0].name,
        slot: items[0].slot,
        count: items[0].count,
        displayName: items[0].displayName,
        metadata: items[0].metadata,
        ntb: items[0].nbt,
        stackSize: items[0].stackSize,
        type: items[0].type,
    };

    for(const i of items) {
        if(fn(i.name) > to.valor) {
            to.valor = fn(i.name);
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