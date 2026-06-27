import cv2
import socket
import imutils
import numpy as np
import time
import base64

buffer_size = 65536

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.setsockopt(socket.SOL_SOCKET,socket.SO_RCVBUF, buffer_size)
local_ip = "192.168.1.114"
port = 9999

server.bind((local_ip, port))

print(f"Ready at: {local_ip}:{port}")

video = cv2.VideoCapture("video.mp4")

fps = 0
st = 0
frames_to_count = 20
cnt = 0

while True:
    msg, client_addr = server.recvfrom(buffer_size)
    print(f"Connection from {client_addr}")
    WIDTH = 400
    while video.isOpened():
        _, frame = video.read()
        frame = imutils.resize(frame, width=WIDTH)
        encoded, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 80])
        message = base64.b64encode(buffer)
        server.sendto(message, client_addr)
        frame = cv2.putText(frame, 'FPS: '+str(fps), (10,40),cv2.FONT_HERSHEY_SIMPLEX,0.7, (0,0,255), 2)
        cv2.imshow('TRANSMITTING VIDEO', frame)
        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            server_socket.close()
            break
        if cnt == frames_to_count:
            try:
                fps = round(frames_to_count/(time.time()-st))
                st = time.time()
                cnt = 0
            except:
                pass
        cnt+=1
