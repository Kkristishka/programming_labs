#include<iostream>
using namespace std;
void vvod_arr(int* pointer)
{
    int size;
    cout<<"the size"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] ";
        cin >> pointer[i];
    }
}
void vivod_arr(int* pointer)
{
    int size;
    cout<<"the size"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] " << pointer[i] << endl;
    }

}
int main()
{
    int size;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    
    int array[size];
    cout << "enter the array"<<endl;
    vvod_arr(array);
    cout << "the array"<<endl;
    vivod_arr(array);

    return 0;
}
