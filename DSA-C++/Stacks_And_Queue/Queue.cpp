#include <iostream>
using namespace std;

class Queue {
protected:
    int rear = 0;
    int size;
    int* data;

    virtual bool isEmpty() { return rear == 0; }
    virtual bool isFull() { return rear == size; }
public:

    Queue(int size) : size(size) { this->data = new int[size]; }
    virtual ~Queue() { delete[] data; }

    virtual void Insert(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        data[rear++] = item;
    }

    virtual int Delete() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = data[0];
        for (int i = 1; i < rear; i++) {
            data[i-1] = data[i];
        }
        rear--;
        return temp;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return data[0];
    }

    virtual void Display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front <- ";
        for (int i = 0; i < rear; i++) {
            cout << data[i] << " <- ";
        }
        cout << "Rear" << endl;
    }

};

class CircularQueue : public Queue {
protected:
    bool isEmpty() override { return front == rear; }
    
public:
    int front = 0;
    CircularQueue(int size) : Queue(size + 1) {}
    void Insert(int item) override {
        data[rear] = item;
        rear = (rear + 1) % size;
    }

    int Delete() override {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int removed = data[front];
        front = (front + 1) % size;
        if (front == rear) {
            front = rear = 0;
        }
        return removed;
    }

    void Display() override {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        cout << "Front <- ";
        while (i != rear) {
            cout << data[i] << " <- ";
            i = (i + 1) % size;
        }
        cout << "Rear" << endl;
    }


};

int main() {
    CircularQueue q(5);
    q.Display();
    q.Insert(1);
    q.Insert(2);
    q.Insert(3);
    q.Insert(4);
    q.Insert(5);
    // q.Insert(6);
    // q.Insert(7);
    // q.Insert(8);
    // q.Insert(9);
    // q.Insert(10);
    cout << q.Delete() << endl;
    cout << q.Delete() << endl;
    cout << q.Delete() << endl;
    cout << q.Delete() << endl;
    cout << q.Delete() << endl;
    cout << q.Delete() << endl;
    q.Display();

}