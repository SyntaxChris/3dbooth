#!/usr/bin/env python

try:
    from Tkinter import *
except ImportError:
    from tkinter import *
    
from time import sleep
import serial

#initialize program and variables
scanGui = Tk()
scanGui.title("ScanAO")

ser = serial.Serial('/dev/ttyACM0', 9600)
table_speed = 100

#define button binding methods
def scanOff(self):
    ser.write(b'0')

def scanUp(self):
    ser.write(b'1')
    
def scanDown(self):
    ser.write(b'2')

def turnTable():
    if tablePowerBtn.config('text')[-1] == 'ON':
        tablePowerBtn.config(text='OFF')
        ser.write(b'4')
    else:
        tablePowerBtn.config(text='ON')
        ser.write(b'3')
  
        

#initialize buttons and labels
scanBtnTitle = Label(text='Scanner Controller')
tableBtnLabel = Label(text='Table Controller')

scannerUp = Button(scanGui, text="UP +")
scannerDown = Button(scanGui, text="DOWN -")
tablePowerBtn = Button(scanGui, text="ON", command=turnTable)
 

#bind buttons to methods
scannerUp.bind("<Button-1>", scanUp)
scannerUp.bind("<ButtonRelease-1>", scanOff)
scannerDown.bind("<Button-1>", scanDown)
scannerDown.bind("<ButtonRelease-1>", scanOff)


#establish button layout
scanBtnTitle.grid(row=0, column=2)
scannerUp.grid(row=1, column=2, pady=5)
scannerDown.grid(row=2,column=2, pady=5)

tableBtnLabel.grid(row=3, column=2)
tablePowerBtn.grid(row=4, column=2, pady=5)



scanGui.mainloop()
