#include <iostream>
using namespace std;

class Stack{
protected:
    int top = -1;
    int size;
    int* data;

public:
    Stack(int size) : size(size) {
        this->data = new int[size];
    }
    ~Stack() { delete[]data; }

protected:
    bool isFull() { return top == size - 1; }
    bool isEmpty() { return top == -1; }

public:

    virtual void Push(int item) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        data[++top] = item;
        size++;
    }

    int Peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[top];
    }

    int Pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[top--];
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top -> ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " -> ";
        }
        cout << "Bottom" << endl;
    }

};

class DynamicStack : public Stack {
public:
    DynamicStack(int size) : Stack(size) {}

    void Push(int item) override{
        if (isFull()) {
            int* temp = new int[2 * size];
            //Copying the old data
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            this->data = temp;
            data[++top] = item;
        }else {
            data[++top] = item;
        }
    }
};


int main() {
    DynamicStack stk(5);
    stk.Display();
    stk.Push(1);
    stk.Push(2);
    stk.Push(3);
    stk.Push(4);
    stk.Push(5);
    stk.Push(6);
    stk.Display();
    cout << stk.Pop() << endl;
    cout << stk.Pop() << endl;
    cout << stk.Pop() << endl;
    cout << stk.Pop() << endl;
    cout << stk.Pop() << endl;
    stk.Display();
    cout << stk.Pop() << endl;
    cout << stk.Pop() << endl;
    stk.Display();
}