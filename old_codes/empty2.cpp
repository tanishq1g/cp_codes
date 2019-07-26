#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;
struct snode{
	char a;
	snode* next;
}*top;

int sisempty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

int sisoneelement(){
	if(top->next==NULL)
		return 1;
	else
		return 0;
}

void sdisplay(){
	if(sisempty())
	;
	else{
		snode*curr;
		curr=top;
		do{
			
			curr=curr->next;
		}while(curr!=NULL);
		//printf("%d\n",tail->a);
	}
}

void push(int ele){
	snode *e=new snode();
	e->a=ele;
	e->next=NULL;
	if(sisempty()){
		top=e;
		//printf("%d\n",tail->a);
	}
	else{
		e->next=top;
		top=e;
	}
}

void pop(){
	if(sisempty()){
		
	}
	else if(sisoneelement()){
	
		top=NULL;
	}
	else{

		top=top->next;
	}
}

int main(){
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++ ){
		string str;
		cin>>str;
		top=NULL;
		int l=str.length(),sl=0;
		for(int i=0 ; i<l ; i++ ){
			push(str[i]);
			sl++;
		
			if(sl>=3){
				if ( top->a=='0' && top->next->a=='0' && top->next->next->a=='1' ){
					pop();pop();pop();
					sl-=3;
				}
			}
		
		}
		if (sl!=0)
			cout<<"Case "<<k+1<<":no\n";
		else
			cout<<"Case "<<k+1<<":yes\n";
	}
	return 0;
}