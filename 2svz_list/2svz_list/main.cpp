#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node * Next;
    Node * Prev;
    Node(int data, Node * new_next= nullptr, Node * new_prev= nullptr){
        this->data = data;
        this->Next = new_next;
        this->Prev = new_prev;
    }
};

class List
{
    int count;
    Node * firstElem;
    Node * lastElem;
    
    void ShowOne(Node * elem);
    Node * _find(int index){
        int counter = 0;
        Node* iterator = firstElem;
        while(iterator != nullptr){
            if(counter == index){
                return iterator;
            }
            counter++;
            iterator = iterator->Next;
        }
        return nullptr;
    }
public:
     bool AddElem(unsigned int index, int data){
        
        if(index == 0){
            auto new_elem = new Node(data, firstElem);
            firstElem = new_elem;
            count++;
            return true;
        }
        auto parent = _find(index - 1);
        if(parent == nullptr){
            return false;
        }
        auto new_elem = new Node(data, parent->Next, parent);
         if ( parent->Next != nullptr){
             parent->Next->Prev = new_elem;
         }
         parent->Next = new_elem;
         count++;
         return true;
        
    }
    
    int FindElem(int index){
        auto element = _find(index);
        if(element != nullptr){
            return element->data;
        }
        throw new runtime_error("elem does not found");
        return -9999;
    }
    void ShowList();
    List()
    {
        firstElem = nullptr;
        lastElem = nullptr;
    }
    
    bool remove_first_elem()
    {
        auto element = firstElem;
        if (firstElem == nullptr)
        {
            return false;
        }
        else if(count != 0 && count != 1)
        {
            firstElem = firstElem->Next;
            delete element;
            count--;
        }
        else if(count==1)
        {
            delete element;
            count--;
        }
        
        return true;
    }
    
    bool remove(unsigned int index){
        auto element = _find(index);
        if (element == nullptr){
            return false;
        }
        auto deleted_elem_next = element->Next;
        auto deleted_elem_prev = element->Prev;
        
        if (deleted_elem_next != nullptr){
            deleted_elem_next->Prev = deleted_elem_prev;
        }
        
        if (deleted_elem_prev != nullptr){
            deleted_elem_prev->Next = deleted_elem_next;
        }
        if( index == 0){
            firstElem = deleted_elem_next;
        }
        if( index == count - 1){
            lastElem = deleted_elem_prev;
        }
        count--;
        delete element;
        
        return true;
    }
    
    
    bool remove_all(){
        
        while(count)
        {
            remove_first_elem();
        }
        return true;
    }
    ~List()
    {
        remove_all();
    }
};

void List::ShowList()
{
    Node * iterator = firstElem;

    while(iterator != nullptr)
    {
        List::ShowOne(iterator);
        iterator=iterator->Next;
    }
}

void List::ShowOne(Node * elem){
    if(elem != nullptr)
        cout << elem->data << endl;
}

int main()
{
    List list;
    list.AddElem(0, 1);
    list.AddElem(1, 2222);
    list.AddElem(2, 2);
    list.AddElem(3, 3);
    list.remove(1);
    list.ShowList();
    
    return 0;
}
