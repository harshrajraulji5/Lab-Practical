#include <iostream>
using namespace std;

// Function Declaration
void insertion(int arr[], int &n);
void deletion(int arr[], int &n);
void searching(int arr[], int n);
void traverse(int arr[], int n);

int main()
{
    int arr[20], n;
    bool running = true;

    cout << "Enter number of elements: ";
    cin >> n;


    if(n > 20 || n <= 0)
{
    cout << "Array size must be between 1 and 20.";
    return 0;
}

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while(running)
    {
        int choice;

        cout << "\n\n===== MENU =====";
        cout << "\n1. Insertion";
        cout << "\n2. Deletion";
        cout << "\n3. Searching";
        cout << "\n4. Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                insertion(arr, n);
                break;

            case 2:
                deletion(arr, n);
                break;

            case 3:
                searching(arr, n);
                break;

            case 4:
                traverse(arr, n);
                break;

            case 5:
                running = false;
                cout << "Program Ended.";
                break;

            default:
                cout << "Invalid Choice!";
        }
    }

    return 0;
}

// Traversal Function
void traverse(int arr[], int n)
{
    cout << "\nArray Elements: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insertion Function
void insertion(int arr[], int &n)
{
    int pos, value;

    cout << "Enter Position: ";
    cin >> pos;

    cout << "Enter Value: ";
    cin >> value;

    for(int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Insertion Successful.\n";
    traverse(arr, n);
}

// Deletion Function
void deletion(int arr[], int &n)
{
    int pos;

    cout << "Enter Position to Delete: ";
    cin >> pos;

    for(int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Deletion Successful.\n";
    traverse(arr, n);
}

// Searching Function
void searching(int arr[], int n)
{
    int key;
    bool found = false;

    cout << "Enter Element to Search: ";
    cin >> key;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Element Found at Position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Element Not Found." << endl;
    }
}