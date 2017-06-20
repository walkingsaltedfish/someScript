import sys
a=[3,3,3,3,3,3,3,3]
c="FGRSTLMNOPQWXYZUAGHIJKBCDEpijkfghlmnoeqrwxyzabcdstuv"
n=-1
flag=0
b=2
res=0
str1=""
for i in sys.stdin.readline().strip():
    if (i=="."):
        a[n]=1
        n+=1
    else:
        if (i=="-"):
            a[n]=0
            n+=1
        else:
                flag=1
    
    if(flag==1):
        n-=1
        res=a[n]
        while(n>0):
            n-=1
            st=a[n]
            res+=b*st        
            b=b*2
        b=2
        flag=0
        a=[3,3,3,3,3,3,3,3]
        if(res<=51):
            str1+=c[res]
        res=0
n-=1
res=a[n]
while(n>0):
    n-=1
    st=a[n]
    res+=b*st        
    b=b*2
if(res<=51):
    str1+=c[res]

print(str1)

    
        

