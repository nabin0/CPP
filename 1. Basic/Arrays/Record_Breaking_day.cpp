// There are n days. Then a day is record breaking day if it satisfies both of the following condition,
// 1. The number of visitors are strictly larger than the number of visitors in each of the previous day.
// 2. either its last day or the number of visitor are lager than the following day.

// There are two solutions for this problem


// --------------Solution with O(n^2) Time complexicity---------------------

#include <iostream>
using namespace std;

void recordBreakingDays(int arr[], int n)
{
    int rbd = 0;
    bool isRbd = false;

    // First day can be Record breaking day if only 2nd term is true
    if (arr[0] > arr[1])
    {
        cout << "Day " << 1 << " is Record Breaking day with visitors " << arr[0] << "\n";
        rbd++;
    }
    else
    {
        cout << "Day " << 1 << " is Not a Record Breaking day." << endl;
    }

    for (int i = 1; i < n; i++)
    {
        isRbd = false;
        for (int j = 0; j < i; j++)
        {
            if ((arr[j] < arr[i]) && (arr[i] > arr[i + 1]))
            {
                isRbd = true;
            }
            else
            {
                isRbd = false;
                break;
            }
        }

        if (isRbd)
        {
            cout << "Day " << i + 1 << " is Record Breaking day with visitors " << arr[i] << "\n";
            rbd++;
        }
        else
        {
            cout << "Day " << i + 1 << " is Not a Record Breaking day." << endl;
        }
    }
    cout << "Total record breaking days are " << rbd << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // To make 2nd term true for last element
    arr[n] = -1;

    recordBreakingDays(arr, n);

    return 0;
}



// ------------Solution with O(n) Time complexicity

/*

#include <iostream>
#include <climits>
using namespace std;

void recordBreakingDays(int arr[], int n)
{
    int mx = INT_MIN;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] > mx) and (arr[i] > arr[i+1]))
        {
            total++;
            cout << "Day " << i + 1 << " is Record Breaking day with visitors " << arr[i] << "\n";
        }else{
            cout << "Day " << i + 1 << " is Not a Record Breaking day with visitors " << arr[i] << "\n";
        }
        mx = max(mx, arr[i]);
    }
    cout<<"Total record breaking days : "<<total<<endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // To make 2nd term true for last element
    arr[n] = -1;

    recordBreakingDays(arr, n);
    return 0;
}

*/