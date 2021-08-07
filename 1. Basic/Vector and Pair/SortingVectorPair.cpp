#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{

    // Declaring and initialising arrays
    int arr1[] = {4, 6, 9, 3, 11, 5};
    int arr2[] = {1, 4, 8, 5, 3, 9};

    //Declaring Vector Pair
    vector<pair<int, int>> v;

    //Putting values of both arrays in vector pair
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        pair<int, int> p;
        p.first = arr1[i];
        p.second = arr2[i];
        v.push_back(p);
    }

    // sort(v.begin(), v.end()); //Shorts first element wise
    sort(v.begin(), v.end(), comparator); //To sort according to second elemet wise we need a comparator

    //Printing after sorting
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}