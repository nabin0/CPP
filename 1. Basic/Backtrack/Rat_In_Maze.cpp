#include <iostream>
using namespace std;

//Check weather the block is safe or not
bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratinMaze(int **arr, int x, int y, int n, int **resultArr)
{

    //Base condition will be different for different pattern

    if (x == n - 1 && y == n - 1)
    {
        resultArr[x][y] = 1;
        return true;
    }

    //Finf=ding path

    if (isSafe(arr, x, y, n))
    {
        resultArr[x][y] = 1;
        if (ratinMaze(arr, x + 1, y, n, resultArr)) //Move down right if condition is true i.e if we can move
        {
            return true;
        }
        if (ratinMaze(arr, x, y + 1, n, resultArr)) //Move right if it is safe
        {
            return true;
        }
        resultArr[x][y] = 0; //BackTraking
        return false;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    //Declaring dynamic 2-D array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    //taking input in 2-D array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //Declarig andInitialising resultArr for result path

    int **arrRes = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arrRes[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arrRes[i][j] = 0;
        }
    }

    //Invoking function
    if(ratinMaze(arr, 0, 0, n, arrRes)){
    //Printing REsult
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arrRes[i][j] << " ";
        }
        cout << endl;
    }
    }else{
        cout<<"Rat is trapped for forever..."<<endl;
    }
    return 0;
}

// 1 0 0 0 0
// 1 1 1 1 1
// 0 1 0 1 0
// 0 0 0 1 0
// 1 0 1 1 1

