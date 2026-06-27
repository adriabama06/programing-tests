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
module.exports.toolvalor = (name) => {
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
 * @param {string} name
 * @returns {number}
 */
module.exports.armorvalor = (name) => {
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
 * @param {string} name
 * @param {'heal' | 'food'} [priority]
 * @returns {number}
 */
module.exports.bestfood = (name, priority = 'food') => {
    if(priority === 'food') {
        if(name.startsWith('cooked_beef')) {
            return 9;
        };
        if(name.startsWith('cooked_porkchop')) {
            return 8;
        };
        if(name.startsWith('cooked_mutton')) {
            return 7;
        };
        if(name.startsWith('bread')) {
            return 6;
        };
        if(name.startsWith('cooked_chicken')) {
            return 5;
        };
        if(name.startsWith('apple')) {
            return 4;
        };
        if(name.startsWith('carrot')) {
            return 3;
        };
        if(name.startsWith('golden_carrot')) {
            return 2;
        };
        if(name.startsWith('golden_apple')) {
            return 1;
        };

    } else if(priority === 'heal') {// <---------------------------HEAL--------------------------->
        if(name.startsWith('golden_apple')) {
            return 9;
        };
        if(name.startsWith('golden_carrot')) {
            return 8;
        };
        if(name.startsWith('bread')) {
            return 7;
        };
        if(name.startsWith('apple')) {
            return 6;
        };
        if(name.startsWith('cooked_beef')) {
            return 5;
        };
        if(name.startsWith('cooked_porkchop')) {
            return 4;
        };
        if(name.startsWith('cooked_mutton')) {
            return 3;
        };
        if(name.startsWith('cooked_chicken')) {
            return 2;
        };
        if(name.startsWith('carrot')) {
            return 1;
        };
    };
};