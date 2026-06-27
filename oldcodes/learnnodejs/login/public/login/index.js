async function log() {
    var mail = document.getElementById('mail').value;
    var pass = document.getElementById('pass').value;

    if( !mail || !pass ) {
        return;
    }

    async function randomInt(low, high) {
        return Math.floor(Math.random() * (high - low) + low)
    }

    var data = {
        mail: mail,
        pass: pass,
        num: `${await randomInt(0, 50000)}`,
    }

    socket.emit('login', data);
}

async function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}

async function logc(data) {
    await sleep(50);
    window.location.href = '/?id=' + data;
}