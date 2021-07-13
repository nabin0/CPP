#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int prev;
    cin >> prev;

    bool isValid = true;
    bool isDecreasing = true;

// Logic to check order of inputs series
    while (--n)
    {
        int curr;
        cin >> curr;
        if (curr == prev)
        {
            isValid = false;
            break;
        }
        else if (curr > prev)
        {
            isDecreasing = false;
        }
        else if (!isDecreasing && curr < prev)
        {
            isValid = false;
            break;
        }

        prev = curr;
    }

// Displaying output
    if (isValid)
    {

        if (isDecreasing)
        {
            cout << "Decreasing" << endl;
        }
        else if (!isDecreasing)
        {
            cout << "Increasing" << endl;
        }
    }
    else
    {
        cout << "Not Valid" << endl;
    }
    // cout << boolalpha << isValid << endl;

    return 0;
}