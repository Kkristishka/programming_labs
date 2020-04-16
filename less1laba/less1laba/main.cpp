#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
using namespace std;
namespace fs = std::__fs::filesystem;

int main()
{
    string log, devicename, userdevicename, path, data_time;
    for (;;)
    {
        cout << "Enter the device name: ";
        cin >> userdevicename;
        cout << endl << "Date \t \t      Value" << endl;
        for (auto& p : fs::directory_iterator("/Users/kristinaammosova/Desktop/labs/programming_labs/less1laba/less1laba/logs"))
            {
                ifstream file(p.path().generic_string());
                path = p.path().generic_string();
                int q = 84;
                while (path[q] != ')')
                {
                    data_time += path[q];
                    q++;
                }
                while (getline(file, log))
                {
                    int i = 0;
                    int j = 0;
                    bool set = 0;
                    while (log[i] != '\0')
                    {
                        if (log[i] == ':')
                        {
                            set = 1;
                        }
                        if (set == 1)
                        {
                            if (userdevicename[j] == log[i + 1])
                            {
                                devicename += userdevicename[j];
                                j++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        i++;
                    }
                    if (userdevicename == devicename && log[i + 1] == ':')
                    {
                            data_time += ':';
                            data_time.push_back(32);

                            int k = i + 2;
                            while (log[k] != '\0')
                            {
                                data_time += log[k];
                                k++;
                            }
                            cout << data_time << endl;
                        data_time.clear();
                    }
                    devicename.clear();
                }
                data_time.clear();
            }
    }
}
