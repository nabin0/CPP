// Fibonacci sequence
#include<iostream>
using namespace std;

int main(){
int n, a=0,b=1,sum;
cin>>n;
for (int i = 0; i < n; i++)
{
    cout<<a<< " ";
    int temp = b;
    sum = a+b;
    a = temp;
    b = sum;
}

return 0;
}




/*
Problem Name: Fibonacci Pattern (Pattern 4)
Problem Difficulty: None
Problem Constraints: 0 < N < 100
Problem Description:
Take N (number of rows), print the following pattern (for N = 4)  
0  
1    1  
2    3    5  
8   13  21  34
Input Format: 
Sample Input: 4
Output Format: 
Sample Output:
0 
1    1 
2    3     5 
8   13    21    34
*/


// Solution
/*

#include <iostream>
using namespace std;

int main()
{

    int a = 0, b = 1, sum, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << a << " ";
            int temp = b;
            sum = a + b;
            b = sum;
            a = temp;
        }
        cout << endl;
    }

    return 0;
}

*/