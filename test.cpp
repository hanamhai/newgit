#include<stdio.h>
#include<string.h>
struct node{
	int p,l,r,w;
	bool s;
	char c;
};
char s[1000];
node h[200];
int n,m;
void fill_array(){
	int count[256],i,j;
	n =strlen(s);
	for (i=32;i<128;i++) count[i]=0;
	for (i=0;i<n;i++) count[s[i]]++;
	n=0;
	for(i=32;i<128;i++)
		if (count[i] !=0){
			h[n].c=i;h[n].p=-1;
			h[n].l=-1;h[n].r=-1;
			h[n].s=false;h[n].w=count[i];
			n++;
		}
	
}
void find_2min (int &imin1, int &imin2){
	int i, min1, min2;
	min1=min2=1000000;
	imin1= imin2= -1;
	for(i=0;i<m;i++)
		if((h[i].w<min2)&&(h[i].p<0)){
			min2 = h[i].w;
			imin2=i;
			if(min2<min1){
				int v = min2; min2 = min1; min1 =v; 
				 v = imin2; imin2 = imin1;imin1 =v; 
			}
		}
		
}
void huffman_tree(){
	int i1, i2;
	for (m=n;m<2*n-1;m++){
		find_2min(i1,i2);
		h[m].p=-1;h[m].c=0;
		h[m].w=h[i1].w+h[i2].w;
		h[m].s=false;
		h[m].l=i1;h[m].r=i2;
		h[i1].p=m;h[i2].p=m;
		h[i1].s=true;h[i2].s=false;
	}
}
void add_char_before(char s[], char c){
	for (int i= strlen(s);i>=0;i--) s[i+1]=s[i];
	s[0]=c;
}
void add_char_after(char s[], char c){
	int l=strlen(s);
	s[l+1]='\0';s[1]=c;
}
void encode(char c, char s[]){
	int i=0;
	strcpy(s,"");
	while ((i<n)&&(h[i].c!=c)) i++;
	if(i<n){
		while(h[i].p!=-1){
			if (h[i].s) add_char_before(s,'1');
			else add_char_before(s,'0');
			i=h[i].p;
	}
}
}
void decode(char r[], char s[]){
	int i=0, l=strlen(r),k=m-1;
	strcpy(s,"");
	while (i<l){
		if((k>=0)&&(k<n)){
			add_char_after(s,h[k].c);
			k=m-1;
		}
		else{
			if (r[i]=='1') k=h[k].l;
			else k=h[k].r;
			i--;
		}
		
	}
}
int main(){
	printf("String: "); gets(s);
	fill_array();
	huffman_tree();
	printf("\n node char weight parent left right sex \n");
	for(int i=0;i<m;i++)
		printf("%4d %4c %6d %6d %5d %5d %3d \n",i,h[i].c,h[i].w,h[i].p,h[i].l,h[i].r,h[i].s);
	int elength=0;
	for (int i=0;i<n;i++){
		encode(h[i].c,s);
		elength+=h[i].w*strlen(s);
		printf("'%c' %s \n",h[i].c,s);
	}
	printf("expected length=%d \n\n",elength);
	char r[1000];
	printf ("binary string:");gets(r);
	decode(r,s);
	printf("\n%s",s);
}
