#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3+10; // Maximum size that we can use for matrix representation
int graph[N][N];

int main(){

    // Input 
    // 4 7  -> 4 vertices and 7 edges
    // 1 2
    // 2 1
    // 2 3
    // 3 2
    // 4 3

    // Adjaccent matrix representation
    int n,m; // n == no of vertex and m = no of input edges
    cin>>n>>m;

    // int g[n+1][n+1]{};
    // for(int i = 0; i < m; i++){
    //     int u,v;
    //     cin >>u>>v;
    //     g[u][v] = 1;
    // }

    //Printing the graph
    // for(int i =1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << g[i][j] << ' ';
    //     }cout << endl;
    // }

    // Adjacent list representation
    vector<int> vec[N];

    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
    }

    for(auto it : vec){
        for(auto i : it){
            cout << i << ' ';
        }
        cout << endl;
    }
    
    return 0; 
}