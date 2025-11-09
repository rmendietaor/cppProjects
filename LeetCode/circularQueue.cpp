#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue{
    private:
        int curr;
        int size;
        int head;
        int tail;
        vector<int> queue;
    public:
        MyCircularQueue(int k){
            queue = vector<int>(k);
            size = k;
            head = -1;
            tail = -1;
            curr = 0;
        }

        bool enQueue(int value) {
            if(curr == size)
                return false;
            else if(curr == 0){
                head++;
                tail++;
                curr++;
                queue[tail]=value;
                return true;
            }
            else{
                if(tail == size-1 && curr < size)
                    tail=tail-size+1;
                else
                    tail++;
                queue[tail]=value;
                curr++;
                return true;
            }
        }

        int Front(){
            cout << "Front: " << queue[head] << endl;
            if(curr==0)
                return -1;
            else
                return queue[head];
        }

        int Rear(){
            cout << "Rear: " << queue[tail] << endl;
            if(curr==0)
                return -1;
            else 
                return queue[tail];
        }

        bool deQueue(){
            if(curr == 0)
                return false;
            else{
                queue[head] = 0;
                curr--;
                if(curr==0){
                    head = -1;
                    tail = -1;
                    return true;
                }
                else if(head==size-1)
                    head = 0;
                else
                    head++;
                return true;
            }
        }

        bool isEmpty(){
            if(curr == 0)
                return 1;
            else
                return 0;
        }

        bool isFull(){
            if(curr == size)
                return 1;
            else
                return 0;
        }

        void printElements(){
            cout << "Current queue (" << curr << " elements)" << endl;
            for(int element : queue){
                cout << element << endl;
            }
            cout << "Head: " << head << ", Tail: " << tail << endl;
            cout << "===" << endl;
        }

        void printIndexes(){
            cout << "Head: " << head << ", Tail: " << tail << endl;
        }
};

int main(){
    MyCircularQueue queue(5);
    queue.printElements();
    queue.enQueue(1);
    queue.printElements();
    queue.deQueue();
    queue.printElements();
    queue.enQueue(2);
    queue.printElements();
    queue.enQueue(3);
    queue.printElements();
    queue.deQueue();
    queue.printElements();
    queue.Front();
}