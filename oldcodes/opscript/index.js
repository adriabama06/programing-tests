const [,, ... args] = process.argv
if(!args[0]) return console.log("Invalid args please use -> node 'index.js help' <- for show the help");
if(args[0] == "help") {
//    console.clear()
console.table([
{ commandos: 'help',descripcion: 'Show help'},
{ commandos: 'http',descripcion: 'Use http server'},
{ commandos: 'clear',descripcion: 'Clear the console'}]);
};
if(args[0] == "clear") {
    console.clear()
    console.log(" ")
};

if(args[0] == "http") {
    if(!args[2]) return console.log("Use host, example -> node index.js http 80 0.0.0.0")
 var server = require("./pack/http/http.js");
 server.starthttp();
}

if(args[0] == "dir") {
    var startdirdir = require("./pack/commands/dir.js");
    startdirdir.startdir();
}

//console.log(args)