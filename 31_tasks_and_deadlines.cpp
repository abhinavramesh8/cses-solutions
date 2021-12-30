#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    pair<int, int> tasks[n];
    for (int i=0; i<n; i++) {
        scanf("%d %d", &tasks[i].first, &tasks[i].second);
    }

    sort(tasks, tasks+n);
    ll end_time = 0;
    ll reward = 0;
    for (auto &[duration, deadline] : tasks) {
        end_time += duration;
        reward += (deadline - end_time);
    }

    printf("%lld", reward);
    return 0;    
}