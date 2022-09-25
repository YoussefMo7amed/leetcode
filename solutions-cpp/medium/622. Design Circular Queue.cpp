class MyCircularQueue {
   private:
    deque<int> dq;

   public:
    int maxSize = 0;

    MyCircularQueue(int k) { maxSize = k; }

    bool enQueue(int value) {
        if (isFull()) return false;
        dq.push_back(value);
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        dq.pop_front();
        return true;
    }

    int Front() { return isEmpty() ? -1 : dq.front(); }

    int Rear() { return isEmpty() ? -1 : dq.back(); }

    bool isEmpty() { return dq.size() == 0; }

    bool isFull() { return dq.size() == maxSize; }
};