#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularList
{
private:
    Node* head;

public:

    CircularList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main()
{
    CircularList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Circular Linked List:" << endl;
    list.display();

    list.insertAtBeginning(5);

    cout << "\nAfter insertion at beginning:" << endl;
    list.display();

    return 0;
}