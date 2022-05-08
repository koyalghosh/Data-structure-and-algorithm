//Doubly link list
//Functions:- Add first,add last,add before,add after, traversal,delete node,count,sorting,reverseing of linked list
#include<iostream>
using namespace std;
struct node{
	int info;
	node* next;
	node* prev;
};
void addfirst(node *& ,int );
void addlast(node *& ,int );
void addafter(node *& ,int ,int );
void addbefore(node *& ,int ,int );
void traversal(node *);
void delnode(node *&,int );
void count(node *);
void sorting(node* );
void reverse(node *&);
int main(){
	node *start=NULL;
	int item,num;
	int n;
	while(1){
		cout<<"MENU "<<endl<<endl;
		cout<<"1.Add at first"<<endl;
		cout<<"2.Add before an element"<<endl;
		cout<<"3.Add after an element"<<endl;
		cout<<"4.Add at last"<<endl;
		cout<<"5.Delete an element"<<endl;
		cout<<"6.Display link list"<<endl;
		cout<<"7.Count number of nodes"<<endl;
		cout<<"8.Sort the elements"<<endl;
		cout<<"9.Reverse elements"<<endl;
		cout<<"10.Exit"<<endl<<endl;
		cout<<"Enter your choice:- ";
		cin>>n;cout<<endl;
		switch(n){
			case 1:
				cout<<"Enter your element:- ";
				cin>>item;
				addfirst(start,item);
				cout<<endl;
				break;
			case 2:
				cout<<"Enter element you want to add:- ";
				cin>>num;
				cout<<"Enter the element before which you want to add:- ";
				cin>>item;
				addbefore(start,item,num);//Adding num before item
				cout<<endl;
				break;
			case 3:
				cout<<"Enter element you want to add:- ";
				cin>>num;
				cout<<"Enter the element after which you want to add:- ";
				cin>>item;
				addafter(start,item,num);//Adding num after item
				cout<<endl;
				break;
			case 4:
				cout<<"Enter your element:- ";
				cin>>item;
				addlast(start,item);
				cout<<endl;
				break;
			case 5:
				cout<<"Enter the element you want to delete:- ";
				cin>>item;
				delnode(start,item);
				cout<<endl;
				break;
			case 6:
				cout<<"Your singly linked list is :- ";
				traversal(start);
				cout<<endl<<endl;
				break;
			case 7:
				cout<<"Number of  element/nodes in your linked list are :- ";
				count(start);
				cout<<endl<<endl;
				break;
			case 8:
				cout<<"After sorting link list is ";
				sorting(start);
				traversal(start);
				cout<<endl;
				break;
			case 9:
				cout<<"After reversing link list ";
				reverse(start);
				traversal(start);
				cout<<endl;
				break;
			case 10:
				exit(0);
			default :
				cout<<"INVALID INPUT"<<endl;
		}
	}
	return 0;
}
inline void addfirst(node *&start,int item){
	node *newnode;
	newnode=new node;
	newnode->info=item;
	newnode->prev=NULL;
	newnode->next=start;
	start=newnode;
}
inline void addlast(node *&start,int item){
	node *newnode,*ptr;
	newnode=new node;
	newnode->info=item;
	newnode->next=NULL;
	if(start==NULL){
		newnode->prev=NULL;
		newnode->next=NULL;
		start=newnode;
	}
	else{
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	newnode->next=NULL;
	newnode->prev=ptr;
	ptr->next=newnode;
	}
}
inline void addafter(node *&start,int item,int numb){
	node *newnode,*ptr;
	newnode=new node;
	newnode->info=numb;
	if(start==NULL){
		cout<<"Linked list is empty unable to search.."<<endl<<endl;
		return;
	}
	ptr=start;
	while(ptr!=NULL && ptr->info!=item)//here ptr!=NULL is used instead of ptr->next!=NULL to check the info of last number
		ptr=ptr->next;
	if(ptr==NULL){
		cout<<"Number not found.."<<endl;
		return;
	}
	newnode->next=ptr->next;
	if(ptr->next!=NULL){//if not taken ptr!=null then we will be unable to check this condition
		ptr->next->prev=newnode;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
}
inline void addbefore(node *&start,int item,int numb){
	node *newnode,*ptr;
	newnode=new node;
	newnode->info=numb;
	if(start==NULL){
		cout<<"Linked list is empty insert some elements.."<<endl<<endl;
		return;
	}
	ptr=start;
	while(ptr!=NULL && ptr->info!=item){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		cout<<"Element not found.."<<endl;
		return;
	}
	if(ptr==start){
		newnode->prev=NULL;
		newnode->next=ptr;
		ptr->prev=newnode;
		start=newnode;
	}
	else{
		newnode->prev=ptr->prev;
		ptr->prev->next=newnode;
		newnode->next=ptr;
		ptr->prev=newnode;
	}
}
inline void traversal(node *start){
	node *ptr;
	ptr=start;
	if(start==NULL){
		cout<<"Linked list is empty no element to display..";
		return;
	}
	while(ptr!=NULL){
		cout<<ptr->info<<"\t";
		ptr=ptr->next;
	}
}
inline void delnode(node *&start,int item){
	node *ptr;
	if(start==NULL){
		cout<<"Your linked list is empty nothung to delete..";
		return;
	}
	ptr=start;
	while(ptr!=NULL && ptr->info!=item){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		cout<<"Element not found..";
		return;
	}
	if(ptr==start){
		ptr->next->prev=NULL;
		start=ptr->next;
	}
	else if(ptr->next!=NULL){
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
	}
	else{
		ptr->prev->next=NULL;
	}
	delete ptr;
}
inline void count(node *start){
	node *ptr=start;
	int count=0;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	cout<<count;
}
inline void sorting(node* start){
	node *p1,*p2;
	p1=p2=NULL;
	for(p1=start;p1->next!=NULL;p1=p1->next){
		for(p2=p1->next;p2!=NULL;p2=p2->next){
			if(p1->info > p2->info){
				int t;
				t=p1->info;
				p1->info=p2->info;
				p2->info=t;
			}
		}
	}
}
inline void reverse(node *&start){
	node *p1,*p2,*p3;
	p1=start;
	p2=NULL;
	while(p1!=NULL){
		p3=p2;
		p2=p1;
		p1=p1->next;
		p2->next=p3;
	}
	start=p2;
}
