#include <iostream>
#include <vector>

using namespace std;

struct Tree_Elem
{
    int key;
    int data;
    Tree_Elem* left;
    Tree_Elem* right;
    Tree_Elem* parent;
    
    Tree_Elem(Tree_Elem* left = nullptr, Tree_Elem* right = nullptr, Tree_Elem* parent = nullptr)
    {
        data = 0;
        key = 0;
        this->left = left;
        this->right = right;
        this->parent = parent;
    }
};
class Tree
{
    private:
        Tree_Elem* firstElem;
        int count;
    public:
    Tree()
    {
        firstElem = nullptr;
        count = 0;
    }
    ~Tree()
    {
        delete_all_tree();
    }
    bool add_elem(unsigned int key, int data)
    {
        Tree_Elem* NewElem = new Tree_Elem();
        NewElem->data = data;
        NewElem->key = key;
        if (firstElem == nullptr)
        {
            firstElem = NewElem;
        }
        else
        {
            Tree_Elem* elem = firstElem;
            while (elem != nullptr)
            {
                if (key == elem->key)
                {
                    elem->data = NewElem->data;
                    break;
                }
                if (key > elem->key)
                {
                    if (elem->right != nullptr)
                    {
                        elem = elem->right;
                    }
                    else
                    {
                        break;
                    }
                }
                if (key < elem->key)
                {
                    if (elem->left != nullptr)
                    {
                        elem = elem->left;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            NewElem->parent = elem;
            if (key > elem->key)
            {
                elem->right = NewElem;
            }
            if (key < elem->key)
            {
                elem->left = NewElem;
            }
        }
        count++;
        return true;
    }
    
    Tree_Elem* find_by_key(unsigned int key)
    {
        Tree_Elem* elem = firstElem;
        if (firstElem != nullptr)
        {
            while (elem != nullptr)
            {
                if (key == elem->key)
                {
                    break;
                }
                else if (key > elem->key)
                {
                    if (elem->right != nullptr)
                    {
                        elem = elem->right;
                    }
                    else
                    {
                        elem = nullptr;
                        break;
                    }
                }
                else if (key < elem->key)
                {
                    if (elem->left != nullptr)
                    {
                        elem = elem->left;
                    }
                    else
                    {
                        elem = nullptr;
                        break;
                    }
                }
            }
        }
        return elem;
    }
    
    bool delete_by_key(unsigned int key)
    {
        Tree_Elem* del_elem = find_by_key(key);

        if (del_elem != nullptr)
        {
            if (del_elem != firstElem)
            {
                Tree_Elem* del_elem_parent = del_elem->parent;
                Tree_Elem* del_elem_left = del_elem->left;
                Tree_Elem* del_elem_right = del_elem->right;
                Tree_Elem* elem;
                if (del_elem_left != nullptr && del_elem_right != nullptr)
                {
                    if (del_elem_parent->right == del_elem)
                    {
                        del_elem_parent->right = del_elem_right;
                        del_elem_right->parent = del_elem_parent;
                    }
                    if (del_elem_parent->left == del_elem)
                    {
                        del_elem_parent->left = del_elem_right;
                        del_elem_right->parent = del_elem_parent;
                    }
                    elem = del_elem_right;
                    while (elem->left != nullptr)
                    {
                        elem = elem->left;
                    }
                    elem->left = del_elem_left;
                    del_elem_left->parent = elem;
                    delete del_elem;
                }
                else if (del_elem_right == nullptr && del_elem_left != nullptr)
                {
                    if (del_elem_parent->right == del_elem)
                    {
                        del_elem_parent->right = del_elem_left;
                        del_elem_left->parent = del_elem_parent;
                    }
                    if (del_elem_parent->left == del_elem)
                    {
                        del_elem_parent->left = del_elem_left;
                        del_elem_left->parent = del_elem_parent;
                    }
                    delete del_elem;
                }
                else if (del_elem_right != nullptr && del_elem_left == nullptr)
                {
                    if (del_elem_parent->right == del_elem)
                    {
                        del_elem_parent->right = del_elem_right;
                        del_elem_right->parent = del_elem_parent;
                    }
                    if (del_elem_parent->left == del_elem)
                    {
                        del_elem_parent->left = del_elem_right;
                        del_elem_right->parent = del_elem_parent;
                    }
                    delete del_elem;
                }
                else if (del_elem_left == nullptr && del_elem_right == nullptr)
                {
                    if (del_elem_parent->right == del_elem)
                    {
                        del_elem_parent->right = nullptr;
                    }
                    if (del_elem_parent->left == del_elem)
                    {
                        del_elem_parent->left = nullptr;
                    }
                    delete del_elem;
                }
                count--;
                return true;
            }
            else if (del_elem == firstElem)
            {
                Tree_Elem* del_elem_left = del_elem->left;
                Tree_Elem* del_elem_right = del_elem->right;
                Tree_Elem* elem;
                if (del_elem_left != nullptr && del_elem_right != nullptr)
                {
                    firstElem = del_elem_right;
                    del_elem_right->parent = nullptr;
                    elem = del_elem_right;
                    while (elem->left != nullptr)
                    {
                        elem = elem->left;
                    }
                    elem->left = del_elem_left;
                    del_elem_left->parent = elem;
                    delete del_elem;
                }
                else if (del_elem_right == nullptr && del_elem_left != nullptr)
                {
                    firstElem = del_elem_left;
                    del_elem_left->parent = nullptr;
                    delete del_elem;
                }
                else if (del_elem_right != nullptr && del_elem_left == nullptr)
                {
                    firstElem = del_elem_right;
                    del_elem_right->parent = nullptr;
                    delete del_elem;
                }
                else if (del_elem_left == nullptr && del_elem_right == nullptr)
                {
                    delete del_elem;
                }
                count--;
                return true;
            }
        }
        else
        {
            cout << "Element not found!!!" << endl;
            return true;
        }
        return true;
    }

    bool delete_all_tree()
    {
        Tree_Elem* elem = firstElem;
        Tree_Elem* elem_parent;
        while (firstElem != nullptr)
        {
            while (elem->left != nullptr)
            {
                elem = elem->left;
            }
            if (elem->right != nullptr)
            {
                elem = elem->right;
                continue;
            }
            if (elem->parent != nullptr)
            {
                elem_parent = elem->parent;
                if (elem_parent->left == elem)
                {
                    elem_parent->left = nullptr;
                }
                if (elem_parent->right == elem)
                {
                    elem_parent->right = nullptr;
                }
                delete elem;
                elem = elem_parent;
            }
            else
            {
                firstElem = nullptr;
                delete elem;
            }
            count--;
        }
        return true;
    }
    void show_all_elem(Tree_Elem* firstElem);
    void show_all_elem1() {    show_all_elem(firstElem); cout << endl;}
    void show_by_key(unsigned int key);
};
void Tree::show_all_elem(Tree_Elem* elem)
{
        cout << elem->data << " ";
        if (elem->left != nullptr)
        {
            show_all_elem(elem->left);
        }
        if (elem->right != nullptr)
        {
            show_all_elem(elem->right);
        }
        
}

void Tree::show_by_key(unsigned int key)
{
    Tree_Elem* elem = find_by_key(key);
    if (elem != nullptr)
    {
        cout << elem->key << "||" << elem->data << endl;
    }
    else
    {
        cout << "Element not found!!!" << endl;
    }
}

int main()
{
    Tree tr;
    tr.add_elem(0, 1);
    tr.add_elem(1, 2);
    tr.add_elem(2, 3);
    tr.show_all_elem1();
    tr.delete_by_key(1);
    tr.show_all_elem1();
}
