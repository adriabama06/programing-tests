import net from "net";
import { parse } from "path/posix";

async function sleep(time: number): Promise<number> {
    return new Promise((r) => setTimeout(() => r(time), time));
}

export type Methods = "GET" | "POST" | "PATCH" | "DELETE";

export function isMethod(s: string): s is Methods {
    return ["GET", "POST", "PATCH", "DELETE"].includes(s);
}

export interface HttpRequest {
    method: Methods,
    path: string,
    httpVersion: string,
    Host: string,
    HostName: string,
    Port: string,
    Accept: string,
    Accept_Encoding: string[],
}

export function StringParseHttpRequest(requestString: string): HttpRequest {
    var toreturn: HttpRequest = {
        method: "GET",
        path: "",
        httpVersion: "",
        Host: "",
        HostName: "",
        Port: "",
        Accept: "",
        Accept_Encoding: []
    };
    const splited: string[] = requestString.split(/\n/g);
    for(var i = 0; i < splited.length; i++) {
        var str: string = splited[i];
        if(i == 0) {
            var strSplit: string[] = str.replace("\r", "").split(/ /g);
            var method = strSplit[0];
            if(isMethod(method)) {
                toreturn.method = method;
            }
            toreturn.path = strSplit[1];
            toreturn.httpVersion = strSplit[2];
            continue;
        }
        if(str.startsWith("Host")) {
            var strSplit: string[] = str.replace(/ /g, "").replace("\r", "").split(":");
            toreturn.Host = strSplit[1]+":"+strSplit[2];
            toreturn.HostName = strSplit[1];
            toreturn.Port = strSplit[2];
            continue;
        }
        if(str.startsWith("Accept") && !str.startsWith("Accept-Encoding")) {
            if(toreturn.Accept.length >= 1) {
                continue;
            } 
            var Accept: string = str.slice("Accept: ".length).replace("\r", "");;
            while(Accept.charAt(0) == ' ') {
                if(Accept.length == 1) {
                    break;
                }
                Accept = Accept.slice(1);
            }
            toreturn.Accept = Accept;
            continue;
        }
        if(str.startsWith("Accept-Encoding")) {
            var strSplit: string[] = str.replace(/ /g, "").replace("\r", "").split(":");
            var Accept_Encoding = strSplit[1].split(/,/g);
            toreturn.Accept_Encoding = Accept_Encoding;
            continue;
        }
    }
    return toreturn;
}

export function ParseHttpRequest(socket: net.Socket): Promise<HttpRequest> {    
    return new Promise((resolve) => {
        var socketDataTmp: string = "";
        var socketData: string = "";
        socket.on("data", (data) => socketData += data.toString() + "\n");
        socket.once("data", async () => {
            while(socketData != socketDataTmp) {
                socketDataTmp = socketData;
                await sleep(500);
            }
            var parsed = StringParseHttpRequest(socketData);
            resolve(parsed);
        });
    });
}