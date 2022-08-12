/*
JAVASCRIPT DON'T SUPPORT MULTI THREAD LIKE OTHER LANG
THIS IS A TEST BUT NOT WORK BECAUSE THE ARRAY IS A COPY AND NOT A REFERENCE
*/
const { Worker } = require('worker_threads');

const fs = require('fs');
const os = require('os');

const MAX_THREADS = os.cpus().length;

function save(arr) {
    const f = fs.createWriteStream("resultJavaScript.txt");
    for(var i = 0; i < arr.length; i++) {
        f.write(`${i} ${arr[i]}\n`);
    }
    f.close();
}

function work(startIndex, endIndex, smallnumber, diferenceByPrecission, arr) {

    for(var i = startIndex; i < endIndex; i++) {
        arr[i] = smallnumber + (diferenceByPrecission * (i+1));
    }

}

async function interpolate(x, y, precission = 1) {
    var toreturn = [];
    var smallnumber = x;
    var diference = y - x;

    if(x > y) {
        smallnumber = y;
        diference = x - y;
    }

    var diferenceByPrecission = diference / (precission + 1);

    if(precission < MAX_THREADS) {
        work(0, precission, smallnumber, diferenceByPrecission, toreturn);
    } else {
        var numberToAddToIndex = precission / MAX_THREADS;

        const promises = [];

        for(var i = 0; i < MAX_THREADS; i++) {
            promises.push(
                new Promise((resolve) => {
                    const worker = new Worker("./work.js", {
                        workerData: {
                            startIndex: i * numberToAddToIndex,
                            endIndex: (i + 1) * numberToAddToIndex,
                            smallnumber,
                            diferenceByPrecission,
                            arr: toreturn
                        }
                    });

                    worker.on('exit', () => {
                        resolve();
                    })
                })
            );
        }
        await Promise.all(promises);
    } 

    return toreturn;
}

function main() {
    var result = interpolate(0, 100, 4);

    save(result);
}

main();