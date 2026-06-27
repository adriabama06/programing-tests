const fs = require('fs');
const child_process= require('child_process');

const rs = fs.createReadStream('./read.txt');

const term = child_process.exec('node .');

rs.pipe(term.stdin);