// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

#include<iostream>
#include<climits>
using namespace std;

#define N 5

int findMaxValue(int arr[][N]){
    int maxVal = INT_MIN;

    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N - 1; j++){
            for(int a = i + 1; a < N; a++){
                for(int b = j + 1; b < N; b++){
                    if(arr[a][b] - arr[i][j] > maxVal){
                        maxVal = arr[a][b] - arr[i][j];
                    }
                }
            }
        }
    }
    return maxVal;
}


int findMaxValOptimized(int arr[][N]){ //Using dp

    int dp[N][N];

    // Preprocess last row and column of the dp 
    dp[N-1][N-1] = arr[N-1][N-1];
    int maxVal = arr[N-1][N-1];

    for(int i = N - 2; i >= 0; i--){ // Preprocess last row
        if(arr[N-1][i] > maxVal)
            maxVal = arr[N-1][i];
        dp[N-1][i] = maxVal;
    }

    maxVal = arr[N-1][N-1];
    for(int i = N-2; i >= 0; i--){ // Preprocess the last column
        if(arr[i][N-1] > maxVal){
            maxVal = arr[i][N-1];
        }
        dp[i][N-1] = maxVal;
    }


    // Process rest of the matrix form bottom
    for(int i = N-2; i >= 0; i--){
        for(int j = N-2; j >= 0; j--){
            if(dp[i+1][j+1] - arr[i][j] > maxVal){
                maxVal = dp[i+1][j+1] - arr[i][j];
            }

            dp[i][j] = max(arr[i][j], max(dp[i][j+1], dp[i+1][j]));
        }
    }


    // --- Print Dp matrix 
    // for(int i = 0 ; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << dp[i][j] <<' ';
    //     }
    //     cout << endl;
    // }


    return maxVal;
}




int main(){


    int matrix[N][N]{
        { 1, 2, -1, -4, -20 },
        { -8, -3, 4, 2, 1 },
        { 3, 8, 6, 1, 3 },
        { -4, -1, 1, 7, -6 },
        { 0, -4, 10, -5, 1 }
    };

    

    int res = findMaxValue(matrix);
    cout << res << endl;
    res = findMaxValOptimized(matrix);
    cout << res<< endl;
    return 0;
}