import serial
srl = serial.Serial()
srl.port = 'COM3'
srl.open()
h = []
t = []
u = 20
while True:
    h.append(float(srl.readline()))
    t.append(float(srl.readline()))
    if u == 0: break
    print(h)
    print(t)
    u-=1
print(h)
print(t)
