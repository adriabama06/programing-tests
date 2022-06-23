const fs = require('fs');

const file = fs.createWriteStream("sometext.txt");

file.write("streaming to sometext.txt");

file.close();