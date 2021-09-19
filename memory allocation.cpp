#include<iostream>
#include<malloc.h>

using namespace std;

int main(){
	int *p;
	//trong C++
	p= new int;
	delete p;

	/*trong C
	p=(int*)malloc(sizeof(int));
	free(p);*/
	return 0;
}
