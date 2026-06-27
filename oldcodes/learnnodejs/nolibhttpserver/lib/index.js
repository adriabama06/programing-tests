"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const net_1 = __importDefault(require("net"));
const util_1 = require("./util");
const server = new net_1.default.Server( /*{
    allowHalfOpen: true,
    pauseOnConnect: false
}*/);
server.on("connection", (socket) => __awaiter(void 0, void 0, void 0, function* () {
    var req = yield (0, util_1.ParseHttpRequest)(socket);
    console.log(req);
    const msg = "Hello world";
    socket.write(`HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: ${msg.length}\n\n${msg}`);
    socket.end();
}));
server.listen(8080, "0.0.0.0", () => console.log("Server listening on port 8080"));
//# sourceMappingURL=index.js.map