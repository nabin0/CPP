// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

#include<iostream>
#include<unordered_map>
using namespace std;


#define M 4
#define N 5


void findCommonElement(int mat[M][N]){
    unordered_map<int, int> m;

    for(int j = 0; j < N; j++){
         m[mat[0][j]] = 1;
    }

    for(int i = 1; i < M; i++){
        for(int j = 0; j < N;j++){
            if(m[mat[i][j]] == i){
                m[mat[i][j]]++;

                if(i == M-1 && m[mat[i][j]] == M){
                cout << mat[i][j] << ' ';
            }
            }
        }
    }
}

int main(){
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    findCommonElement(mat);
    return 0;
}