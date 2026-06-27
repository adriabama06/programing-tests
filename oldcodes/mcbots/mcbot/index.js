const mineflayer = require('mineflayer');
const { mineflayer: mineflayerViewer } = require('prismarine-viewer')
const { food, inv, util, moviments } = require('./modules/index.js');
const { Goal, GXZ, GFollow } = require('./modules/moviments.js');



const bot = mineflayer.createBot({
    host: 'mrpokemon2yt.ddns.net', // optional
    port: 80,       // optional
    username: 'afkonline', // email and password are required only for
    //password: '12345678',          // online-mode=true servers
    version: 1.8,                 // false corresponds to auto version detection (that's the default), put for example "1.8.8" if you need a specific version
    //auth: 'mojang'      // optional; by default uses mojang, if using a microsoft account, set to 'microsoft'
});

bot.loadPlugin(moviments.load);

food.foodevent(bot);

const prefix = "!";

bot.on('chat', async (username, message) => {
    console.log(`${username}: ${message}`);

    const args = message.slice(prefix.length).trim().split(/ +/g);
    const command = args.shift().toLowerCase();
    
    
    if(command == 'slot') {
        if(!args[0]) {
            return;
        };
        var calculate = parseInt(args[0]);
        var slot = calculate - 1;
        if(isNaN(slot)) {
          console.log(`Debe de poner un numero`);
          return;
        };
        if(slot > 8 || slot < 0) {
          console.log(`Debe de poner un numero que vaya del 1 al 9`);
          return;
        };
        bot.setQuickBarSlot(slot);
    };

    if(command == 'sword') {
        bot.setQuickBarSlot(0);
        const item = await inv.bestininv(bot, 'sword');

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

    if(command == 'drop') {
        var todrop = ((bot.quickBarSlot + 35)+1);
        if(args[0] == 'inv') {
            todrop = parseInt(args[1]);
        };
        if(args[0] == 'bar') {
            todrop = (parseInt(args[1]) + 35);
        };
        if(args[0] == 'all') {
            function tossNext () {
                if (bot.inventory.items().length === 0) return
                const item = bot.inventory.items()[0]
                bot.tossStack(item, tossNext)
            };
            return tossNext();
        };
        await bot.clickWindow(todrop, 0, 0, async (err) => {
            if(err) console.log(err);
        });
        await bot.clickWindow(-999, 0, 0, async (err) => {
            if(err) console.log(err);
        });
    };

    if(command == 'move') {
        if(!args[0]) return;
        var fist = 0;
        var second = 0;
        if(args[0] == 'inv') {
            fist = parseInt(args[1]);
            second = parseInt(args[2]);
        };
        if(args[0] == 'bar') {
            fist = (parseInt(args[1]) + 35);
            second = (parseInt(args[2]) + 35);
        };
        await bot.clickWindow(fist, 0, 0, async (err) => {
            if(err) console.log(err);
        });
        await bot.clickWindow(second, 0, 0, async (err) => {
            if(err) console.log(err);
        });
        await bot.clickWindow(fist, 0, 0, async (err) => {
            if(err) console.log(err);
        });
    };

    if(command == 'come') {
        var p = bot.players[username].entity.position;

        if(args[0] && bot.players[args[0]]) {
            p = bot.players[args[0]].entity.position;
        };

        moviments.move(bot, Goal(p.x, p.y, p.z));
    };

    if(command == 'xz') {
        var p = bot.players[username].entity.position;

        if(args[0] && args[1]) {
            var x = parseInt(args[0]);
            var z = parseInt(args[1]);
            if(isNaN(x) || isNaN(z)) {
                return;
            };
            p = {
                x: x,
                z: z,
            };
        } else {
            return;
        };
        moviments.xz(bot, GXZ(p.x, p.z));
    };

    if(command == 'follow') {
        var p = bot.players[username].entity;

        if(args[0] && bot.players[args[0]]) {
            p = bot.players[args[0]].entity;
        };

        moviments.follow(bot, GFollow(p));
    };

    if(command == 'stop') {
        moviments.stop(bot);
    };
});

bot.on('kicked', async (reason, loggedIn) => {
    console.log(reason, loggedIn)
});
bot.on('error', async (err) => {
    console.log(err)
});

bot.once('spawn', async () => {
    mineflayerViewer(bot, { port: 3007, firstPerson: false }) // port is the minecraft server port, if first person is false, you get a bird's-eye view

    bot.viewer.on('blockClicked', (block, face, button) => {
        if (button !== 2) return // only right click
    
        const p = block.position.offset(0, 1, 0);
    
        const { GoalBlock } = require('mineflayer-pathfinder').goals;
        bot.pathfinder.setGoal(new GoalBlock(p.x, p.y, p.z));
    });
});


process.stdin.on('data', data => bot.chat(data.toString()));