const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Algo: ', async (answer) => {
    console.log(`Pues ok: ${answer}`);
});

rl.on('line', async (line) => {
    console.log(`Received: ${line}`);
});