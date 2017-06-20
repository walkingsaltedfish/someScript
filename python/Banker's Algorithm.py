# -*- coding: utf-8 -*-
import sys


def changedata(num):
    for i in range(0,3,1):
        syshave[i]=syshave[i]-need[num*3+i]
        get[num*3+i]=get[num*3+i]+need[num*3+i]
        need[num*3+i]=0

def compare(num):
    for i in range(0,3,1):
        if syshave[i]-need[num*3+i]<0:
            return 0
        else:
            return 1

def restore(num):
    syshave[0]=syshave[0]+get[num*3]
    syshave[1]=syshave[1]+get[num*3+1]
    syshave[2]=syshave[2]+get[num*3+2]


maxneed=[7,5,3,3,2,2,9,0,2,2,2,2,4,3,3]
syshave=[3,3,2]
syshave1=[3,3,2]
get=[0,1,0,2,0,0,3,0,2,2,1,1,0,0,2]
get1=[0,1,0,2,0,0,3,0,2,2,1,1,0,0,2]
need=[7,4,3,1,2,2,6,0,0,0,1,1,4,3,1]
need1=[7,4,3,1,2,2,6,0,0,0,1,1,4,3,1]
wantoget=[0,1,2]
order=[0,0,0,0,0]
f=[0,0,0,0,0]
ABC=['A','B','C']
str=''
str1='Y'
str2='N'
waiterflag=['1']

while(1):
    sys.stdout.write( "请输入请求进程号0-4:")
    id=input()
    print ("进程%d的请求资源"  %id)
    for i in range(0,3,1):
        sys.stdout.write("资源%s为：" %ABC[i]);wantoget[i]=input()
        if wantoget[i]<0:
            print "输入错误，输入小于零"
            waiterflag[0]='2'
            break
        if wantoget[i]>maxneed[id*3+i]:
            print "请求错误，请求资源大于最大需求"
            waiterflag[0]='2'
            break
        if wantoget[i]>syshave1[i]:
            waiterflag[0]='3'

    if waiterflag[0] == '3':
        print ("进程%d进行等待，请求资源大于目前系统可用,请输入下一个进程请求" %id)

    if waiterflag[0] == '1':
        for i in range(0,3,1):
            syshave1[i]=syshave1[i]-wantoget[i]
            syshave[i]=syshave1[i]
            need1[id*3+i]=need1[id*3+i]-wantoget[i]
            need[i]=need1[i]
            get1[id*3+i]=get1[id*3+i]+wantoget[i]
            get[i]=get1[i]

        print ("当前分配结果为：")
        print ("*****    Max     Allocation     Need      Available ")
        print ("***** A   B   C   A   B   C   A   B   C   A   B   C  ")
        print (" P%d   %d   %d   %d   %d   %d   %d   %d   %d   %d  "  %(0,maxneed[0],maxneed[1],maxneed[2],get[0],get[1],get[2],need[0],need[1],need[2])),
        print ("%d   %d   %d" %(syshave[0],syshave[1],syshave[2]))
        for i in range(1,5,1):
            print (" P%d   %d   %d   %d   %d   %d   %d   %d   %d   %d  "  %(i,maxneed[i*3],maxneed[i*3+1],maxneed[i*3+2],get[i*3],get[i*3+1],get[i*3+2],need[i*3],need[i*3+1],need[i*3+2]))

        print ("__________________________________________________________________________")
        print ("**************************安全性检查*************************************")
        print ("*****    Work     Allocation     Need      Available+Work ")
        print ("***** A   B   C   A   B   C   A   B   C   A   B   C     Finish")
        ze=0
        while(1):
            count=0
            for id in range(0,5,1):
                if f[id]!=1:
                    flag=compare(id)
                    if flag:
                        print (" P%d   %d   %d   %d   %d   %d   %d   %d   %d   %d  "  %(id,syshave[0],syshave[1],syshave[2],get[i*3],get[i*3+1],get[i*3+2],need[i*3],need[i*3+1],need[i*3+2])),
                        changedata(id)
                        restore(id)
                        print ("%d   %d   %d     true " %(syshave[0],syshave[1],syshave[2]))
                        f[id]=1
                        order[ze]=id
                        ze=ze+1
                        count=count+1
            if count==0:
                break

        if ze<5:
            print ("该请求不合理，系统进入不安全状态")
            break
        else:
            print ("请求合理，此时安全序列为:")
            for i in range(0,5,1):
                print (order[i]),
            print ("")

    print ("是否继续分配？   是（Y）；否（N）")
    waiterflag[0] = '1'
    str=raw_input()
    if str!=str1:
        break






















