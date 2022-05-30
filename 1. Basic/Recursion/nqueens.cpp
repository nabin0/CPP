#include<iostream>
#include<vector>
using namespace std;

bool isSafe(const vector<string> &board, int n, int row, int col){
    // Check left Up diagonal
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    //Check left side of the col
    row = duprow;
    col = dupcol;

    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    // Check down left diagonal

    row = duprow;
    col = dupcol;

    while(row <= n-1 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void nqueens(vector<vector<string>> &ans, vector<string> & board, int col, int n ){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int i = 0; i < n; i++){
        if(isSafe(board, n, i, col)){
            board[i][col] = 'Q';
            nqueens(ans, board, col + 1, n);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> queen_positions(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i = 0; i < n; i++) board[i] = s;
    nqueens(ans, board, 0, n);
    return ans;
}

void print(vector<vector<string>> & ans){
    for(auto v : ans){
        for(auto i : v){
            for(auto it : i){
                cout << it << ' ';
            }cout << endl;
        }cout << "\n\n";
    }
    
}

int main(){
    int n = 4;
    vector<vector<string>> ans = queen_positions(n);
    
    print(ans);
    return 0;
}