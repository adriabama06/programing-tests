const fs = require('fs');

fs.writeFileSync("sometext.txt", "hello from sometext.txt");

console.log('sometext.txt has ben writted');