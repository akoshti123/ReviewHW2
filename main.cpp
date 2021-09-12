#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string temp, temp2;
    string name = "vowels_";
    cout<<"Enter File Name of input file: ";
    cin>>temp;
    string line;
    name += temp;
    int x = 0;
    fstream file(temp, ios::binary | ios::in | ios::out);
    ofstream file2(name, ios::out);
    if (file.is_open())
    {
        while (getline(file,line))
        {
            if (x > 0)
            {
                file2 << '\n';
            }
            string test = line;
            int n = test.length();
            char test_array[5000];
            strcpy(test_array, test.c_str());
            for (int i = 0; i < sizeof(test_array); i++)
            {
                char check = test_array[i];
                if (check == 'A' || check == 'a' || check == 'E' || check == 'e' || check == 'I' || check == 'i' || check == 'O' || check == 'o' || check == 'U' || check == 'u')
                {
                    file2 << check;
                }
                else if (check == '\0')
                {
                    x++;
                    break;
                }
            }
        }
        file.close();
        file2.close();
        return 0;
    }
}
