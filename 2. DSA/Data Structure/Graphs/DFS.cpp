#include<iostream>
#include<vector>

const int N = 1e5+10;
std::vector<int> v[N];
bool vis[N];

void dfs(int vertex){
    std::cout << vertex << ' ';

    /*Take action on the vertix before entering the vertex : make it visited
    */
    vis[vertex] =  true;
    for(int child : v[vertex]){
        /*
        Take action in the child before entering in the child. Check if child is already visited
        */
        // std::cout << "par " << vertex << " child "<< child << std::endl;
        if(vis[child]) continue;
        dfs(child);
        /*
        Take  action on the child before exiting the Child
        */
    }
    /*
    Take action on vertex before exiting the child.
    */
}

int main(){
/*
Input: 
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6

output :
1 3 5 6 2 4
*/
    int n, m;
    std::cin >> n>>m;
    for(int i = 0; i < m; i++){
        int v1,v2;
        std::cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    dfs(1);
    return 0;
}