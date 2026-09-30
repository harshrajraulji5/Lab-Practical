#include<iostream>
using namespace std;
int stack[5];
int top=-1;
void push()
{
    int x;
    cout<<"enter value:";
    cin>>x;

    if(top==4)
    cout<<"stack overflow\n";
    else{
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    cout<<"stack underflow\n";
    else{
        cout<<"deleted element:"<<stack[top]<<endl;
        top--;
    }
}
void peek()
{
    if(top==-1)
    cout<<"stack is empty\n";
    else
    cout<<"top element:"<<stack[top]<<endl;
}
void display()
{
    if(top=-1)
    cout<<"stack is empty\n";
    else
    {
        cout<<"stack elements are:\n";
        for(int i=top;i>=0;i--)
        cout<<stack[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    push();
    push();
    display();
    peek();
    pop();
    display();
    return 0;
}