var config = {
    quality: null,
    maxq: null,
    volume: 1,
    paused: true,
    fullscreen: false,
}

document.getElementById('video').onpause = function (ev) {
    config.paused = true;
}
document.getElementById('video').onplay = function (ev) {
    config.paused = false;
}
document.getElementById('video').onclick = async function (ev) {
    if(config.paused) {
        this.play();
    } else {
        this.pause();
    }
}
document.getElementById('play').onclick = async function (ev) {
    if(config.paused) {
        document.getElementById('video').play();
    } else {
        document.getElementById('video').pause();
    }
}
document.getElementById('mute').onclick = async function (ev) {
    if(config.volume === 0) {
        document.getElementById('video').volume = 1;
        config.volume = 1;
    } else {
        document.getElementById('video').volume = 0;
        config.volume = 0;
    }
}
document.getElementById('volume').onchange = async function (ev) {
    document.getElementById('video').volume = parseInt(this.value)/100;
    config.volume = parseInt(this.value)/100;
}
document.getElementById('fullscreen').onclick = async function (ev) {
    if(config.fullscreen) {
        document.getElementById('video').volume = 1;
        config.volume = 1;
    } else {
        document.getElementById('video').volume = 0;
        config.volume = 0;
    }
}