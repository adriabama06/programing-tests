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
Object.defineProperty(exports, "__esModule", { value: true });
exports.ParseHttpRequest = exports.StringParseHttpRequest = exports.isMethod = void 0;
function sleep(time) {
    return __awaiter(this, void 0, void 0, function* () {
        return new Promise((r) => setTimeout(() => r(time), time));
    });
}
function isMethod(s) {
    return ["GET", "POST", "PATCH", "DELETE"].includes(s);
}
exports.isMethod = isMethod;
function StringParseHttpRequest(requestString) {
    var toreturn = {
        method: "GET",
        path: "",
        httpVersion: "",
        Host: "",
        HostName: "",
        Port: "",
        Accept: "",
        Accept_Encoding: []
    };
    const splited = requestString.split(/\n/g);
    for (var i = 0; i < splited.length; i++) {
        var str = splited[i];
        if (i == 0) {
            var strSplit = str.replace("\r", "").split(/ /g);
            var method = strSplit[0];
            if (isMethod(method)) {
                toreturn.method = method;
            }
            toreturn.path = strSplit[1];
            toreturn.httpVersion = strSplit[2];
            continue;
        }
        if (str.startsWith("Host")) {
            var strSplit = str.replace(/ /g, "").replace("\r", "").split(":");
            toreturn.Host = strSplit[1] + ":" + strSplit[2];
            toreturn.HostName = strSplit[1];
            toreturn.Port = strSplit[2];
            continue;
        }
        if (str.startsWith("Accept") && !str.startsWith("Accept-Encoding")) {
            if (toreturn.Accept.length >= 1) {
                continue;
            }
            var Accept = str.slice("Accept: ".length).replace("\r", "");
            ;
            while (Accept.charAt(0) == ' ') {
                if (Accept.length == 1) {
                    break;
                }
                Accept = Accept.slice(1);
            }
            toreturn.Accept = Accept;
            continue;
        }
        if (str.startsWith("Accept-Encoding")) {
            var strSplit = str.replace(/ /g, "").replace("\r", "").split(":");
            var Accept_Encoding = strSplit[1].split(/,/g);
            toreturn.Accept_Encoding = Accept_Encoding;
            continue;
        }
    }
    return toreturn;
}
exports.StringParseHttpRequest = StringParseHttpRequest;
function ParseHttpRequest(socket) {
    return new Promise((resolve) => {
        var socketDataTmp = "";
        var socketData = "";
        socket.on("data", (data) => socketData += data.toString() + "\n");
        socket.once("data", () => __awaiter(this, void 0, void 0, function* () {
            while (socketData != socketDataTmp) {
                socketDataTmp = socketData;
                yield sleep(500);
            }
            var parsed = StringParseHttpRequest(socketData);
            resolve(parsed);
        }));
    });
}
exports.ParseHttpRequest = ParseHttpRequest;
//# sourceMappingURL=util.js.map