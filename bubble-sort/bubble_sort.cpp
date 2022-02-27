#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string input_list;
    vector<string> v = {};
    string word;
    
    ifstream infile;
    infile.open("bubble_test.txt");

    getline (infile, input_list);
    stringstream ss(input_list);
   
    while (getline(ss, word, ' '))
        v.push_back(word);

    infile.close();

    bool swapped;
    int last_unsorted_index = v.size() - 1;
    string temp;
    do 
    {
        swapped = false;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i-1] > v[i])
            {
                temp = v[i];
                v[i] = v[i-1];
                v[i-1] = temp;
                swapped = true;
            }

        }
    } while (swapped);

    for (string x : v)
        cout<<x<<" ";

}