const fs = require('fs');

/*const file = '{"test": "this is the content","hi": "hello"}';
const tojson = JSON.parse(file);

console.log('\n');
console.log(file);
console.log('\n\n');
console.log(tojson);
console.log('\n');*/

const file = fs.readFileSync('./owo.json').toString();

const tojson = JSON.parse(file);

tojson.aa = "ponte a hacer deberes >:V";

fs.writeFileSync('./owo.json', JSON.stringify(tojson))