async function send(text) {
    if(!text) return;
    var data = {
        by: location.search.slice(5).replace('%20', ' '),
        text: text
    };

    socket.emit('client/msg', data);
    add(data);
    document.getElementById('text').value = '';
}
async function start() {
    var info = location.search.slice(5).replace('%20', ' ');
    socket.emit('client/start', info);
}

async function add(data) {
    const by = data.by;
    const text = data.text;
    console.log(by + ": " + text);
    const messageElement = document.createElement('li');
    messageElement.innerHTML = `<div class="msgbox"><p class="name" >${by}:</p><p class="msg">${text}</p></div>`;
    //messageElement.innerText = by + ": " + text;
    document.getElementById('chatarea').append(messageElement);
}