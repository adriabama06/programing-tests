const mineflayer = require('mineflayer');
const pathfinder = require('mineflayer-pathfinder').pathfinder;
const Movements = require('mineflayer-pathfinder').Movements;
const { GoalNear, GoalFollow, GoalXZ } = require('mineflayer-pathfinder').goals;
const { Vec3 } = require('vec3');
const modules = require('./modules.js');

/**
 * @returns {Promise<number>}
 * @param {number} ms 
 */

async function sleep(ms) {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
};

const bot = mineflayer.createBot({
    host: 'localhost',
    //host: 'adriabama06_.aternos.me', // optional
    //port: 25565,       // optional
    username: 'afkonline', // email and password are required only for
    //password: '12345678',          // online-mode=true servers
    version: 1.8,                 // false corresponds to auto version detection (that's the default), put for example "1.8.8" if you need a specific version
    //auth: 'mojang'      // optional; by default uses mojang, if using a microsoft account, set to 'microsoft'
});
process.stdin.on('data', async (data) => {
    bot.chat(data.toString().replace('\n', ''));
});

bot.loadPlugin(pathfinder);

const mcData = require('minecraft-data')(bot.version);

const defaultMove = new Movements(bot, mcData);

defaultMove.scafoldingBlocks = [];
defaultMove.scafoldingBlocks.push(mcData.blocksByName.dirt.id);
defaultMove.scafoldingBlocks.push(mcData.blocksByName.planks.id);
defaultMove.scafoldingBlocks.push(mcData.blocksByName.cobblestone.id);
defaultMove.scafoldingBlocks.push(mcData.blocksByName.obsidian.id);
defaultMove.scafoldingBlocks.push(mcData.blocksByName.wool.id);

bot.pathfinder.setMovements(defaultMove);

bot.on('spawn', async () => {
    //await sleep(5000);
    //bot.chat("/register Adriaba Adriaba");
    //bot.chat("/login Adriaba");
    /*await sleep(20000);
    bot.pathfinder.setGoal(new GoalNear(51, 95, -1));
    await sleep(60000);

    const mobFilter = (entity) => entity.type === 'player' || entity.type === 'mob';
    const mob = bot.nearestEntity(mobFilter);
    
    if(mob) {
        const pos = new Vec3(mob.position.x, (mob.position.y+1.5), mob.position.z);
        const dist = bot.entity.position.distanceTo(pos);
        if(dist < 3.7) { //3.7
            bot.lookAt(pos, true, async () => {
                bot.activateEntity(mob, async (err) => {
                    if(err) console.log(err);
                });
            });
        };
    };*/
});

const prefix = "!";

