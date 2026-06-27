async function sleep(ms) {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
};
const child_process = require('child_process');
//import * as child_process from 'child_process';

async function main() {
    const spawn_options = {
        cwd: __dirname,
        env: null,
        detached: false,
    };
    
    var child = child_process.spawn('cmd');
    
    child.stdout.on('data', async (data) => {
        console.log("stdout: <-- " + data.toString() + " -->");
    });
    
    child.stderr.on('data', async (data) => {
        console.log("stderr:" + data.toString());
    });
    
    child.on('close', async (code) => {
        console.log(code);
    });
    child.stdin.write('ping 192.168.1.201 -t'+ '\r\n');
    setTimeout( async ()=>{
        child.stdin.write("\x03");
    }, 2000);
};

main();


/*setInterval(async() => {
    process.stdout.write('node support.js\n');
}, 1000);*/