async function reg() {
    var mail = document.getElementById('mail').value;
    var pass = document.getElementById('pass').value;
    var nick = document.getElementById('nick').value;

    if( !mail || !pass || !nick ) {
        return;
    }

    var data = {
        mail: mail,
        pass: pass,
        nick: nick,
    }

    socket.emit('reg', data);

    window.location.href = '/login'
}