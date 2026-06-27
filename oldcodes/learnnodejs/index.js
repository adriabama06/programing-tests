const fs = require('fs');
const argv = process.argv.splice(2);
if(!argv[0]) {
    console.log(`
    Use: node index.js -h`);
};
if(argv[0] == '-h' || argv[0] == '-help' || argv[0] == '--help') {
    var cmd = [];
    var dirs = fs.readdirSync('./');
    console.log(`
    Usar: node index.js -r (nombre)

    Disponibles:
    
    - ${cmd}`);
};