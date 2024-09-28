//Approach-1 (Using Array)
//T.C : O(1)
//S.C : O(k)
/*class MyCircularDeque {
public:
    vector<int> deq;
    int K;
    int front;
    int rear;
    int currentCount;

    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(K, 0);
        front = 0;
        rear  = K-1;
        currentCount = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }

        front = (front - 1 + K) % K;
        deq[front] = value;
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }

        rear = (rear + 1) % K;
        deq[rear] = value;
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        front = (front + 1) % K;
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }

        rear = (rear - 1 + K) % K;
        currentCount--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }        

        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return deq[rear];
    }
    
    bool isEmpty() {
        return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == K;
    }
};
*/
class MyCircularDeque {
    deque<int> dq;
    int n;
public:
    MyCircularDeque(int k) {
        n = k;
    }
    
    bool insertFront(int value) {
        if(dq.size() == n)
            return false;
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(dq.size() == n)
            return false;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(dq.size() == 0)
            return false;
        dq.pop_front();        
        return true;
    }
    
    bool deleteLast() {
        if(dq.size() == 0)
            return false;
        dq.pop_back();        
        return true;
    }
    
    int getFront() {
        if(dq.size() == 0)
            return -1;
        return dq.front();
    }
    
    int getRear() {
        if(dq.size() == 0)
            return -1;
        return dq.back();        
    }
    
    bool isEmpty() {
        return dq.size() == 0;
    }
    
    bool isFull() {
        return dq.size() == n;
    }
};