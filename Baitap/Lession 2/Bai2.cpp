#include <iostream>
using namespace std;
int main()
{
    int n, i;

    do {
        cout << "Nhap mot so nguyen duong: ";
        cin >> n;
    }
    while (n <= 0);
    
    cout <<"So nguyen duong: "<< n << endl;

    return 0;
}
