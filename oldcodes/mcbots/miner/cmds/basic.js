const mineflayer = require('mineflayer');
const { GoalNear } = require('mineflayer-pathfinder').goals;

module.exports = {
    cmd: "basic",
    /**
     * @param {mineflayer.Bot} bot 
     * @param {string} username 
     * @param {string} message 
     */
    async run(bot, username, message, args) {
        function mineatfront() {
            var block = bot.blockAtCursor();
            var d = bot.dig(block, true);
            d.finally(() => {
                var blockdos = bot.blockAtCursor();
                var dos = bot.dig(blockdos, true);
                dos.finally(() => {
                    bot.pathfinder.setGoal(new GoalNear(blockdos.position.x, blockdos.position.y-1, blockdos.position.z, 1), true);
                    bot.on('goal_reached', async (stateGoal) => {
                        mineatfront();
                    });
                });
            });
        }
        mineatfront();
    },
}