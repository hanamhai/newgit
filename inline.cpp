#include<iostream>

using namespace std;

inline int tinhDientich(int cd, int cr){
	return cd*cr;
}


int main(){
	int d=5;
	int r=4;
	cout<<"Dien tich hinh chu nhat la:"<<tinhDientich(d,r);
}
