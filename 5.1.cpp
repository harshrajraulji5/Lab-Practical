#include<iostream>
using namespace std;


#include <iostream>
using namespace std;

int q[5], front = 0, rear = -1;

void enqueue() {
    int x;
    if (rear == 4)
        cout << "Queue is Full\n";
    else {
        cout << "Enter value: ";
        cin >> x;
        q[++rear] = x;
    }
}

void dequeue() {
    if (front > rear)
        cout << "Queue is Empty\n";
    else
        cout << q[front++] << " deleted\n";
}

void display() {
    if (front > rear)
        cout << "Queue is Empty\n";
    else {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
}

int main() {
    enqueue();
    enqueue();
    enqueue();

    display();
    dequeue();
    display();

    return 0;
}





