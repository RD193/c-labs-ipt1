import serial
srl = serial.Serial()
srl.port = 'COM5'
srl.open()
while True:
    i = input("Speed:").encode("utf-8")
    srl.write(i)
    print(srl.readline())
