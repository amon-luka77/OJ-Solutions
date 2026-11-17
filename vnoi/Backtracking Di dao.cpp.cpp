#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
using namespace std;

const ll N = 50;
ll n, k, ans = 1e18, a[N + 1][N + 1];
string kq;
vector<pair<ll, ll>> edge[N + 1];
bool vs[N + 1];

void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            cin >> a[i][j];
            edge[i].pb({j, a[i][j]});
        }
    }
}

void backtrack(ll u, ll sum, string &trace) {
    if(sum > ans) return;
    if(trace.size() == k) {
        if(ans > sum + a[trace.back() - '0'][1]) {
            ans = sum + a[trace.back() - '0'][1];
            kq = trace;
        }
        return;
    }

    for(auto [i, j] : edge[u]) {
        if(!vs[i]) {
            vs[i] = 1;
            trace.pb(char(i + '0'));
            backtrack(i, sum + j, trace);
            trace.erase(trace.size() - 1, 1);
            vs[i] = 0;
        }
    }
}

void solve() {
    string trace = "1";
    vs[1] = 1;
    backtrack(1, 0, trace);
}

void write() {
    cout << ans << "\n";
    for(auto i : kq) {
        cout << i - '0' << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("vnoi.inp", "r", stdin);
//    freopen("vnoi.out", "w", stdout);
    read();
    solve();
    write();
    return 0;
}
