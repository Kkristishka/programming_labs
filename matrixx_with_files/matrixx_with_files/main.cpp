#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void static_arr()
{
    int r_rows, r_cols, l_rows, l_cols, s;
    cout<<"\t size of matrix A"<<endl;
    cin>>l_rows>>l_cols;
    cout<<"\t size of matrix B"<<endl;
    cin>>r_rows>>r_cols;
                
    if(l_cols==r_rows)
    {
        int left_array[l_rows][l_cols];
        int right_array[r_rows][r_cols];
        int arr[l_rows][r_cols];
        cout<<"\t matrix A"<<endl;
        for(int i=0; i<l_rows; i++)
        {
            for(int j=0; j<l_cols; j++)
                {
                    cin>>left_array[i][j];
                }
        }
        for(int i=0; i<l_rows; i++)
            {
                for(int j=0; j<l_cols; j++)
                    {
                        cout<<left_array[i][j]<<"\t";
                    }
                    cout<<endl;
            }
        cout<<"\t matrix B"<<endl;
        for(int a=0; a<r_rows; a++)
            {
                for(int b=0; b<r_cols; b++)
                    {
                        cin>>right_array[a][b];
                    }
            }
                for(int a=0; a<r_rows; a++)
                {
                    for(int b=0; b<r_cols; b++)
                    {
                        cout<<right_array[a][b]<<"\t";
                    }
                    cout<<endl;
                }
                
        for(int i=0; i<l_rows; i++)
            {
                for(int k=0; k<r_cols; k++)
                    {
                        s = 0;
                        for(int j=0; j<r_rows; j++)
                        {
                            s += left_array[i][j]*right_array[j][k];
                        }
                        arr[i][k] = s;
                    }
            }

        cout<<"\t AxB:"<<endl;
        string path = "/Users/kristinaammosova/Documents/static.txt";
        fstream file(path, ios::out);
            for(int i=0; i<l_rows; i++)
                {
                    for(int j=0; j<r_cols; j++)
                    {
                        cout<<arr[i][j]<<"\t";
                        file << arr[i][j]<<"\t";
                    }
                    cout<<endl;
                }
        file.close();
                    
    }
    else
        {
            cout<<"\t change the size"<<endl;
        }
}
 
void dynamic_arr()
{
    int r_rows, r_cols, l_rows, l_cols, s;
    cout<<"\t size of matrix A"<<endl;
    cin>>l_rows>>l_cols;
    cout<<"\t size of matrix B"<<endl;
    cin>>r_rows>>r_cols;
    int **l_arr = new int* [l_rows];
    for(int i=0; i<l_rows; i++)
        {
            l_arr[i] = new int[l_cols];
        }
    for(int i=0; i<l_rows; i++)
        {
            delete[] l_arr[i];
        }
    delete[] l_arr;
    
    if(l_cols==r_rows)
        {
            cout<<"\t matrix A"<<endl;
            for(int i=0; i<l_rows; i++)
            {
                for(int j=0; j<l_cols; j++)
                    {
                        cin>>l_arr[i][j];
                    }
            }
    for(int i=0; i<l_rows; i++)
        {
            for(int j=0; j<l_cols; j++)
                {
                    cout<<l_arr[i][j]<<"\t";
                }
            cout<<endl;
        }
    int **r_arr = new int* [r_rows];
    for(int a=0; a<r_rows; a++)
        {
            r_arr[a] = new int[r_cols];
        }
    for(int a=0; a<r_rows; a++)
        {
            delete[] r_arr[a];
        }
    delete[] r_arr;
            
    cout<<"\t matrix B"<<endl;
    for(int a=0; a<r_rows; a++)
        {
            for(int b=0; b<r_cols; b++)
                {
                    cin>>r_arr[a][b];
                }
        }
    for(int a=0; a<r_rows; a++)
        {
            for(int b=0; b<r_cols; b++)
                {
                    cout<<r_arr[a][b]<<"\t";
                }
            cout<<endl;
        }
    int arr[l_rows][r_cols];
        for(int i=0; i<l_rows; i++)
            {
                for(int k=0; k<r_cols; k++)
                    {
                        s = 0;
                        for(int j=0; j<r_rows; j++)
                            {
                                s += l_arr[i][j]*r_arr[j][k];
                            }
                        arr[i][k] = s;
                    }
            }

    cout<<"\t AxB"<<endl;
    string path = "/Users/kristinaammosova/Documents/dynamic.txt";
    fstream file(path, ios::out);
        for(int i=0; i<l_rows; i++)
            {
                for(int j=0; j<r_cols; j++)
                    {
                        cout<<arr[i][j]<<"\t";
                        file << arr[i][j] << "\t";
                    }
                cout<<endl;
            }
            file.close();
        }
    else
        {
            cout<<"\t change the size"<<endl;
        }
}

