#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string input_list;
    vector<double> v = {};
    string number;
    
    ifstream infile;
    infile.open("insertion_test.txt");

    getline (infile, input_list);
    stringstream ss(input_list);
   
    while (getline(ss, number, ' '))
        v.push_back(stod(number));

    infile.close();

    int lastSortedIndex = 0;
    double elem;
    for (int i = 1; i < v.size(); i++)
    {
        elem = v[i];
        int j = i - 1;

        while (elem < v[j] && j >=0)
        {
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = elem;
    }
    cout << "arranged list: ";
    for (double x : v)
            cout<<x<<" ";
    return 0;
}