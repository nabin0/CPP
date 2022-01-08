#include <iostream>
#include <algorithm>
using namespace std;

bool next_permutation(string &str, int n)
{

    int i = n - 1;
    while (str[i - 1] >= str[i])
    {

        if (--i == 0)
            return false;
    }
    
    int j = n - 1;
    while (j > i && str[j] <= str[i - 1])
        j--;

    swap(str[i - 1], str[j]);

    reverse(str.begin() + i, str.end());

    return true;
}

void permutations(string str)
{
    int n = str.length();

    if (n == 0)
        return;

    if (n == 1)
    {
        cout << str;
        return;
    }
        next_permutation(str, str.length());  

    cout << str;
}

int main()
{
    string str = "abedc";
    permutations(str); //edcba
    return 0;
}