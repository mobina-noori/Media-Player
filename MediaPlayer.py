import random
import keyboard 
import time

controls = ["Play/Pause","Stop","Volume Up","Volume Down","Next","Previous","Forward","Backward"]

while True:
    
    button = random.choice(controls)
    
    if button == "Play/Pause":
        keyboard.press_and_release('space')
    elif button == "Stop":
        keyboard.press_and_release('S')
    elif button == "Volume Up":
        keyboard.press_and_release('ctrl + up')
    elif button == "Volume Down":
        keyboard.press_and_release('ctrl + down')
    elif button == "Next":
        keyboard.press_and_release('N')
    elif button == "Previous":
        keyboard.press_and_release('P')
    elif button == "Forward":
        keyboard.press_and_release('shift + right')
    elif button == "Backward":
        keyboard.press_and_release('shift + left')
        
    print(button)
    time.sleep(3)

# Coding in Mac OS:

# import pyautogui
# import time
# import random

# pyautogui.hotkey('command', 'space')
# pyautogui.write('vlc')
# pyautogui.press('return')
# time.sleep(5)

# controls = ["space","s","command+up","command+down","right","left","command+right","command+left"]

# while True:
#     button = random.choice(controls)
#     pyautogui.hotkey(button)
#     print(button)
#     time.sleep(3)