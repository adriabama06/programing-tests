const mineflayer = require('mineflayer')
const pathfinder = require('mineflayer-pathfinder').pathfinder
const Movements = require('mineflayer-pathfinder').Movements
const { GoalNear, GoalFollow } = require('mineflayer-pathfinder').goals
var blockFinderPlugin = require('mineflayer-blockfinder')(mineflayer);

async function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}

const bot = mineflayer.createBot({
  host: 'WolfSurvi.aternos.me', // optional
  //port: 25565,       // optional
  username: 'afkonline', // email and password are required only for
  //password: '12345678',           online-mode=true servers
  version: "1.15.2"                 // false corresponds to auto version detection (that's the default), put for example "1.8.8" if you need a specific version
})
bot.loadPlugin(blockFinderPlugin);
bot.loadPlugin(pathfinder)
const mcData = require('minecraft-data')(bot.version)

const defaultMove = new Movements(bot, mcData)
bot.pathfinder.setMovements(defaultMove)

bot.on('spawn', async function (username, message) {
  await sleep(5000);
  bot.chat('/register adriabama06')
  //bot.chat('/login adriabama06')
});

var atacando = false;

setInterval(async function() {
  if(atacando == true) {
    //const playerCI = bot.players['TheDudeFromCI']
    //const playerFilter = (entity) => entity.type === 'player' mob
    //const mobFilter = e => e.type === 'player' && e.type === 'mob';// && e.mobType === 'Zombie'
    const mobFilter = (entity) => entity.type === 'player' || entity.type === 'mob'
    const mob = bot.nearestEntity(mobFilter)

    if (!mob) return;

    const pos = mob.position;
    const dist = bot.entity.position.distanceTo(pos);
    if(dist > 3.7) { //3.7
      return
    }
    bot.lookAt(pos, true, async () => {
      bot.attack(mob, true);
    });
  }
}, 100)
setInterval(async function() {
  if(bot.health < 12 || bot.food < 6) {
  var cambiaratacando = false;
  if(atacando == true) {
    cambiaratacando = true
    atacando = false
  }
  if (bot.inventory.items().some(item => item.name == 'golden_apple')) { //CHEQUEA SI HAY ESE ITEM EN EL INVENTARIO :D
    await bot.setQuickBarSlot(5);
    await bot.equip(322, 'hand');
    await bot.activateItem();
    await sleep(3100);
    bot.setQuickBarSlot(0);
    if(cambiaratacando == true) {
      cambiaratacando = false
      atacando = true
    }
  } else {
    return
  }
} else {
  return
}
}, 5000)
/*    function nearestEntity(type) {
      var id, entity, dist;
      var best = null;
      var bestDistance = null;
      for(id in bot.entities) {
        entity = bot.entities[id];
        if(type && entity.type !== type) continue;
        if(entity === bot.entity) continue;
        dist = bot.entity.position.distanceTo(entity.position);
        if(!best || dist < bestDistance) {
          best = entity;
          bestDistance = dist;
        }
      }
      return best;
    }
  var entity = nearestEntity();
  if(entity) {
    bot.attack(entity, true);
  } else {
    bot.chat('no nearby entities');
  }*/

//events
/*setInterval(function() {
if(bot.food < 6) {
  bot.equip(364, 'hand')
}
}, 10000);*/

