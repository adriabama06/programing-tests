const { workerData } = require('worker_threads');

for(var i = workerData.startIndex; i < workerData.endIndex; i++) {
    workerData.arr[i] = workerData.smallnumber + (workerData.diferenceByPrecission * (i+1));
}

process.exit();