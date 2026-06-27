module.exports = async function(mail, pass, nick, data) {
    var d = {
        mail: `${mail}`,
        pass: `${pass}`,
        nick: `${nick}`,
    }
    data.set(`${mail}`, d);
}