import sys
get=''
giv=''
ret=[]
a='hello'
e=0
c=0
for s in a:
        b=ord(s)*ord(s)
        b=(b*c+c)%66
        e=b+33
        get+=(chr(e))
        c=c+1
d=['0x40','0x79','0x70','0x70','0x61','0x48']
for j in d:
        ret.append(int(j,16))

for i in ret:

        giv+=(chr(i))
giv=giv[::-1]
giv=giv+get


sys.stdout.write(giv)
