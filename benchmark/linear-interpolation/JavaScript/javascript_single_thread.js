const fs = require('fs');

function save(arr) {
    const f = fs.createWriteStream("resultJavaScript.txt");
    
    var cuantity = 1000000;

	var limitedSelection = arr.length / cuantity;

    for(var i = 0; i < cuantity; i++) {
        f.write(`${i * limitedSelection} ${arr[i * limitedSelection]}\n`);
    }
    f.close();
}

function work(startIndex, endIndex, smallnumber, diferenceByPrecission, arr) {

    for(var i = startIndex; i < endIndex; i++) {
        arr[i] = smallnumber + (diferenceByPrecission * (i+1));
    }

}

function interpolate(x, y, precission = 1) {
    var toreturn = [];
    var smallnumber = x;
    var diference = y - x;

    if(x > y) {
        smallnumber = y;
        diference = x - y;
    }

    var diferenceByPrecission = diference / (precission + 1);

    work(0, precission, smallnumber, diferenceByPrecission, toreturn);

    return toreturn;
}

function main() {
    var result = interpolate(0, 1000, 450000000);

    save(result);
}

main();