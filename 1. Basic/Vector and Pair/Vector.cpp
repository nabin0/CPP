#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //Declaring Vector
    vector<int> v;        //Method 1
    vector<int> v2(5, 7); //Method 2 :  v2(size, elements if you want same in whole array (*optional))

    //Initialisation of a vector
    v.push_back(1);
    v.push_back(5);
    v.push_back(41);
    v.push_back(2);
    v.push_back(17);

    //Poping element i.e removing last element
    v.pop_back(); //17 will be removed

    //<----Traversing a vector----->

    //Normal Looping method
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    //Loopng using iterator
    vector<int>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    //Using auto keyword

    for (auto elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;

    //Swapping values of two vectors

    vector<int> vec1(5, 67);
    vector<int> vec2(5, 44);

    swap(vec1, vec2);

    for (auto i : vec1)
    {
        cout << i << " "; //will return 44
    }
    cout << endl;

    //Sorting a vector
    sort(v.begin(), v.end()); //will return sorted array

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    
    return 0;
}