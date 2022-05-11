#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
};
node* GetNode(int );
void AddFirst(node *&,int );
void AddLast(node *&,int );
void AddAfter(node *&,int ,int );
void AddBefore(node *&,int ,int );
void traverse(node *);
void DelNode(node *&,int );
int main(){
	int n,item,num;
	node* tail=NULL;//starting from last thats why named tail
	while(1){
	cout<<"MENU"<<endl;
	cout<<"1.Add first"<<endl;
	cout<<"2.Add last"<<endl;
	cout<<"3.Add before"<<endl;
	cout<<"4.Add after"<<endl;
	cout<<"5.Delete an element"<<endl;
	cout<<"6.Traverse"<<endl;
	cout<<"7.Exit"<<endl;
	cout<<"Enter your choice :-\t";
	cin>>n;
	switch(n){
		case 1:
			cout<<"Enter the element:- ";cin>>item;
			AddFirst(tail,item);
			break;
		case 2:
			cout<<"Enter the element:- ";cin>>item;
			AddLast(tail,item);
			break;
		case 3:
			cout<<"Enter the element:- ";cin>>num;
			cout<<"Enter the element before which you want to add:- ";cin>>item;
			AddBefore(tail,item,num);
			break;
		case 4:
			cout<<"Enter the element:- ";cin>>num;
			cout<<"Enter the element after which you want to add:- ";cin>>item;
			AddAfter(tail,item,num);
			break;
		case 5:
			cout<<"Enter the element you want to delete:- ";cin>>item;
			DelNode(tail,item);
			break;
		case 6:
			cout<<"Items of your link list are :- ";
			traverse(tail);
			cout<<endl;
			break;
		case 7:
			exit(1);
		default:
			cout<<"Enter valid input."<<endl;
	}
	}
	return 0;
}
node* GetNode(int item){
	node* newnode;
	newnode=new node;
	newnode->info=item;
	return newnode;
}
void AddFirst(node *&tail,int item){
	node* newnode;
	newnode=GetNode(item);
	if(tail==NULL){
		newnode->next=newnode;
		tail=newnode;
	}
	else{
		newnode->next=tail->next;
		tail->next=newnode;
	}
}
void traverse(node *tail){
	node* ptr;
	if(tail==NULL){
		cout<<"List is empty ";
		return;
	}
	ptr=tail->next;
	do{
		cout<<ptr->info<<"\t";
		ptr=ptr->next;
	}while(ptr!=tail->next);//using do while becoz if only used while condition it will failed without execution
}
void AddLast(node *&tail,int item){
	node* newnode;
	newnode=GetNode(item);
	if(tail==NULL){
		newnode->next=newnode;
		tail=newnode;
	}
	else{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
}
void AddBefore(node *&tail,int item,int num){
	if(tail==NULL){
		cout<<"List is empty. Unable to search."<<endl;
		return;
	}
	node* newnode,*ptr,*preptr;
	newnode=GetNode(num);
	ptr=tail->next;
	preptr=NULL;
	do{
		preptr=ptr;
		ptr=ptr->next;
	}while(ptr!=tail->next && ptr->info!=item);
	if(ptr->info!=item){
		cout<<"Item not found"<<endl;
		return;
	}
	newnode->next=ptr;
	if(ptr==tail->next)
		tail->next=newnode;
	else
		preptr->next=newnode;
}

void AddAfter(node *&tail,int item,int num){
	if(tail==NULL){
		cout<<"List is empty. Unable to search."<<endl;
		return;
	}
	node* newnode,*ptr;
	newnode=GetNode(num);
	ptr=tail->next;
	do{
		ptr=ptr->next;
	}while(ptr!=tail->next && ptr->info!=item);
	if(ptr->info!=item){
		cout<<"Item not found"<<endl;
		return;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
	if(ptr==tail)
		tail=newnode;
}
void DelNode(node *&tail,int item){
	if(tail==NULL){
		cout<<"List is empty. Unable to search."<<endl;
		return;
	}
	node *ptr,*preptr;
	ptr=tail->next;
	preptr=NULL;
	do{
		preptr=ptr;
		ptr=ptr->next;
	}while(ptr!=tail->next && ptr->info!=item);
	if(ptr->info!=item){
		cout<<"Item not found"<<endl;
		return;
	}
	if(ptr==tail){
		preptr->next=ptr->next;
		tail=ptr->next;
	}
	else if(ptr==tail->next)
		tail->next=ptr->next;
	else
	preptr->next=ptr->next;
	delete ptr;
}
