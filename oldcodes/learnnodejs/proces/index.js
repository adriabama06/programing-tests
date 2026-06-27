const fs = require('fs');

const ws = fs.createWriteStream('./log.txt');

process.stdin.pipe(ws);
// process.stdin.on('data', async (data) => {
//    ws.write(data);
// });

process.on('SIGTERM', async () => {
    ws.close();
});