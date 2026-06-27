from socket import socket
from threading import Thread
from zlib import compress
import struct

class Server:
    def __init__(self, host = "0.0.0.0", port = 5050):
        self.host = host
        self.port = port
        self.is_running = False

        self.server = socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_thread = False


    def listen(self):
        if self.is_running:
            print("Server is already running")
            return
        self.is_running = True
        self.server_thread = Thread(target = self.server_listen)
        #while True:
        #    client, addr = self.server.accept()
        #    Thread(target = self.listenToClient, args = (client, addr)).start()


    def server_listen(self):
        self.server.listen() # 5 ?
        while self.is_running:
            conn, addr = self.server.accept()
            thr = Thread(target = self.clientThread, args = (conn, addr))
            thr.start()


    def clientThread(self, conn, addr):
        payload_size = struct.calcsize('>L')
        data = b""

        while self.is_running:
            break_loop = False

            while len(data) < payload_size:
                recived = conn.recv(4096)
                if recived == b"":
                    conn.close()
                    break_loop = True
                    break
                data += recived
            
            packed_msg_size = data[:payload_size]
            data = data[payload_size:]

            msg_size = struct.unpack(">L", packed_msg_size)[0]

            while len(data) < msg_size:
                data += conn.recv(4096)

def main():
    server = Server()
    server.listen()

if __name__ == '__main__':
    main()