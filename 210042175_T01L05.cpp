#include <iostream>

class CircularQueue {
private:
    int *queue;
    int maxSize;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        maxSize = size;
        queue = new int[maxSize];
        front = -1;
        rear = -1;
    }

    void Enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue " << x << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }

        queue[rear] = x;
    }

    int Dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; 
        }

        int removed = queue[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }

        return removed;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }

        if (rear >= front) {
            return rear - front + 1;
        } else {
            return (maxSize - front) + (rear + 1);
        }
    }

    int Front() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; 
        }

        return queue[front];
    }

    int Rear() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return -1; 
        }

        return queue[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
};

int main() {
    CircularQueue cq(5);

    std::cout << "Enqueue 1: ";
    cq.Enqueue(1);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    std::cout << "Enqueue 2: ";
    cq.Enqueue(2);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    std::cout << "Enqueue 3: ";
    cq.Enqueue(3);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    std::cout << "Dequeue: " << cq.Dequeue() << std::endl;
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    std::cout << "Enqueue 4: ";
    cq.Enqueue(4);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    std::cout << "Enqueue 5: ";
    cq.Enqueue(5);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    std::cout << "Enqueue 6: ";
    cq.Enqueue(6);
    std::cout << "Front: " << cq.Front() << ", Rear: " << cq.Rear() << ", Size: " << cq.size() << std::endl;

    return 0;
}
