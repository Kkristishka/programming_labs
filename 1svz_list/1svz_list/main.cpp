#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node * Next;
    Node(int data, Node * new_next= nullptr){
        this->data = data;
        this->Next = new_next;
    }
};

class List
{
    int count;
    Node * firstElem;
    
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
        auto new_elem = new Node(data, parent->Next);
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
    }
    
    bool remove_first_elem()
    {
        if (firstElem == nullptr)
        {
            return false;
        }
        else
            firstElem = firstElem -> Next;
        delete firstElem;
        count--;
        
        return true;
    }
    
    bool remove(unsigned int index){
        
        auto element = _find(index);
        if(count == 0)
        {
            return false;
        }
        if(index == 0)
        {
            remove_first_elem();
        }
        else
        {
            for(int i=1; i < index; i++)
            {
                firstElem = firstElem -> Next;
            }
            element = firstElem -> Next;
            firstElem -> Next = firstElem -> Next -> Next;
            delete element;
            count--;
        }
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
    list.AddElem(1, 2);
    list.AddElem(2, 3);

    list.remove(1);
    list.ShowList();
    
    return 0;
}
