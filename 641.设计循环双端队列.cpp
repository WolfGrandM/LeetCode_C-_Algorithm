/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
   int *data;
   int Front, Rear;
   int capacity;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
   data = new int[k + 1];
    capacity = k + 1;
    Front = Rear = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
   if (isFull()) return false;
  Front = (Front - 1 + capacity) % capacity;
  data[Front] = value;
  return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
if (isFull()) return false;
  data[Rear] = value;
  Rear = (Rear + 1) % capacity;
  return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
    if (isEmpty()) return false;
  Front = (Front + 1) % capacity;
  return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
    if (isEmpty()) return false;
  Rear = (Rear - 1 + capacity) % capacity;
  return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
if (isEmpty()) return -1;
  return data[Front];
    }

    /** Get the last item from the deque. */
    int getRear() {
   if (isEmpty()) return -1;
  return data[(Rear - 1 + capacity) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
     return (Front == Rear);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
     return ((Rear + 1) % capacity == Front);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

