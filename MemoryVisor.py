from tkinter import *

import socket
import json
import sys



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
    global ventana_principal
    x_cuadro=0
    y_cuadro=0
    Socket()
    global document
    cantidad=(document["UseSize"]/document["TotalSize"])*100
    i=0
    while(i<100):
        while(cantidad>0):
            cuadro = Canvas(ventana_principal , width= 18, height = 18, bg ="red")
            cantidad=cantidad-1
            cuadro.place(x=(x_cuadro),y=(y_cuadro))
            i+=1
            if x_cuadro==180:
                x_cuadro =0
                y_cuadro+=20

            else:
                x_cuadro+=20

        cuadro = Canvas(ventana_principal , width= 18, height = 18, bg ="green")
        cuadro.place(x=(x_cuadro),y=(y_cuadro))
        if x_cuadro==180:
            x_cuadro =0
            y_cuadro+=20

        else:
            x_cuadro+=20


        i+=1
    ventana_principal.after(500,draw)


ventana_principal = Tk()
ventana_principal.title("Principal")
ventana_principal.minsize(300,300)
ventana_principal.resizable(width=NO,height=NO)
botonImprimir = Button(ventana_principal, text="Verificar",relief=RAISED, command=draw, bg = "#000000", fg = "#ffffff")
botonImprimir.place(x=150,y=280)
