#include <bits/stdc++.h>
using namespace std;
 
class Data
{
public:
    void print(int i)
    {
        cout << "Print int: " << i << endl;
    }
 
    void print(float i)
    {
        cout << "Print float: " << i << endl;
    }
 
    void print(string i)
    {
        cout << "Print string: " << i << endl;
    }
 
};
 
int main()
{
    Data obj;
    obj.print(1);
    obj.print(2.5);
    obj.print("Lap Trinh Khong Kho");
 
    return 0;
}
