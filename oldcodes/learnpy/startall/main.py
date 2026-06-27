import pyautogui
from time import sleep

pyautogui.FAILSAFE = False

p = open('p.txt', 'r', encoding='utf8')

sp = str(p.read(int(p.__sizeof__())))

def home():
    pyautogui.click(x=21, y=1421, button='left')
    return

# left - right

home()
sleep(2.5)
pyautogui.write("cmd", interval=0.01)
sleep(2.5)
pyautogui.press('enter')
sleep(2.5)
pyautogui.write("C:\\Windows\\System32\\runas.exe /user:janba cmd", interval=0.01)
pyautogui.press('enter')
sleep(1)
pyautogui.write(sp, interval=0.01)
pyautogui.press('enter')
sleep(2.5)
pyautogui.write("\"D:\\Program Files\\MSI Afterburner\\MSIAfterburner.exe\" && \"C:\\Program Files (x86)\\Intel\\Intel(R) Extreme Tuning Utility\\Client\\XtuUiLauncher.exe\" && \"C:\\Program Files (x86)\\NoteBook FanControl\\NoteBookFanControl.exe\"", interval=0.01)
pyautogui.press('enter')
pyautogui.write("exit", interval=0.01)
pyautogui.press('enter')
