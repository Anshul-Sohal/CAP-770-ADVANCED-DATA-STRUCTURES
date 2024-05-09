#include <iostream>
using namespace std;
const int MAX_SIZE = 5;
int arr[MAX_SIZE];
int front = -1, rear = -1;
bool isEmpty() {
    return front == -1 && rear == -1;
}
bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}
void enqueue(int element) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    arr[rear] = element;
}
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    int removedElement = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return removedElement;
}
int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty. No front element." << endl;
        return -1;
    }
    return arr[front];
}
int getRear() {
    if (isEmpty()) {
        cout << "Queue is empty. No rear element." << endl;
        return -1;
    }
    return arr[rear];
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    cout << "Dequeue: " << dequeue() << endl;
    cout << "Dequeue: " << dequeue() << endl;
    enqueue(6);
    enqueue(7);
    cout << "Front element: " << getFront() << endl;
    cout << "Rear element: " << getRear() << endl;

    return 0;
}
