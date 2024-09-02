#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> E;

    Graph(int v, vector<pair<int, int>> vec) : V(v) {
        E.resize(V);
        for(auto i:vec) {
            E[i.first].push_back(i.second);
        }
    }

    void BFS() {
        queue<int> q;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {

            if(!vis[i]) q.push(i);
            else continue;

            vis[i] = true;

            while(!q.empty()) {
                int cur = q.front();
                vis[cur] = true;
                for(auto e:E[cur]) if(!vis[e]) q.push(e);
                q.pop();
            }
        }
    }
};

int main() {
    vector<pair<int, int>> vec = {{1, 3}, {1, 2}, {2, 6}, {2, 4}, {2, 5}};
    
    Graph G(7, vec);

    G.BFS();

    return 0;
}