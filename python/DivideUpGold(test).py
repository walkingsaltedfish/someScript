
a=raw_input()
m=1
while(m<=int(a)):
    b=raw_input()
    c=[]
    c=raw_input()
    c=c.split()
    n=int(b)/2
    sc1=0;sc2=0
    while(n>0):
        n+=-1
        sc1+=long(c[2*n+1])
        sc2+=long(c[2*n])
        

    print('Case #'+str(m)+":"),
    print(sc1),
    print(sc2)
    m+=1

