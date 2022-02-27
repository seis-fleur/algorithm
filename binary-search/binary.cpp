#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int target = 0, high = 0, mid = 0, low  = 0;
    bool found = false;
    string input_list;
    vector<int> v = {};
    string number;
    ifstream infile;
    infile.open("binary_test.txt");

    getline (infile, input_list);
    stringstream ss(input_list);
   
    while (getline(ss, number, ' '))
        v.push_back(stoi(number));
    
    infile >> target;
    infile.close();

    high = v.size() - 1;
  
    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (v[mid] == target)
        {
            found = true;
            break;
        }
        if (v[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (found)
        cout<<target<<" is found at index "<<mid<<"."<<endl;
    else
        cout<<target<<" is not found."<<endl;

    return 0;
}