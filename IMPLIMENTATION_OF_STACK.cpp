#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int *arr;
    int top;
    Stack(int n)
    {
        this->size = n;
        arr = new int[size];
        top = -1;
    }
    void push(int x)
    {
        if (top == size - 1)
            cout << "Stack is Full" << endl;
        else
        {
            top++;
            arr[top] = x;
        }
    }
    int pop()
    {
        if (top == -1)
            cout << "Stack is Empty" << endl;
        int value = arr[top];
        top--;
        return value;
    }
    void isempty()
    {
        if (top == -1)
            cout << "Yes : Stack is empty" << endl;
        else
            cout << "NO : Stack is not empty" << endl;
    }
    void topelement()
    {
        if (top == -1)
            cout << "Stack is empty so no top element is present" << endl;
        else
            cout << "Top element of stack is : " << arr[top] << endl;
    }
    void isfull()
    {
        if (top == size - 1)
            cout << "Yes : Stack is Full" << endl;
        else
            cout << "NO : Stack is not Full" << endl;
    }
    // function for size of stack
    void sizeofstack()
    {
        cout << "size of stack is : " << top + 1 << endl;
    }
};
int main()
{
    Stack s(5);
    s.isempty();
    s.isfull();
    s.push(10);
    s.push(20);
    s.topelement();
    s.pop();
    s.topelement();
    s.pop();
    s.sizeofstack();
    s.topelement();
    s.push(1);
    s.topelement();
    s.push(2);
    s.topelement();
    s.push(3);
    s.topelement();
    s.push(4);
    s.topelement();
    s.push(5);
    s.topelement();
    s.push(6);
    s.topelement();
    s.sizeofstack();
    return 0;
}
