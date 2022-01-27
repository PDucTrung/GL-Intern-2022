#include <iostream>
using namespace std;
 
int main()
{
    int n;
    long giaiThua = 1;
    
    do{
    cout << "Nhap so n: ";
    cin >> n;
   	}while(n <= 0);
    
    for(int i = 1; i <= n; i++) {
        giaiThua = giaiThua * i;
    }
    
    cout << n << "! = " << giaiThua << endl;
    
    return 0;
}

//Write a program to calculate n!

