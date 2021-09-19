#include<iostream>
#include<time.h>

using namespace std;

int main(){
	int n;
	cout<<"nhap N:"<<endl;
	cin>>n;
	
	int *p;
	p= new int[n];
	for(int i=0;i<n;i++){
		cout<<"nhap phan tu thu:"<<endl;
		cin>>*(p+i);
		
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(*(p+i)>*(p+j))swap(*(p+i),*(p+j));
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<*(p+i)<<"\t";
	}
	return 0;
}