void vector_arr()
{
    int r_rows, r_cols, l_rows, l_cols, s;
    cout<<"\t size of matrix A"<<endl;
    cin>>l_rows>>l_cols;
    cout<<"\t size of matrix B"<<endl;
    cin>>r_rows>>r_cols;
    
    if(l_cols==r_rows)
    {
    cout<<"\t matrix A"<<endl;
    vector<vector<int>> V1(l_rows);
    for(int i=0; i<l_rows; i++)
        {
            V1[i].resize(l_cols);
            for(int j=0; j<l_cols; j++)
                {
                    cin>>V1[i][j];
                }
        }
    for(int i=0; i<l_rows; i++)
        {
            V1[i].resize(l_cols);
            for(int j=0; j<l_cols; j++)
            {
                cout<<V1[i][j]<<"\t";
            }
            cout<<endl;
        }
    
    cout<<"\t matrix B"<<endl;
    vector<vector<int>> V2(r_rows);
    for(int i=0; i<r_rows; i++)
    {
        V2[i].resize(r_cols);
        for(int j=0; j<r_cols; j++)
        {
            cin>>V2[i][j];
        }
    }
    for(int i=0; i<r_rows; i++)
    {
        V2[i].resize(r_cols);
        for(int j=0; j<r_cols; j++)
        {
            cout<<V2[i][j]<<"\t";
        }
        cout<<endl;
    }
    vector<vector<int>> V3(l_rows);
    for(int i=0; i<l_rows; i++)
        {
            V3[i].resize(r_cols);
            for(int k=0; k<r_cols; k++)
                {
                    s = 0;
                    for(int j=0; j<r_rows; j++)
                        {
                            s += V1[i][j]*V2[j][k];
                        }
                    V3[i][k] = s;
                }
        }
    cout<<"\t AxB"<<endl;
    string path = "/Users/kristinaammosova/Documents/vector.txt";
    fstream file(path, ios::out);
    for(int i=0; i<l_rows; i++)
    {
        for(int j=0; j<r_cols; j++)
        {
            cout<<V3[i][j]<<"\t";
            file << V3[i][j] << "\t";
        }
        cout<<endl;
    }
        file.close();
    }
    else
    {
        cout<<"\t change the size"<<endl;
    }
}

int main()
{
    int x;
    for(;;)
        {
            cout<<"\t menu \n 1 - static\n 2 - dynamic\n 3 - vector\n 4 - show previous answers\n 5 - exit\n "<<endl;
            cin>>x;
            if(x==1)
                {
                    static_arr(); continue;
                }
            if(x==2)
                {
                    dynamic_arr(); continue;
                }
            if(x==3)
                {
                    vector_arr(); continue;
                }
            if(x==4)
            {
                for(;;)
                {
                    cout<<" 1 - static\n 2 - dynamic\n 3 - vector\n 4 - exit\n"<<endl;
                    cin>>x;
                    if(x==1)
                        {
                            fstream file("/Users/kristinaammosova/Documents/static.txt", ios::in);
                            string A;
                            file >> A;
                            cout << A;
                            getline(file, A);
                            cout << A << endl;
                            file.close();
                            continue;
                        }
                    if(x==2)
                        {
                            fstream file("/Users/kristinaammosova/Documents/dynamic.txt", ios::in);
                            string A;
                            file >> A;
                            cout << A;
                            getline(file, A);
                            cout << A << endl;
                            file.close();
                            continue;
                        }
                    if(x==3)
                        {
                            fstream file("/Users/kristinaammosova/Documents/vector.txt", ios::in);
                            string A;
                            file >> A;
                            cout << A;
                            getline(file, A);
                            cout << A << endl;
                            file.close();
                            continue;
                        }
                    
                    else
                        return 0; break;
                }
            }
            else
                {
                    return 0; break;
                }
        }
    return 0;
}
