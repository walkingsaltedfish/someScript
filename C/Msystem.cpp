#include<stdio.h> 
#include<iostream>
#include<stdlib.h> 
#include<fstream>
#include<cstring>


using namespace std;

struct M_type{
	int id;
	char type[16];
	char data[256];
	int to;
	
}mch[16],buff[16];



int input(int num){
	
	int a=num;
	cout<<"输入设备id:";
	cin>>mch[num].id;
	cout<<"输入设备类型:";
	cin>>mch[num].type;
	cout<<"输入设备信息描述:";
	cin>>mch[num].data;	
	//cout<<"数据输入，ok"<<endl;
	
	
	a++;
	return(a);	
} 


void menu(){
	cout<<endl;
	cout<<endl;
	cout<<"请输入数字以执行您想要的功能,输入必须为1~5,："<<endl;
	cout<<"1.查询特定设备信息"<<endl;
	cout<<"2.增加设备信息"<<endl;
	cout<<"3.删除某台设备信息"<<endl;
	cout<<"4.打印所有设备"<<endl;

	cout<<"5.退出"<<endl;
//	cout<<"6.格式化并重新输入"<<endl;
}

int select(int id,int num){	

	int a,n=0;
	a=num;

	
	while(n<a){

		if(mch[n].id==id){
			cout<<"查询结果："<<endl;
			cout<<"***********位置-"<<(n+1)<<"***********"<<endl;
			cout<<"设备ID："<<mch[n].id<<endl;
			cout<<"设备类型："<<mch[n].type<<endl;
			cout<<"设备信息："<<mch[n].data<<endl;
			cout<<endl;
			//cout<<"数据库设备总量为："<<mch.to<<endl;	
			cout<<"****************************"<<endl;
	}
	
	n++;
	
	}	
	return 1;
}



int prin(int num){	
	
	int a,n=0;
	a=num;

	while(n<a){
	
	cout<<"***********位置"<<(n+1)<<"***********"<<endl;
	cout<<"设备ID："<<mch[n].id<<endl;
	cout<<"设备类型："<<mch[n].type<<endl;
	cout<<"设备信息："<<mch[n].data<<endl;
	cout<<endl;
//	cout<<"数据库设备总量为："<<mch.to<<endl;	
	cout<<"****************************"<<endl;
	
	n++;
	
	}	
	return 1;
}

int dele(int num,int id){
	int i=id;
	int a=num;
	int n=0,m=0;
	while(n<num){
		if((n+1)!=i){
			buff[m].id=mch[n].id;
			strcpy(buff[m].type,mch[n].type);
			strcpy(buff[m].data,mch[n].data);
			buff[m].to=num-1;
			
			cout<<"设备ID："<<buff[m].id<<endl;
			cout<<"设备类型："<<buff[m].type<<endl;
			cout<<"设备信息："<<buff[m].data<<endl;	
			
			
			m++;
			
		}
		n++;
	}
	cout<<"删除成功。以上为剩余设备"<<endl;
	n=0;
	while(n<(a--)){
		mch[n].id=buff[n].id;
		strcpy(mch[n].type,buff[n].type);
		strcpy(mch[n].data,buff[n].data);
		mch[n].to=buff[n].to;
	}
	return(a);
}

int main(){
	string name;
	string pw;
	char ch;
	int id,num;
	num=0;
	cout<<"***********请先登陆***********"<<endl;
	cout<<"请输入用户名（默认为root）:"<<endl;
	cin>>name;
	while(name!="root"){
		cout<<"用户名错误，需要重新输入："<<endl;
		cin>>name; 
	}
	cout<<"请输入密码（默认为root）:"<<endl;
	cin>>pw;
	while(pw!="root"){
		cout<<"密码错误，需要重新输入："<<endl;
		cin>>pw; 
	}	           
	cout<<"欢迎，root "<<endl;
	
	cout<<"当前数据库为空，请先录入设备。"<<endl;
	num=input(num);
	while(1){
		
		menu();
		scanf("%s",&ch);
		if(ch=='2'){
			num=input(num);
			
		}
		
		
		if(ch=='1'){
			cout<<"请输入查询设备的id："<<endl;
			cin>>id;
			if((select(id,num))==0){
				cout<<"查询失败"<<endl;	
			}
			
		}
		
		if(ch=='3'){
			cout<<"请输入要删除的设备id:"<<endl;
			cin>>id;
			num=dele(num,id);
			
		}
		
		if(ch=='4'){
			cout<<"*********以下为所有设备：*********"<<endl;
			if((prin(num))==0){
				cout<<"查询失败"<<endl;	
			}	
		}
		
		if(ch=='5'){
			exit(0); 
			
			
		}
		


	}
	
	return 0;
}


