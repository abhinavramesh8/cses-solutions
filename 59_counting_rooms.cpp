#include <utility>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    char s[1010];
    bool visited[n][m];
    for (int i=0; i<n; i++) {
        scanf(" %s", s);
        for (int j=0; j<m; j++) {
            visited[i][j] = (s[j] == '.' ? false : true);
        }
    }

    queue<pair<int, int> > q;
    int rooms = 0;
    for (int i = 0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(visited[i][j]) {
                continue;
            }
            rooms++;
            q.push(make_pair(i,j));
            visited[i][j] = true;
            while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                int curr_i = curr.first, curr_j = curr.second;
                if ((curr_i > 0) && !visited[curr_i-1][curr_j]) {
                    q.push(make_pair(curr_i-1, curr_j));
                    visited[curr_i-1][curr_j] = true;
                }
                if ((curr_j > 0) && !visited[curr_i][curr_j-1]) {
                    q.push(make_pair(curr_i, curr_j-1));
                    visited[curr_i][curr_j-1] = true;
                }
                if ((curr_i < n-1) && !visited[curr_i+1][curr_j]) {
                    q.push(make_pair(curr_i+1, curr_j));
                    visited[curr_i+1][curr_j] = true;
                }
                if ((curr_j < m-1) && !visited[curr_i][curr_j+1]) {
                    q.push(make_pair(curr_i, curr_j+1));
                    visited[curr_i][curr_j+1] = true;
                }
            }
        }
    }

    cout << rooms;
    return 0;
}
