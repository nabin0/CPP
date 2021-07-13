/*
Problem Name: Odd and Even back in Delhi
Problem Difficulty: 1
Problem Constraints: N<=1000
Car No >= 0 && Car No <=1000000000
Problem Description:
Due to an immense rise in Pollution, Kejriwal is back with the Odd and Even Rule in Delhi. The scheme is as follows, each car will be allowed to run on Sunday if the sum of digits which are even is divisible by 4 or sum of digits which are odd in that number is divisible by 3. However to check every car for the above criteria can't be done by the Delhi Police. You need to help Delhi Police by finding out if a car numbered N will be allowed to run on Sunday?
Input Format: The first line contains N , then N integers follow each denoting the number of the car.
Sample Input: 2
12345
12134
Output Format: N lines each denoting "Yes" or "No" depending upon whether that car will be allowed on Sunday or Not !
Sample Output: Yes
No
*/

#include <iostream>
using namespace std;

int main()
{

    // Number of numbers want to enter
    int num;
    cin >> num;

    // Number of car(in numberplate)
    long long int no[num];
    for (int i = 0; i < num; i++)
    {
        cin >> no[i];
    }

    for (int i = 0; i < num; i++)
    {
        int sum_even = 0, sum_odd = 0;

        while (no[i] != 0)
        {
            int t;
            t = no[i] % 10;
            if (t % 2 == 0)
            {
                sum_even += t;
            }
            else if (t % 2 == 1)
            {
                sum_odd += t;
            }
            no[i] = no[i] / 10;
        }

        if (sum_even % 4 == 0 || sum_odd % 3 == 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "no" << endl;
    }

    return 0;
}