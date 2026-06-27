module.exports = class Collection {
    constructor() {
        this.map = new Map();
    }
    set(key, valure) {
        return this.map.set(key, valure);
    }
    get(key) {
        return this.map.get(key);
    }
    has(key) {
        return this.map.has(key);
    }
    keys() {
        return this.map.keys();
    }
};