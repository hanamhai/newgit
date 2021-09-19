#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
struct TreapNod  { //node declaration
   int data;
   int priority;
   TreapNod* l, *r;
   TreapNod(int d) { //constructor
      this->data = d;
      this->priority = rand() % 100;//cho ra so ngau nhien tu 1 den 100
      this->l= this->r = nullptr;
   }
};
void rotLeft(TreapNod* &root) { //left rotation(ham xoay trai cay nhi phan)
   TreapNod* R = root->r;
   TreapNod* X = root->r->l;
   R->l = root;
   root->r= X;
   root = R;
}
void rotRight(TreapNod* &root) { //right rotation(ham xoay phai cay nhi phan)
   TreapNod* L = root->l;
   TreapNod* Y = root->l->r;
   L->r = root;
   root->l= Y;
   root = L;
}
void insertNod(TreapNod* &root, int d) { //insertion(them phan tu moi cho cay)
   if (root == nullptr) {
      root = new TreapNod(d);
      return;
   }
   if (d < root->data) { //neu du lieu da cho it hon thi nut goc 
      insertNod(root->l, d);// chen du lieu vao cay con ben trai
      if (root->l != nullptr && root->l->priority > root->priority)//xoay phai neu khoa heap vi pham
      rotRight(root);
   } else {
      insertNod(root->r, d);//nguoc lai thi chen du lieu vao cay con ben phai 
      if (root->r!= nullptr && root->r->priority > root->priority)//xoay trai neu khoa heap vi pham
      rotLeft(root);
   }
}
bool searchNod(TreapNod* root, int key) {//ham tim kiem nut
   if (root == nullptr)//neu khong co key thi tra ve gia tri false
      return false;
   if (root->data == key)//neu co key thi tra ve gia tri true
      return true;
   if (key < root->data)//neu khoa nho hon goc thi tim kiem trong cay con ben trai(1)
      return searchNod(root->l, key);
      return searchNod(root->r, key);//nguoc lai (1)
}
void deleteNod(TreapNod* &root, int key) {//ham xoa nut
   //node to be deleted which is a leaf node(ham xoa nut la)
   if (root == nullptr)
      return;
   if (key < root->data)
      deleteNod(root->l, key);
   else if (key > root->data)
      deleteNod(root->r, key);
      //node to be deleted which has two children(nut bi xoa co 2 nut con)
   else {
      if (root->l ==nullptr && root->r == nullptr) {
         delete root;
         root = nullptr;
      }
      else if (root->l != nullptr && root->r != nullptr) {
         if (root->l->priority < root->r->priority) {
            rotLeft(root);
            deleteNod(root->l, key);
         } else {
            rotRight(root);
            deleteNod(root->r, key);
         }
      }
      //node to be deleted has only one child(nut bi xoa co 1 nut con)
      else {
         TreapNod* child = (root->l)? root->l: root->r;
         TreapNod* curr = root;
         root = child;
         delete curr;
      }
   }
}
void displayTreap(TreapNod *root, int space = 0, int height =10) { //display treap
   if (root == nullptr)
      return;
   space += height;
   displayTreap(root->l, space);
   cout << endl;
   for (int i = height; i <=space; i++)
      cout << ' ';
      cout << root->data << "(" << root->priority << ")";
      cout << endl;
   displayTreap(root->r, space);
}
int main() {
   int nums[] = {7,1,6,4,3,2,8,9,10,11 };
   int a = sizeof(nums)/sizeof(int);
   TreapNod* root = nullptr;
   srand(time(nullptr));
   for(int n: nums)
      insertNod(root, n);
   cout << "cau truc cay Treap:\n\n";
   displayTreap(root);
   cout << "\nxoa node 8:\n\n";
   deleteNod(root, 8);
   displayTreap(root);
   cout << "\nxoa node 3:\n\n";
   deleteNod(root, 3);
   displayTreap(root);
   return 0;
}
