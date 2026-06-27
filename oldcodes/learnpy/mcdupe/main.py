import asyncio
import pyautogui

from time import sleep

ping = 0

obj_x = 497
obj_y = 598


sleep(5)

pyautogui.mouseDown(button='left')

sleep(3)

pyautogui.mouseUp(button='left')

pyautogui.hotkey('alt', 'tab') 

pyautogui.keyDown('shiftleft')

pyautogui.click(x=obj_x, y=obj_y, )

#sleep(ping / 1000)


pyautogui.keyUp('shiftleft')