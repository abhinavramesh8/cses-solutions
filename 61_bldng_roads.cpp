#include <iostream>
#include <vector>

using namespace std;

bool visited[100'010];
vector<int> adj[100'010];

void dfs(int s) {
    visited[s] = true;
    for (auto v: adj[s]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int a=0,b=0,i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    vector<int> components;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            components.push_back(i);
            dfs(i);
        }
    }
    int count = (int) components.size();
    cout << (count-1) << '\n';
    for (int i=0; i<count-1; i++) {
        cout << components[i] << ' ' << components[i+1] << '\n';
    }

    return 0;
}
