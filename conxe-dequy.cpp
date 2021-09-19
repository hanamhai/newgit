#include<stdio.h>
#include<math.h>
int a[20];
bool Ok(int x2,int y2){
    //ki?m tra cách d?t có th?a mãn không
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2  )
            return false;
    //N?u ki?m tra h?t các tru?ng h?p v?n không sai thì tr? v? true
    return true;
}
 
void Xuat(int n){
    //in ra m?t k?t qu?
    for(int i=1;i<=n;i++)
        printf(" %d",a[i]);
    printf("\n");
}
 
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        // th? d?t quân h?u vào các c?t t? 1 d?n n
        if(Ok(i,j)){
            //n?u cách d?t này th?a mãn thì luu l?i v? trí
            a[i] = j;
                        //n?u d?t xong quân h?u th? n thì xu?t ra m?t k?t qu?
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
 
int main(){
    int n = 4;// ? dây mình cho bài toán là 8 quân h?u trên bàn 8*8
    Try(1,n);
    return 0;
}
