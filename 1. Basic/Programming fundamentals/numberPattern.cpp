/*
Problem: Print this pattern
    1
   232
  34543
 4567654
567898765
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        // Printing space
        for (int s = 0; s < n - i; s++)
        {
            cout << " ";
        }

        // For values (increasing)
        int val = i;
        for (int p = 0; p < i; p++)
        {
            cout << val;
            val += 1;
        }

        // (decreasing order)
        val = val - 2;
        for (int p = 0; p < i - 1; p++)
        {
            cout << val;
            val--;
        }

        // New line
        cout << endl;
    }
    return 0;
}