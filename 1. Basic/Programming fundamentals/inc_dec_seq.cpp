// Check wether the sequence is increasing, decreasing or not


//------------------ Solution One-----------------


#include <iostream>
using namespace std;

void order(int arr[], int n)
{
    int i = 0, j = 1;
    bool inc = false, dec = false, valid = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[j])
        {
            valid = true;
            break;
        }
        else if (arr[i] > arr[j] && !inc)
        {
            dec = true;
        }
        else if (arr[i] < arr[j] && !dec)
        {
            inc = true;
        }
        else
        {
            valid = true;
            break;
        }

        j++;
    }

    if (inc)
    {
        cout << "Order is increasing" << endl;
    }
    else if (dec)
    {
        cout << "Order is decreasing" << endl;
    }
    else if (valid)
    {
        cout << "Not Valid" << endl;
    }
    else
    {
        cout << "Something is wrong!!!" << endl;
    }
}

int main()
{
    int n;
    cout << "How many elements you want to enter. " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    order(arr, n);
    return 0;
}




//------------------ Solution two-----------------

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