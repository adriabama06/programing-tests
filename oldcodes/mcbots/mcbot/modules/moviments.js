const mineflayer = require('mineflayer');
const pathfinder = require('mineflayer-pathfinder').pathfinder;
const Movements = require('mineflayer-pathfinder').Movements;
const { GoalNear, GoalFollow, GoalXZ } = require('mineflayer-pathfinder').goals;
const { Vec3 } = require('vec3');
const { Entity } = require('prismarine-entity');


/**
 * @type {{
 * ismoving: boolean
 * goal: GoalFollow | GoalNear | GoalXZ | Vec3}} this.config
 */
module.exports.config = {
    ismoving: false,
    goal: null,
};

/**
 * @param {mineflayer.Bot} bot
 */
module.exports.load = async (bot) => {
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

    bot.on('goal_reached', async (stateGoal) => {
        console.log(stateGoal)
        /**
         * @type {GoalNear | GoalXZ | GoalFollow} stateGoal
         */
        if(this.config.goal == null && this.config.ismoving == false) return;
        this.config.goal = false;
        this.config.ismoving = false;
    });
    bot.on('path_update', async (r) => {
        const path = [bot.entity.position.offset(0, 0.5, 0)];
        for (const node of r.path) {
            path.push({ x: node.x, y: node.y + 0.5, z: node.z });
        }
        bot.viewer.drawLine('path', path, 0xff00ff);
    });
};

/**
 * @param {number} x 
 * @param {number} y 
 * @param {number} z 
 */
module.exports.Goal = (x, y, z) => {
    return new GoalNear(x, y, z, 1);
};

/**
 * @param {number} x 
 * @param {number} z 
 */
module.exports.GXZ = (x, z) => {
    return new GoalXZ(x, z);
};

/**
 * @param {Entity} entity
 */
module.exports.GFollow = (entity) => {
    return new GoalFollow(entity, 1);
};


/**
 * @param {GoalNear} to
 * @param {mineflayer.Bot} bot
 */
module.exports.move = async (bot, to) => {
    this.config.goal = to;
    this.config.ismoving = true;
    bot.pathfinder.setGoal(to);
};



/**
 * @param {GoalXZ} to
 * @param {mineflayer.Bot} bot
 */
module.exports.xz = async (bot, to) => {
    this.config.goal = to;
    this.config.ismoving = true;
    bot.pathfinder.setGoal(to);
};



/**
 * @param {GoalFollow} to
 * @param {mineflayer.Bot} bot
 */
module.exports.follow = async (bot, to) => {
    this.config.goal = to;
    this.config.ismoving = true;
    bot.pathfinder.setGoal(to, true);
};



/**
 * @param {mineflayer.Bot} bot
 */
module.exports.stop = async (bot) => {
    this.config.goal = null;
    this.config.ismoving = false;
    var p = bot.entity.position;
    bot.pathfinder.setGoal(this.Goal(p.x, p.y, p.z));
};