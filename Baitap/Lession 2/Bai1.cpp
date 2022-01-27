#include <iostream>
using namespace std;
 
int main()
{
    int n;
    long giaiThua = 1;
    
    cout << "Nhap so n: ";
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        giaiThua = giaiThua * i;
    }
    
    cout << n << "! = " << giaiThua << endl;
    
    return 0;
}

//Write a program to calculate n!

/* cach 2

int giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << "Giai thua " << n << " la: " << giaiThua(n);
    return 0;
}

*/
