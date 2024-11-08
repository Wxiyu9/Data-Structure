#define _CRT_SECURE_NO_WARNINGS 1



// 6 0 0 0 0 
typedef struct {
    int* a;
    int rear;
    int head;
    int k;
} MyCircularQueue;
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->a = (int*)malloc(sizeof(int) * (k + 1));
    q->rear = q->head = 0;
    q->k = k;
    return q;
}
// h r
// 6 0 0 0 0
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    else {
        *(obj->a + obj->rear) = value;
        obj->rear = (obj->rear + 1) % (obj->k + 1);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    else {
        obj->head = (obj->head + 1) % (obj->k + 1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else {
        return *(obj->a + obj->head);
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else {
        int x = obj->rear == 0 ? obj->k : obj->rear - 1;
        return *(obj->a + x);
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->rear == obj->head)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->rear + 1 == obj->head)
    {
        return true;
    }
    else if (obj->rear == obj->k && obj->head == 0) {
        return true;
    }
    else {
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    obj->a = NULL;
    obj->rear = obj->head = obj->k = 0;
    free(obj);
    obj = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/