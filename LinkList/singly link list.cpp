//Singly link list
//Functions:-Add first,add last,add after,add before,traverse,delnode,count ,sorting,reverse.
#include<iostream>
using namespace std;
struct node{
	int info;
	struct node* next;
};
void addfirst(node *& ,int );//here change in start may be needed for some cases
void addlast(node *& ,int );//here change in start may be needed for some cases
void addafter(node *& ,int ,int );//here change in start may be needed for some cases
void addbefore(node *& ,int ,int );//here change in start may be needed for some cases
void traversal(node *);//here not used & becoz if don't want to change our start pointer
void delnode(node *&,int );//here change in start may be needed for some cases
void count(node *);//here not used & becoz if don't want to change our start pointer
void sorting(node* );//here not used & becoz if don't want to change our start pointer
void reverse(node *&);//here change in start may be needed for some cases
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
		cout<<"8.Sort the link list"<<endl;
		cout<<"9.Reverse the link list"<<endl;
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
				addbefore(start,item,num);//item k phele num add kro
				cout<<endl;
				break;
			case 3:
				cout<<"Enter element you want to add:- ";
				cin>>num;
				cout<<"Enter the element after which you want to add:- ";
				cin>>item;
				addafter(start,item,num);//item k baad num add kro
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
				cout<<"Your link list after sorting is :- ";
				sorting(start);
				traversal(start);
				cout<<endl;
				break;
			case 9:
				cout<<"Your reversed link list is :- ";
				reverse(start);
				traversal(start);
				cout<<endl;
				break;
			case 10:
				exit(1);
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
	newnode->next=start;
	start=newnode;
}
inline void addlast(node *&start,int item){
	node *newnode,*ptr;
	newnode=new node;
	newnode->info=item;
	newnode->next=NULL;
	if(start==NULL){
		start=newnode;
	}
	else{
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
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
	while(ptr->next!=NULL && ptr->info!=item){//here ptr!=NULL is used instead of ptr->next!=NULL to check the info of last number
	ptr=ptr->next;
	}
	if(ptr->info!=item){
		cout<<"Element not found "<<endl;
		return;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
}
inline void addbefore(node *&start,int item,int numb){
	node *newnode,*ptr,*preptr;
	newnode=new node;
	newnode->info=numb;
	if(start==NULL){
		cout<<"Linked list is empty insert some elements.."<<endl<<endl;
		return;
	}
	preptr=NULL;
	ptr=start;
	while(ptr->next!=NULL && ptr->info!=item){
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr->info!=item){
		cout<<"Element not found.."<<endl;
		return;
	}
	if(ptr==start){
		newnode->next=ptr;
		start=newnode;
	}
	else{
		preptr->next=newnode;
		newnode->next=ptr;
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
	node *ptr,*preptr;
	if(start==NULL){
		cout<<"Your linked list is empty nothung to delete..";
		return;
	}
	ptr=start;
	preptr=NULL;
	while(ptr!=NULL && ptr->info!=item){
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL){
		cout<<"Element not found..";
		return;
	}
	if(ptr==start)
	start=ptr->next;
	else
	preptr->next=ptr->next;
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
