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
	cout<<"�����豸id:";
	cin>>mch[num].id;
	cout<<"�����豸����:";
	cin>>mch[num].type;
	cout<<"�����豸��Ϣ����:";
	cin>>mch[num].data;	
	//cout<<"�������룬ok"<<endl;
	
	
	a++;
	return(a);	
} 


void menu(){
	cout<<endl;
	cout<<endl;
	cout<<"������������ִ������Ҫ�Ĺ���,�������Ϊ1~5,��"<<endl;
	cout<<"1.��ѯ�ض��豸��Ϣ"<<endl;
	cout<<"2.�����豸��Ϣ"<<endl;
	cout<<"3.ɾ��ĳ̨�豸��Ϣ"<<endl;
	cout<<"4.��ӡ�����豸"<<endl;

	cout<<"5.�˳�"<<endl;
//	cout<<"6.��ʽ������������"<<endl;
}

int select(int id,int num){	

	int a,n=0;
	a=num;

	
	while(n<a){

		if(mch[n].id==id){
			cout<<"��ѯ�����"<<endl;
			cout<<"***********λ��-"<<(n+1)<<"***********"<<endl;
			cout<<"�豸ID��"<<mch[n].id<<endl;
			cout<<"�豸���ͣ�"<<mch[n].type<<endl;
			cout<<"�豸��Ϣ��"<<mch[n].data<<endl;
			cout<<endl;
			//cout<<"���ݿ��豸����Ϊ��"<<mch.to<<endl;	
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
	
	cout<<"***********λ��"<<(n+1)<<"***********"<<endl;
	cout<<"�豸ID��"<<mch[n].id<<endl;
	cout<<"�豸���ͣ�"<<mch[n].type<<endl;
	cout<<"�豸��Ϣ��"<<mch[n].data<<endl;
	cout<<endl;
//	cout<<"���ݿ��豸����Ϊ��"<<mch.to<<endl;	
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
			
			cout<<"�豸ID��"<<buff[m].id<<endl;
			cout<<"�豸���ͣ�"<<buff[m].type<<endl;
			cout<<"�豸��Ϣ��"<<buff[m].data<<endl;	
			
			
			m++;
			
		}
		n++;
	}
	cout<<"ɾ���ɹ�������Ϊʣ���豸"<<endl;
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
	cout<<"***********���ȵ�½***********"<<endl;
	cout<<"�������û�����Ĭ��Ϊroot��:"<<endl;
	cin>>name;
	while(name!="root"){
		cout<<"�û���������Ҫ�������룺"<<endl;
		cin>>name; 
	}
	cout<<"���������루Ĭ��Ϊroot��:"<<endl;
	cin>>pw;
	while(pw!="root"){
		cout<<"���������Ҫ�������룺"<<endl;
		cin>>pw; 
	}	           
	cout<<"��ӭ��root "<<endl;
	
	cout<<"��ǰ���ݿ�Ϊ�գ�����¼���豸��"<<endl;
	num=input(num);
	while(1){
		
		menu();
		scanf("%s",&ch);
		if(ch=='2'){
			num=input(num);
			
		}
		
		
		if(ch=='1'){
			cout<<"�������ѯ�豸��id��"<<endl;
			cin>>id;
			if((select(id,num))==0){
				cout<<"��ѯʧ��"<<endl;	
			}
			
		}
		
		if(ch=='3'){
			cout<<"������Ҫɾ�����豸id:"<<endl;
			cin>>id;
			num=dele(num,id);
			
		}
		
		if(ch=='4'){
			cout<<"*********����Ϊ�����豸��*********"<<endl;
			if((prin(num))==0){
				cout<<"��ѯʧ��"<<endl;	
			}	
		}
		
		if(ch=='5'){
			exit(0); 
			
			
		}
		


	}
	
	return 0;
}


