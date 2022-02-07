#include <iostream>
using namespace std;
 
int main()
{
    int n;
    long giaiThua = 1;
    
    do{
    cout << "Nhap so n: ";
    cin >> n;
<<<<<<< HEAD
	}while(n <= 0); 
=======
    }while(n <= 0);
>>>>>>> a6fde6f6ee526b8aef5e724eb920d96b2166cae2
    
    for(int i = 1; i <= n; i++) {
        giaiThua = giaiThua * i;
    }
    
    cout << n << "! = " << giaiThua << endl;
    
    return 0;
}

//Write a program to calculate n!

