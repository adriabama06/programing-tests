const mineflayer = require('mineflayer');
const pathfinder = require('mineflayer-pathfinder').pathfinder;
const Movements = require('mineflayer-pathfinder').Movements;
const { GoalNear, GoalFollow, GoalXZ , GoalBlock, GoalY } = require('mineflayer-pathfinder').goals;
const { Vec3 } = require('vec3');
const { Entity } = require('prismarine-entity');

/**
 * @type {{
 * goal: null | GoalNear | GoalFollow | GoalXZ | GoalBlock | GoalY,
 * goals: Array<GoalNear | GoalFollow | GoalXZ | GoalBlock | GoalY>,
 * ismoving: boolean,
 * }}
 */
var config = {
    goal: null,
    goals: [],
    ismoving: false,
}
module.exports.config = config;

/**
 * 
 * @param {mineflayer.Bot} bot
 */
module.exports.load = function (bot) {
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

    bot.on('goal_reached', function (stateGoal) {
        if(config.goals.length === 0) {
            config.goal = null;
            config.goals = [];
            config.ismoving = false;
            return;
        }
        config.goal = config.goals.shift();
        if(config.goal === undefined) {
            config.goal = null;
            config.goals = [];
            config.ismoving = false;
            return;
        }
        bot.pathfinder.setGoal(config.goal);
    });
}

module.exports.stop = function () {
    config.goal = null;
    config.goals = [];
    config.ismoving = false;
    return;
}