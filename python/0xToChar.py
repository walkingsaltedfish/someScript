import sys
b=0
c=0
ret=[]
get=''
a=['0x6F','0xD3','0x12','0xB2','0xD8','0x78','0xA5','0x19','0x37','0x69','0xDE','0x2F','0x68','0x04','0x87','0xF7']
for s in a:
        ret.append(int(s,16))

for i in ret:

        b=b+1
        get+=(chr(i))
get=get[::-1]


sys.stdout.write(get)
