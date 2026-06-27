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
    child.stdin.setDefaultEncoding('utf-8');
    child.stdout.on('data', async (data) => {
        console.log(data.toString());
        //console.log("stdout: <-- " + data.toString() + " -->");
    });
    
    child.stderr.on('data', async (data) => {
        console.log("stderr:" + data.toString());
    });
    
    child.on('close', async (code) => {
        console.log(code);
    });
    child.stdin.write('echo hola'+ '\r\n');
    await sleep(5000);
    child.stdin.write('echo hola'+ '\r\n');
    await sleep(5000);
    child.stdin.write('node rl.js'+ '\r\n');
    await sleep(5000);
    child.stdin.write("\u0003"+ '\r\n');
    child.stdin.end();
};

main();