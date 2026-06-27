const net = require('net');
const client = net.createConnection(3000, '192.168.1.110');
const fs = require('fs');
function random(min, max) {  
    return Math.floor(Math.random() * (max - min) + min);
};
var selected = random(0, 500);
const file = fs.createWriteStream('./torecive/temp'+selected);

client.pipe(file);

client.on('close', async () => {
    file.close();
    fs.renameSync(file.path, './torecive/file'+selected);
});