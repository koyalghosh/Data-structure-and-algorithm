#include<iostream>
using namespace std;
int max(int[],int);//for finding max number in array
int max_count(int);//size of max num
int digit(int,int);//digit of kth place(k is defined in program)
void radix_sort(int[],int);

int main(){
	int n;
	cout<<"Enter the size of the array:- "<<endl;
	cin>>n;
	int ar[n],i;
	for(i=0;i<n;i++){
		cout<<"Enter element "<<i+1<<": ";
		cin>>ar[i];
	}
	radix_sort(ar,n);
	cout<<"After radix sorting:- "<<endl;
	for(i=0;i<n;i++){
		cout<<ar[i]<<"\t";
	}
	return 0;
}
void radix_sort(int ar[],int s){
	int bucket[10][s],i,j,k,r,c,l,cnt,m;
	m=max(ar,s);//here ar is array and s is size of the array
	cnt=max_count(m);//max is max number in array
	for(k=1;k<=cnt;k++){
		for(i=0;i<10;i++){
			for(j=0;j<s;j++){
			bucket[i][j]=-1;//initializing all values with -1 of array bucket
			}
		}
		//now putting values of array ar to bucket 
		for(i=0;i<s;i++){
		r=digit(ar[i],k);//passing i^th element of array to find its kth place for row
		c=0;//for column
		while(bucket[r][c]!=-1)//means initially all elements are initialized with -1
			c++;// only if condition is true
		bucket[r][c]=ar[i];//if condition becomes false. Now for i=2 while condition will become true becoz c=0 is full so it will update to c=1 and fill element to bucket matrix	
		//now we have to fill this bucket matrix elements to ar array
		}
	 	l=0;// l is for elements of array
		for(i=0;i<10;i++){//rows of bucket array
			for(j=0;j<s;j++){//columns of bucket array
				if(bucket[i][j]!=-1){//now some of the elements of bucket are !=-1 so putting those elements in ar array
					ar[l]=bucket[i][j];//putting !=-1 elements to array
					l++;
				}
			}
		}
	}
	
}								
int max(int ar[10],int s){
	int max=ar[0];
	for(int i=1;i<s;i++){
		if(ar[i]>max)
		max=ar[i];
	}
	return max;
}
int max_count(int m){
	int count=0;
	for(int i=m;i!=0;i=i/10){
		int c=m%10;
		count++;
	}
	return count;
}
int digit(int e,int k){
	int digit;
	for(int i=0;i<k;i++){
		digit=e%10;
		e=e/10;
	}
	return digit;
}
