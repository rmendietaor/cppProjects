#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* header;
        Node* tail;
        int size;
    public:
        LinkedList(){
            header = nullptr;
            tail = nullptr;
            size = 0;
        };

        int getSize(){
            return size;
        }

        void append(int data){
            // Create new node
            Node* n = new Node(data);
            // Case 1: Empty list
            if(header==nullptr){
                header = n;
                tail = n;
            }
            // List is not empty
            else{
                tail->next = n;
                tail = n;
            }
            size++;
        };

        void prepend(int data){
            // Create new node
            Node* n = new Node(data);
            // Case1: Empty list
            if(header==nullptr){
                header = n;
                tail = n;
            }
            // Case2: List not empty
            else{
                n->next = header;
                header = n;
            }
            // Increment size
            size++;
        }

        void toString(){
            // Create a temp pointer
            Node* temp = header;
            // Create a loop that stops when next pointer is null
                // Print data and advance to the next pointer
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(4);
    list.toString();
}