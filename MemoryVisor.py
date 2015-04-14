from tkinter import *

import socket
import json
import sys
from tkinter.filedialog import askopenfilename


global document


def Socket():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(('8.8.8.8', 0))
    HOST, PORT = s.getsockname()[0], 9500
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    global document
    s.send(b'Hello\0')
    result=s.recv(1024).decode("utf-8")
    document = json.loads(result)
    s.close()
def draw():
    #Socket()
    global document
    #cantidad=(document["UseSize"]/document["TotalSize"])*100
    cantidad =20
    i=0
    for i in range(10):
       for j in range(10):
            if cantidad>0:
                Matrix[i][j]["bg"]="red"
                cantidad=cantidad-1
            else:
                Matrix[i][j]["bg"]="green"
                
          
               
    ventana_principal.after(500,draw)
Matrix = [[0 for x in range(10)] for x in range(10)]
def MemoryScreen():
    botonMemory.config(state=DISABLED)
    ventanaDatos=Toplevel()
    
 #   Socket()
    x_cuadro=0
    y_cuadro=0
    global document
    #cantidad=(document["UseSize"]/document["TotalSize"])*100
    cantidad =10
    for x in range(10):
        for y in range(10):
            if cantidad >0:
                Matrix[x][y]=Canvas(ventanaDatos , width= 18, height = 18, bg ="red")
                Matrix[x][y].place(x=(x_cuadro),y=(y_cuadro))
                cantidad -=1
            else:
                Matrix[x][y]=Canvas(ventanaDatos , width= 18, height = 18, bg ="green")
                Matrix[x][y].place(x=(x_cuadro),y=(y_cuadro))
            if x_cuadro==180:
                x_cuadro =0
                y_cuadro+=20

            else:
                x_cuadro+=20
           
    
    ventanaDatos.after(1000,draw)
def CargarTxt():
    try:#verifica los condiciones si se puede especialmente para cargar el archivo
        file_name = askopenfilename()
        if ".txt" in file_name:
            ventanaDump=Toplevel()
            with open (file_name,'r') as f:
                for line in f:
                    w=Label(ventanaDump,text=line)
                    w.pack()
                mainloop()
                    
            
            
    except:
        print ("The file is not txt file")

ventana_principal = Tk()
ventana_principal.title("Principal")
ventana_principal.minsize(300,300)
ventana_principal.resizable(width=NO,height=NO)

botonMemory = Button(ventana_principal, text="Memory Visor",relief=RAISED, command=MemoryScreen, bg = "#000000", fg = "#ffffff")
botonMemory.place(x=50,y=100)
botonDump = Button(ventana_principal,text= "Dump Visor", relief=RAISED,command=CargarTxt,bg = "#000000", fg = "#ffffff")
botonDump.place(x=170,y=100)

