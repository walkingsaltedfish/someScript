while(1):
    a=raw_input()   
    b=raw_input()
    c=raw_input()
    e=len(b)
    if((b in a)&(c in a)):
            bl=a.find(b)
            if(bl+e<=len(a)-1):
                if(a.find(c,bl+e)>0):
                    res=1
                else:res=0
            else:res=0
    else:res=0

    d=a[::-1]
    if((b in d)&(c in d)):
            bl=d.find(b)
            if(bl+e<=len(a)-1):
                if(d.find(c,bl+e)>0):
                    res+=2
                else:res+=0
            else:res+=0
    else:res+=0    
    if(res==0):print'invalid'
    if(res==1):print'forward'
    if(res==2):print'backward'
    if(res==3):print'both'

