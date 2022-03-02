#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    int target = 0, high = 0, mid = 0, low  = 0;
    map <int, string> Movies;
    vector<int> years;
    bool found = false;
    int year = 0;
    string title = "";
    string line;

    ifstream infile;

    infile.open("binary_test.in");

    while (getline(infile, line))
    {
        year = stoi(line.substr(0, 4));
        title = (line.substr(5, string::npos));
        years.push_back(year);
        Movies.insert(make_pair(year, title));
    }
    cout<<"Choose year: "<<endl;
    for (int year: years)
    {
        cout<<year<<"\t";
    }
    cout<<endl;
    cin>>target;
    infile.close();

    high = Movies.size() - 1;
  
     while (low <= high)
     {
         mid = low + (high - low)/2;
         if (years[mid] == target)
         {
             found = true;
             break;
         }
         if (years[mid] > target)
             high = mid - 1;
         else
             low = mid + 1;
     }

     if (found)
        {
            cout<<"An MCU movie released on "<<target<<" is " <<Movies[target]<<"."<<endl;
            cout<<"It is found at index "<<mid<<"."<<endl;
        }
     else
         cout<<"There is no MCU movie released on."<<target<<endl;

    return 0;
}

