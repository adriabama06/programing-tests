import pyautogui
from time import sleep

pyautogui.FAILSAFE = False

data = ""

text = open('towrite.txt', 'r', encoding='utf8')

for line in text:
    data += line

print(data)


sleep(5)
pyautogui.write(data, interval=0.1)