bot.on('chat', async function (username, message) {
  console.log(`${username}: ${message}`)
    if (message.includes('!come')) {
      const tempargs = message.split('!come ');//.toString(); para los args o maps tipo ['arg1', 'arg2']

      const argsspl= tempargs[1];
      var args;
      if(!tempargs[1]) {

      } else {
        args = argsspl.split(' ');
      }
      var playerCI;
      if(!args) {
        playerCI = bot.players[`${username}`].entity
      } else {
        playerCI = bot.players[`${args[0]}`].entity
      }

      if(!playerCI || playerCI.entity) {
        bot.chat(`No pude encontrar al jugador ..`) ///tell ${username} 
      }

      var p = playerCI.position

      const goal = new GoalNear(p.x, p.y, p.z, 1)

      bot.pathfinder.setGoal(goal)
    }
    if(message.startsWith('!goto')) {


      const args = message.split('!goto ');//.toString(); para los args o maps tipo ['arg1', 'arg2']

      const argsspl= args[1];
      const cords = argsspl.split(' ');
      
      bot.pathfinder.setGoal(new GoalNear(cords[0], cords[1], cords[2]))
      bot.chat(`/tell ${username} Voy para ${cords[0]}, ${cords[1]}, ${cords[2]}`)
    }

    if(message.startsWith('!find')) {
      bot.findBlock({
        point: bot.entity.position,
        matching: 56,
        maxDistance: 256,
        count: 1,
      }, function(err, blocks) {
        if (err) {
          bot.chat(`/tell ${username} Hubo un error al buscar ${cords[0]}: ` + err);
          return;
        }
        if (blocks.length) {
          bot.chat(`/tell ${username} encontre diamantes en ${blocks[0].position}`);
          return;
        } else {
          bot.chat(`/tell ${username} no pude encontrar el bloque ${args[1]}`);
          return;
        }
      });
    }
    if(message.startsWith('!gofind')) {
      const args = message.split('!gofind ');//.toString(); para los args o maps tipo ['arg1', 'arg2']

      const argsspl= args[1];
      const cords = argsspl.split(' ');

      const tempcord = Number.parseInt(cords[0]);

      if(!cords[0] || isNaN(tempcord)) {
        bot.chat(`/tell ${username} debe de poner el ID del bloque`);
        return
      }
      bot.findBlock({
        point: bot.entity.position,
        matching: Number.parseInt(cords[0]),
        maxDistance: 256,
        count: 1,
      }, function(err, blocks) {
        if (err) {
          bot.chat(`/tell ${username} Hubo un error al buscar ${cords[0]}: ` + err);
          return;
        }
        if (blocks.length) {
          bot.chat(`/tell ${username} encontre diamantes en ${blocks[0].position}`);
          const x = blocks[0].position.x;
          const y = blocks[0].position.y;
          const z = blocks[0].position.z;
          bot.pathfinder.setGoal(new GoalNear(x, y, z))
        } else {
          bot.chat(`/tell ${username} no pude encontrar el bloque ${args[1]}`);
          return;
        }
      });
    }

    if(message.startsWith('!kill')) {

      if(atacando == true) {
        atacando = false;
        return
      } else {
        atacando = true;
        return
      }
    }

    if(message.startsWith('!follow')) {
      const tempargs = message.split('!follow ');//.toString(); para los args o maps tipo ['arg1', 'arg2']

      const argsspl= tempargs[1];
      var args;
      if(!tempargs[1]) {

      } else {
        args = argsspl.split(' ');
      }
      var playerCI;
      if(!args) {
        playerCI = bot.players[`${username}`]
      } else {
        playerCI = bot.players[`${args[0]}`]
      }

      if(!playerCI || playerCI.entity) {
        bot.chat(`/tell ${username} No pude encontrar al jugador ..`)
      }

      const goal = new GoalFollow(playerCI.entity, 1)

      bot.pathfinder.setGoal(goal, true)
    }

    if (message.startsWith('!say')) {


      const args = message.split('!say ');

      bot.chat(args[1])

      return;
    }

    //if(message.startsWith('!inv')) {
    //  bot.chat(`${bot.inventory.items()}`);
    //}

    if(message.startsWith('!bardrop')) {
      const args = message.split('!bardrop ');//.toString(); para los args o maps tipo ['arg1', 'arg2']

      const argsspl= args[1];
      const cords = argsspl.split(' ');

      if(!cords) return;

      const userslot = Number.parseInt(cords[0]);

      bot.clickWindow(userslot + 35, 0, 0, () => {
        bot.clickWindow(-999, 0, 0, () => {
          bot.inventory.off;
        });
      });
    }

    if(message.startsWith('!barmove')) {
      const args = message.split('!barmove ');//.toString(); para los args o maps tipo ['arg1', 'arg2']

      const argsspl= args[1];
      const cords = argsspl.split(' ');

      if(!cords) return;

      const userslot = Number.parseInt(cords[0]);
      const userto = Number.parseInt(cords[1]);

      bot.clickWindow(userslot + 35, 0, 0, () => {
        bot.clickWindow(userto + 35, 0, 0, () => {
          bot.inventory.off;
        });
      });
    }

    if(message.startsWith('!slot')) {
      const firstsplit = message.split('!slot ');//.toString(); para los args o maps tipo ['arg1', 'arg2']
      const argsspl= firstsplit[1];
      const args = argsspl.split(' ');

      var calculate = Number.parseInt(args[0]);
      var slot = calculate - 1;

      if(isNaN(slot)) {
        bot.chat(`/tell ${username} Debe de poner un numero`);
        return
      } else if(slot > 8 || slot < 0) {
        bot.chat(`/tell ${username} Debe de poner un numero que vaya del 1 al 9`);
        return
      }
      bot.setQuickBarSlot(slot)
    }
    if(message.startsWith('!dropall')) {
      function tossNext () {
        if (bot.inventory.items().length === 0) return
        const item = bot.inventory.items()[0]
        bot.tossStack(item, tossNext)
      }
      tossNext();
    }

    if(message.startsWith('!inv')) {
      if (bot.inventory.items().length === 0) return bot.chat('No tengo ningun item');
      const item = bot.inventory.items()[0]
      bot.chat(`${item}`);
    }
    if(message.startsWith('!use')) {
      bot.activateItem();
    }
    if(message.startsWith('!unuse')) {
      bot.deactivateItem();
    }
    if(message.startsWith('!heal')) {
      const firstsplit = message.split('!heal ');//.toString(); para los args o maps tipo ['arg1', 'arg2']
      const argsspl= firstsplit[1];
      const args = argsspl.split(' ');

      var calculate = Number.parseInt(args[0]);
      if(isNaN(calculate)) {
        bot.chat(`/tell ${username} Debe de poner el id del item`);
        return
      }
      await bot.setQuickBarSlot(5);
      await bot.equip(calculate, 'hand');
      await bot.activateItem();
      await sleep(3100);
      bot.setQuickBarSlot(0);
    }
    if(message.startsWith('!gold')) {
      if (bot.inventory.items().some(item => item.name == 'golden_apple')) { //CHEQUEA SI HAY ESE ITEM EN EL INVENTARIO :D
        await bot.setQuickBarSlot(5);
        await bot.equip(322, 'hand');
        await bot.activateItem();
        await sleep(3100);
        bot.setQuickBarSlot(0);
      } else {
        return
      }
    }
    if(message.startsWith('!armor')) {
      await bot.setQuickBarSlot(5);
      await bot.equip(310, 'hand');
      await bot.activateItem();
      await sleep(100);
      await bot.setQuickBarSlot(5);
      await bot.equip(311, 'hand');
      await bot.activateItem();
      await sleep(100);
      await bot.setQuickBarSlot(5);
      await bot.equip(312, 'hand');
      await bot.activateItem();
      await sleep(100);
      await bot.setQuickBarSlot(5);
      await bot.equip(313, 'hand');
      await bot.activateItem();
      await sleep(100);
      bot.setQuickBarSlot(0);
    }
})


// Log errors and kick reasons:
bot.on('kicked', (reason, loggedIn) => console.log(reason, loggedIn))
bot.on('error', err => console.log(err))