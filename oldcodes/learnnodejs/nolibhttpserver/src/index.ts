import net from "net";
import { ParseHttpRequest } from "./util";

const server = new net.Server(/*{
    allowHalfOpen: true,
    pauseOnConnect: false
}*/);

server.on("connection", async (socket) => {
    var req = await ParseHttpRequest(socket);
    console.log(req);
    const msg = "Hello world";
    socket.write(`HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: ${msg.length}\n\n${msg}`);
    socket.end();
});

server.listen(8080, "0.0.0.0", () => console.log("Server listening on port 8080"));