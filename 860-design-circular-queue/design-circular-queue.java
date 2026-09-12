class MyCircularQueue {
    int arr[];
    int rear;
    int front;
    int size;

    public MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }

    public boolean enQueue(int value) {
        if ((rear + 1) % size == front) {
            return false;
        }

        if (front == -1) {
            front = (front + 1) % size;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;

        return true;
    }

    public boolean deQueue() {
        if (front == -1) {
            return false;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return true;
    }

    public int Front() {
        if (front == -1) {
            return -1;
        }

        return arr[front];
    }

    public int Rear() {
        if (rear == -1) {
            return -1;
        }

        return arr[rear];
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {
        return (rear + 1) % size == front;
    }
}