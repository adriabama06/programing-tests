from time import sleep
import pyautogui

# RGB values for the colors we want to recognize
color = (140, 185, 101)
range_size = int(50 / 2)
color_with_range = (range(color[0]-range_size, color[0]+range_size), range(color[1]-range_size, color[1]+range_size), range(color[2]-range_size, color[2]+range_size))

x_line_start = 1353
x_line_end = 2527
y_line = 646

isKeyDown = False

sleep(5)

# Create screen shot every 1 second and check if the color is present
while True:
    if not isKeyDown:
        pyautogui.mouseDown(button='left')
        isKeyDown = True

    image = pyautogui.screenshot()

    for i in range(x_line_start, x_line_end):
        pixel = image.getpixel((i, y_line))
        
        if pixel[0] in color_with_range[0] and pixel[1] in color_with_range[1] and pixel[2] in color_with_range[2]:
            print("Color is present")
            pyautogui.mouseUp(button='left')
            isKeyDown = False
            sleep(3)
            break
        else:
            print("Color is not present")

    sleep(0.01)