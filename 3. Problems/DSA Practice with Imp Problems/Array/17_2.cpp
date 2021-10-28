
//Maximize the profit can buy and  sell multiple time

#include <iostream>
using namespace std;

int stockProfit(int *arr, int start, int end)
{
    {
        if (start > end)
        {
            return 0;
        }

        int profit = 0;
        for (int i = start; i < end; i++)
        {
            for (int j = i + 1; j <= end; j++)
            {
                if (arr[j] > arr[i])
                {
                    int currProfit = arr[j] - arr[i] + stockProfit(arr, start, i - 1) +stockProfit(arr, j + 1, end); 
                    profit = max(profit, currProfit);
                }
            }
        }

        return profit;
    }
}

int main()
{

    int arr[] = {40, 100, 120, 20, 400, 340, 420};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << stockProfit(arr, 0, n - 1);

    return 0;
}