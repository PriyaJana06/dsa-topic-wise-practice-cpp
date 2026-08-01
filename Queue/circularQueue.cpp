#include<iostream>
using namespace std;

class CircularQueue{
    int* arr; 
    int capacity;  // total size of array
    int currSize;   // no. of elements stored in array

    int f, r;   // front, rear

public:
    CircularQueue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;   // empty

        f = r = -1;
    }

    void printQueue(){  // TC = O(N)
        if(empty()){
            cout << "Circular Queue is Empty\n";
            return;
        }

        int idx = f;
        cout << "Circular Queue elements: ";
        for(int i=0; i<currSize; i++){
            cout << arr[idx] << " ";
            idx = (idx + 1) % capacity;
        } cout << endl;
    }

    void printArray(){
        cout << "Array: ";
        for(int i = 0; i < capacity; i++){
            cout << arr[i] << " ";
        } cout << endl;
    }

    // Enqueue:
    void push(int val){   // TC = O(1)
        if(currSize == capacity){
            cout << "Circular Queue Overflow\n";
            return;
        }

        if(f == -1){
            f = r = 0;
        } else {
            r = (r+1) % capacity;
        }
        arr[r] = val;
        currSize++;
    }

    // Dequeue:
    void pop(){   // TC = O(1)
        if(empty()){
            cout << "Circular Queue Underflow\n";
            return;
        }

        if(f == r){
            f = r = -1;
        } else {
            f = (f+1) % capacity;
        }
        currSize--;
    }

    int front(){    // TC = O(1)
        if(empty()){
            cout << "Circular Queue Underflow\n";
            return -1;
        }
        return arr[f];
    }

    bool empty(){   // TC = O(1)
        return currSize == 0;
    }

    // prints rear of circular queue:
    int printRear(){
        return arr[r];
    }
};

int main(){
    CircularQueue cq(4);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);

    cout << "Front of queue: " << cq.front() << endl;
    cq.pop();
    cout << "Front of queue: " << cq.front() << endl;
    cq.push(5);
    cq.printQueue();  //circular queue: 2 3 4 5

    cout << "Print array: ";
    cq.printArray();    //array: 5 2 3 4

    cout << "Rear of Circular Queue: " << cq.printRear();
    
    return 0;
}