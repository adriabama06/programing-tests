const RtmpServer = require('rtmp-server');
const rtmpServer = new RtmpServer();
async function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}
rtmpServer.on('error', (err) => {
  throw err;
});
var sh;
rtmpServer.on('client', async (client) => {

    /*client.on('command', command => {
        console.log(command.cmd, command);
    });*/

    client.on('connect', async () => {
        console.log('connect', client.app);
    });
  
    client.on('play', async ({ streamName }) => {
        console.log('PLAY', streamName);
    });
  
    client.on('publish', async ({ streamName }) => {
        console.log('PUBLISH', streamName);
        await sleep(15000);
        sh = require('child_process').exec(`ffmpeg -i "rtmp://localhost:1935/" "out.mkv"`, async (err) => {
            if(err) console.log(err);
        });
    });
  
    client.on('stop', async () => {
        console.log('client disconnected');
        await sleep(15000);
        sh.emit('exit');
        sh.emit('close');
    });
});

rtmpServer.listen(1935);