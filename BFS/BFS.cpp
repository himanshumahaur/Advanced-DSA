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
        cout << "BFS: ";

        queue<int> q;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {

            if(!vis[i]) q.push(i);
            else continue;

            vis[i] = true;

            while(!q.empty()) {
                int cur = q.front();

                cout << cur << " ";
            
                vis[cur] = true;
                for(auto e:E[cur]) if(!vis[e]) q.push(e);
                q.pop();
            }
        }

        cout << endl;
    }

    void DFS(int cur, vector<bool> &vis) {
        if(vis[cur]) return;
        else vis[cur] = 1;

        cout << cur << " ";

        for(auto e:E[cur]) DFS(e, vis);
    }

    void DFS() {
        cout << "DFS: ";
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) DFS(i, vis);
        cout << endl;
    }
};

int main() {
    vector<pair<int, int>> vec = {{1, 2}, {1, 5}, {2, 4}, {4, 3}};
    
    Graph G(7, vec);

    G.BFS();
    G.DFS();

    return 0;
}