bot.on('chat', async (username, message) => {
    console.log(`${username}: ${message}`);
    if(!message.startsWith(prefix)) return;
    const args = message.slice(prefix.length).trim().split(/ +/g);
    const cmd = args.shift().toLowerCase();
    if(cmd == 'come') {
        var target;
        if(args[0]) {
            target = bot.players[`${args[0]}`].entity;
        } else {
            target = bot.players[`${username}`].entity;
        };
        if(!target) {
            console.log(`No pude encontrar al jugador ..`); ///tell ${username}
            return;
        };
        const p = target.position;
        bot.pathfinder.setGoal(new GoalNear(p.x, p.y, p.z, 1));
    };

    if(cmd == 'goto') {
        if(!args[0] && !args[1] && !args[2]) {
            return;
        };
        var x = parseInt(args[1]);
        var y = parseInt(args[2]);
        var z = parseInt(args[3]);
        bot.pathfinder.setGoal(new GoalNear(x, y, z, 1));
    };

    if(cmd == 'xz') {
        if(!args[0] && !args[1]) {
            return;
        };
        var x = parseInt(args[0]);
        var z = parseInt(args[1]);
        bot.pathfinder.setGoal(new GoalXZ(x, z));
    };

    if(cmd == 'follow') {
        var target;
        if(args[0]) {
            target = bot.players[`${args[0]}`].entity;
        } else {
            target = bot.players[`${username}`].entity;
        };
        if(!target) {
            console.log(`No pude encontrar al jugador ..`); ///tell ${username}
            return;
        };
        bot.pathfinder.setGoal(new GoalFollow(target, 1), true);
    };

    if(cmd == 'stop') {
        bot.pathfinder.setGoal(new GoalNear(bot.player.entity.position.x, bot.player.entity.position.y, bot.player.entity.position.z, 1));
    };

    if(cmd == 'slot') {
        var calculate = parseInt(args[0]);
        var slot = calculate - 1;

        /*if(isNaN(slot)) {
          bot.chat(`/tell ${username} Debe de poner un numero`);
          return
        } else if(slot > 8 || slot < 0) {
          bot.chat(`/tell ${username} Debe de poner un numero que vaya del 1 al 9`);
          return
        }*/
        bot.setQuickBarSlot(slot);
    };

    if(cmd == 'use') {
        bot.activateItem();
    };
    if(cmd == 'unuse') {
        bot.deactivateItem();
    };

    if(cmd == 'barmv') {
        if(!args[0] && !args[1]) {
            return;
        };

        const item = parseInt(args[0]);
        const to = parseInt(args[1]);

        //bot.inventory.on;
        await bot.clickWindow(item + 35, 0, 0, async (err) => {
            if(err) console.log(err);
        });
        await bot.clickWindow(to + 35, 0, 0, async (err) => {
            if(err) console.log(err);
        });
    };

    if(cmd == 'kill') {
        //const playerCI = bot.players['TheDudeFromCI']
        //const playerFilter = (entity) => entity.type === 'player' mob
        //const mobFilter = e => e.type === 'player' && e.type === 'mob';// && e.mobType === 'Zombie'
        /*const mobFilter = (entity) => entity.type === 'player' || entity.type === 'mob'
            const mob = bot.nearestEntity(mobFilter)
    
            if (!mob) return;
    
            const pos = new Vec3(mob.position.x, (mob.position.y+1.5), mob.position.z);
            const dist = bot.entity.position.distanceTo(pos);
            if(dist > 3.7) { //3.7
                return;
            };
            bot.lookAt(pos, true, async () => {
                bot.attack(mob, true);
            });
            await sleep(200);*/
        var max = 1;
        if(args[0]) {
            max = parseInt(args[0]);
        };
        for(var i = 0; i < max; i++) {
            const mobFilter = (entity) => entity.type === 'player' || entity.type === 'mob';
            const mob = bot.nearestEntity(mobFilter);
    
            if(mob) {
                const pos = new Vec3(mob.position.x, (mob.position.y+1.5), mob.position.z);
                const dist = bot.entity.position.distanceTo(pos);
                if(dist < 5) { //3.7
                    bot.lookAt(pos, true, async () => {
                        await bot.setQuickBarSlot(0);

                        if(!bot.heldItem.name.endsWith('_sword')) {
                            var to = await modules.bestsword(bot);

                            if(to) {
                                await bot.clickWindow(to.slot, 0, 0, async (err) => {
                                    if(err) console.log(err);
                                });
                                await bot.clickWindow(1 + 35, 0, 0, async (err) => {
                                    if(err) console.log(err);
                                });
                            };
                        };

                        bot.attack(mob, true);
                    });
                };
            };
            await sleep(100);
        };
    };

    if(cmd == 'int') {
        const mobFilter = (entity) => entity.type === 'player' || entity.type === 'mob';
        const mob = bot.nearestEntity(mobFilter);
    
        if(mob) {
            const pos = new Vec3(mob.position.x, (mob.position.y+1.5), mob.position.z);
            const dist = bot.entity.position.distanceTo(pos);
            if(dist < 3.7) { //3.7
                bot.lookAt(pos, true, async () => {
                    bot.activateEntity(mob, async (err) => {
                        if(err) console.log(err);
                    });
                });
            };
        };
    };

    if(cmd == 'say') {
        const tosay = args.join(' ');
        bot.chat(tosay);
    };

    if(cmd == 'inv') {
        if (bot.inventory.items().length === 0) return bot.chat('No tengo ningun item');
        const item = bot.inventory.items()[0];
        bot.chat(`${item}`);
    };

    if(cmd == 'dropall') {
        function tossNext () {
            if (bot.inventory.items().length === 0) return
            const item = bot.inventory.items()[0]
            bot.tossStack(item, tossNext)
        };
        tossNext();
    };

    if(cmd == 'bardrop') {
        if(!args[1]) return;

        const userslot = parseInt(args[0]);

        bot.clickWindow(userslot + 35, 0, 0, async () => {
            bot.clickWindow(-999, 0, 0, async () => {
                bot.inventory.off;
            });
        });
    };

    if(cmd == 'mobkill') {
        var max = 1;
        if(args[0]) {
            max = parseInt(args[0]);
        };
        const en = args[1];
        for(var i = 0; i < max; i++) {
            var mobFilter = (entity) => entity.type === 'mob' && entity.mobType === en;
            if(en == 'all') {
                mobFilter = (entity) => entity.type === 'mob';
            };
            const mob = bot.nearestEntity(mobFilter);
    
            if(mob) {
                const pos = new Vec3(mob.position.x, (mob.position.y+1), mob.position.z);
                const dist = bot.entity.position.distanceTo(pos);
                if(dist < 4) { //3.7
                    bot.lookAt(pos, true, async () => {
                        await bot.setQuickBarSlot(0);
                        var to = await modules.bestsword(bot);
                        await bot.clickWindow(to.slot, 0, 0, async (err) => {
                            if(err) console.log(err);
                        });
                        await bot.clickWindow(1 + 35, 0, 0, async (err) => {
                            if(err) console.log(err);
                        });
                        bot.attack(mob, true);
                    });
                };
            };
            await sleep(200);
        };
    };

    if(cmd == 'mobfollow') {
        var mobFilter;
        if(args[0]) {
            mobFilter = (entity) => /*entity.type === 'mob' &&*/ entity.mobType === args[0];
        } else {
            mobFilter = (entity) => entity.type === 'mob';
        };
        const mob = bot.nearestEntity(mobFilter);
        if(!mob) {
            console.log(`No pude encontrar al mob ..`);
            return;
        };
        bot.pathfinder.setGoal(new GoalFollow(mob, 1), true);
    };

    if(cmd == 'sword') {
        await bot.setQuickBarSlot(0);
        
        var to = await modules.bestsword(bot);

        await bot.clickWindow(to.slot, 0, 0, async (err) => {
            if(err) console.log(err);
        });
        await bot.clickWindow(1 + 35, 0, 0, async (err) => {
            if(err) console.log(err);
        });
    };
    if(cmd == 'apple') {
        await bot.setQuickBarSlot(5);
        await bot.equip(322, 'hand');
        await bot.activateItem();
        await sleep(5000);
        await bot.deactivateItem();
    };
    if(cmd == 'armor') {
        await bot.setQuickBarSlot(8);
        await bot.equip(310, 'hand');
        await bot.activateItem();
        await bot.equip(311, 'hand');
        await bot.activateItem();
        await bot.equip(312, 'hand');
        await bot.activateItem();
        await bot.equip(313, 'hand');
        await bot.activateItem();
        bot.setQuickBarSlot(0);
    };
});

bot.on('kicked', (reason, loggedIn) => console.log(reason, loggedIn));
bot.on('error', err => console.log(err));