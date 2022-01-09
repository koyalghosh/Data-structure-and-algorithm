#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int coeff;
	int pow;
	node* next;
};
void append(node *&,int ,int );
void display(node *);
node* poly_add(node *&,node *&);
int main(){
	int n1,n2,i;
	node *start1,*start2,*start3;
	start1=start2=start3=NULL;
	cout<<"Enter number of terms of 1st polynomial and 2nd polynomial repectively:- ";
	cin>>n1>>n2;
	cout<<"Enter for 1st polynomial: "<<endl;
	for(i=0;i<n1;i++){
		int c,p;
		cout<<"Enter coeff and power of x in decreasing order of "<<i+1<<": ";
		cin>>c>>p;
		append(start1,c,p);
	}
	cout<<"Enter for 2nd polynomial: "<<endl;
	for(i=0;i<n2;i++){
		int c,p;
		cout<<"Enter coeff and power of x in decreasing order of "<<i+1<<": ";
		cin>>c>>p;
		append(start2,c,p);
	}
	start3=poly_add(start1,start2);
	cout<<"After add :- ";
	display(start3);
	return 0;
}
node * GetNode(int coeff,int pow){
	node *newnode;
	newnode=new node;
	newnode->coeff=coeff;
	newnode->pow=pow;
	return newnode;
}
void append(node *&start,int coeff,int pow){
	node *newnode,*ptr;
	newnode=GetNode(coeff,pow);
	newnode->next=NULL;
	if(start==NULL)
		start=newnode;
	else{
		ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
node* poly_add(node *&start1,node *&start2){
	node *start3,*l2,*l1;
	start3=NULL;
	//Condition for if an of the list is empty
	if(start1==NULL)
		return start2;	
	if(start2==NULL)
		return start2;
		l1=start1;l2=start2;
		while(l1!=NULL && l2!=NULL){
			if(l1->pow > l2->pow){
				append(start3,l1->coeff	,l1->pow);
				l1=l1->next;
			}
			if(l1->pow < l2->pow){
				append(start3,l2->coeff,l2->pow);
				l2=l2->next;
			}
			if(l1->pow==l2->pow){
				append(start3,l1->coeff+l2->coeff,l1->pow);
				l1=l1->next;
				l2=l2->next;
			}
		}
		while(l1!=NULL){
			append(start3,l1->coeff,l1->pow);
			l1=l1->next;
		}
		while(l2!=NULL){
			append(start3,l2->coeff,l2->pow);
			l2=l2->next;
		}
	return start3;
}
void display(node *start){
	if(start==NULL){
		cout<<"List is empty "<<endl;
		return;
	}
	node* ptr;
	ptr=start;
	while(ptr!=NULL){
		if(ptr->coeff >0)
		cout<<"+ "<<ptr->coeff<<"x^"<<ptr->pow<<" ";
		else
		cout<<"- "<<abs(ptr->coeff)<<"x^"<<ptr->pow<<" ";
		ptr=ptr->next;
	}
}
