#include <iostream>
using namespace std;

int stockProfit(int *arr, int start, int end)
{
    {
        if (start >= end)
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
                    int left = stockProfit(arr, start, i - 1);
                    int right = stockProfit(arr, j + 1, end);
                    int currProfit = arr[j] - arr[i] +left +right;
                    profit = max(profit, currProfit);
                    cout<<"i : "<<i<<"   j: "<<j<<"   left: "<<left<<"   right: "<<right<<"   curr: "<<currProfit<< "   profit: "<<profit<<endl;
                }
            }
            cout<<endl<<endl;
        }

        return profit;
    }
}

int main()
{

    int arr[] = {40, 110, 80,160};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = stockProfit(arr, 0, n - 1);

    cout <<"profit : "<< p;

    return 0;
}