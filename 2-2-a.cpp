#include <iostream>
using namespace std;

void swapByValue(int x, int y) 
{
    int temp = x;
    x = y;
    y = temp;
    cout << "x = " << x << ", y = " << y << endl;
}

int main() 
{
    int a = 10, b = 20;
    cout << "Before swap: ";
    cout << "a = " << a << ", b = " << b << endl;
    
    swapByValue(a, b);
    
    cout << "After swap: ";
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}