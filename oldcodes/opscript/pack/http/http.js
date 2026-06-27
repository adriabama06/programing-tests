function starthttp() {
const [,, ... args] = process.argv
const http = require('http')
const fs = require('fs')
const hostname = args[2];
const port = args[1];

const server = http.createServer((req, res) => {
  res.writeHead(200, {'Content-Type': 'text/html'})
  fs.readFile('./pack/http/pages/start/index.html', (error, data) => {
    if(error){
      res.writeHead(404)
      res.write("Archivo no encontrado")
    } else {
      res.write(data)
    }
    res.end()
  })
});

server.listen(port, hostname, () => {
  console.log(`Server is runing on http://${hostname}:${port}/ \n\nUse CTRL + C for stop the server\n`);
});
}
exports.starthttp = starthttp;