/**
* @returns {Promise<number>}
* @param {number} ms 
*/
module.exports.sleep = async (ms) => {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
}