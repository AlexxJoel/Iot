import serial, time
board = serial.Serial('COM3',9600)

while 1==1: 

    # leemos hasta que encontarmos el final de linea
    a = board.readline()
    # Mostramos el valor leido y eliminamos el salto de linea del final
    print ( a)

board.close