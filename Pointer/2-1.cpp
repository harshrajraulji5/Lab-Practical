#include<iostream>
using namespace std;

int main()
{
    int arr[100],n;

    cout << "Enter Size of Array = ";
    cin >> n;

    cout << "Enter Element of Array = ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int *ptr = arr + n-1;

    cout << "Reverse Order = ";
    for(int i=0; i<n; i++)
    {
        cout << *ptr << " ";
        ptr--;
    }
    cout << endl;

    return 0;
}