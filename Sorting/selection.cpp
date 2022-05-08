#include<iostream>
using namespace std;

int main(){
	int *ar;
	int n,i,j;
	cout<<"Enter number of elements:- ";
	cin>>n;
	ar=new int [n];
	//input
	for(i=0;i<n;i++){
		cout<<"Enter "<<i+1<<"element : ";
		cin>>ar[i];
	}
	//selection sort loop
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(ar[i]>ar[j]){
				int t;
				t=ar[i];
				ar[i]=ar[j];
				ar[j]=t;
			}
		}
	}
	//printing 
	for(int i=0;i<n;i++)
		cout<<ar[i]<<"\t";
	return 0;
}

