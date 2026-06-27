/// <reference types="node" />
import net from "net";
export declare type Methods = "GET" | "POST" | "PATCH" | "DELETE";
export declare function isMethod(s: string): s is Methods;
export interface HttpRequest {
    method: Methods;
    path: string;
    httpVersion: string;
    Host: string;
    HostName: string;
    Port: string;
    Accept: string;
    Accept_Encoding: string[];
}
export declare function StringParseHttpRequest(requestString: string): HttpRequest;
export declare function ParseHttpRequest(socket: net.Socket): Promise<HttpRequest>;
//# sourceMappingURL=util.d.ts.map