const fs = require('fs');

const file = fs.createReadStream("sometext.txt");

file.pipe(process.stdout);

file.on('close', () => {
    process.stdout.write("\n");
});