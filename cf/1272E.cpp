#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 2e5;
int n, a[N + 1];
int ans[N + 1];

vector<int> edge[N + 1];

void bfs(const vector<int> &start, const vector<int> &end) {
    vector<int> d(n + 1, 1e9);
    queue<pair<int, int>> q;
    for(auto i : start) {
        d[i] = 0;
        q.push({i, 0});
    }

    while(!q.empty()) {
        auto [u, dis] = q.front(); q.pop();

        for(auto v : edge[u]) if(d[v] == 1e9) {
            d[v] = dis + 1;
            q.push({v, d[v]});
        }
    }

    for(auto i : end) ans[i] = d[i];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i], ans[i] = 1e9;

    FOR(i, 1, n) {
        if(i - a[i] >= 1) edge[i - a[i]].push_back(i);
        if(i + a[i] <= n) edge[i + a[i]].push_back(i);
    }

    vector<int> odd, even;
    
    FOR(i, 1, n) {
        if(a[i] % 2) odd.push_back(i);
        else even.push_back(i);
    }

    bfs(odd, even); bfs(even, odd);

    FOR(i, 1, n) cout << (ans[i] == 1e9 ? -1 : ans[i]) << ' ';
}