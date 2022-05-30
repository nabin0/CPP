#include<iostream>
#include<vector>
#include<utility>
#include<set>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector< pair<int, int> > g[N]; // (node, dist) Graph list representation

void dijkstra(int source){
    vector<int> vis(N, 0); // To store visited node
    vector<int> dist(N, INF); //Store distance from source to the node

    set<pair<int, int>> st; // Can use priority queue

    st.insert({0, source}); // (distance, node)
    dist[source] = 0; 

    while(st.size() > 0){
        auto node = *st.begin(); // Get the min distance node from the source
        int vertex = node.second;
        int vertex_wt = node.first;
        
        st.erase(st.begin()); //Remove min distance node from pq

        // If that node is already visited it means its all child distance via that node is already calculated so continue
        if(vis[vertex]) continue; 

        // Make that node visited if not visited beacause all its child distance via that node will be calculated by below code
        vis[vertex] = 1;

        for(auto child : g[vertex]){ // Check if the distance of its child can be reduced via this node
            int child_vertex = child.first;
            int child_vertex_wt = child.second;

            if(dist[child_vertex] > dist[vertex] + child_vertex_wt){
                dist[child_vertex] = dist[vertex] + child_vertex_wt;
                st.insert({dist[child_vertex], child_vertex});
            }
        }
    }

    //Print distance from source (1) to node i
    for(int i = 0; i < dist.size(); i++){
        cout << "Dist from " << source << " to " << i << " is " << dist[i] << endl;
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from , to , wt;
        cin >> from >> to >> wt;

        g[from].push_back({to, wt});
    }
    
    dijkstra(1);
    return 0;
}


/*
Input 
5 7
1 2 1
1 3 3
1 4 1
2 5 4
3 5 6
4 3 2
4 5 2

Output
Dist from 1 to 1 is 0
Dist from 1 to 2 is 1
Dist from 1 to 3 is 3
Dist from 1 to 4 is 1
Dist from 1 to 5 is 3

*/