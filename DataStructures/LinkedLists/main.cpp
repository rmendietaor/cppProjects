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

        ~LinkedList(){
            Node* next = nullptr;
            while (header != nullptr){
                next = header->next;
                delete header;
                header = next;
            }
        }

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

        void removeFirst(){
            if(header != nullptr){
                Node* temp = header;
                header = header->next;
                delete temp;
                size--;
            }
        }

        void removeLast(){
            if(header->next == nullptr){
                removeFirst();
            }
            else if(header != nullptr){
                Node* curr = header;
                Node* prev = nullptr;
                while(curr->next != nullptr){
                    prev = curr;
                    curr = curr->next;
                }
                tail = prev;
                prev->next = nullptr;
                delete curr;
                size--;
            }
        }

        void removeAt(int pos){
            if(pos > size || pos < 1)
                return;
            else if(pos == 1)
                removeFirst();
            else if(pos == size)
                removeLast();
            else if (header != nullptr){
                Node* prev = nullptr;
                Node* curr = header;
                for(int i=1; i<pos; i++){
                    prev = curr;
                    curr = curr->next;
                }
                prev->next=curr->next;
                delete curr;
                size--;
            }
        }

        void insertAt(int pos, int data){
            if(pos > size+1 || pos < 1)
                return;
            else if(pos == 1)
                prepend(data);
            else if(pos == size+1)
                append(data);
            else if(header != nullptr){
                Node* n = new Node(data);
                Node* prev = nullptr;
                Node* curr = header;
                for(int i=1;i<pos;i++){
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = n;
                n->next = curr;
                size++;
            } 
        }
};

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.toString();
    list.insertAt(2,5);
    list.toString();
}