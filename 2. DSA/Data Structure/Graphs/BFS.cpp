#include<iostream>
#include<vector>
#include<queue>

const int N = 1e5+10;
std::vector<int> v[N];
bool vis[N];
int level[N];

void bfs(int source){
    std::queue<int> q;
    q.push(source);
    vis[source] = true;
    while(!q.empty()){
        int curr_vertex = q.front();
        std::cout << curr_vertex << ' ';
        q.pop();
        for(int child : v[curr_vertex]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[curr_vertex] +1;
            }
        }
    }
    std::cout  << std::endl;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v1,v2;
        std::cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    bfs(1);

    for(int i = 1; i <= n; i++){
        std::cout << "level: " << level[i] << ' ' << i << std::endl;
    }
    return 0;
}