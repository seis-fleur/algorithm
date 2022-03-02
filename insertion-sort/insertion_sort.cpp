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
    cout<<"Unsorted List: \t";
    for (double i : v)
        cout<<i<<"\t";
    cout<<endl;
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
        cout << i;
        switch (i)
        {
            case 1: cout << "st"; break;
            case 2: cout << "nd"; break;
            case 3: cout << "rd"; break;
            default: cout<< "th"; break;
        }
        cout<<" pass: \t";
        for (double x : v)
            cout<<x<<"\t";
        cout<<endl;
    }
    
    return 0;
}
