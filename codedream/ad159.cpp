#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 250;
ll n, m, A, B, path[3][N + 1][60001];
bool dis[3][N + 1][60001];
vector<ll> edge[N + 1];
struct kk {
    ll role, dinh, kc;
};
void read() {
    cin >> n >> m >> A >> B;
    for(ll i = 1; i <= m; i ++) {
        ll u, v; cin >> u >> v;
        edge[u].pb(v);
    }
}

void trace(ll root, ll type,  ll k, ll le, vector<ll> &a) {
    ll t = k;
    while(le >= 0 && t > 0) {
        a.pb(t);
        t = path[type][t][le];
        le --;
    }
    reverse(a.begin(), a.end());
}

void solve() {
    queue<kk> q;
    q.push({0, A, 0});
    q.push({1, B, 0});
    dis[0][A][0] = 0;
    dis[1][B][0] = 0;
    while(!q.empty()) {
        auto t = q.front(); q.pop();
        for(auto i : edge[t.dinh]) {
            if(!dis[t.role][i][t.kc + 1]) {
                dis[t.role][i][t.kc + 1] = true;
                path[t.role][i][t.kc + 1] = t.dinh;
                q.push({t.role, i, t.kc + 1});
                if(dis[(t.role + 1) % 2][i][t.kc + 1]) {
                    vector<ll> ans1, ans2;
                    trace(A, 0, i, t.kc + 1, ans1);
                    trace(B, 1, i, t.kc + 1, ans2);
                    cout << ans1.size() - 1 << el;
                    for(auto j : ans1) {
                        cout << j << ' ';
                    }
                    cout << el;
                    for(auto j : ans2) {
                        cout << j << ' ';
                    }
                    exit(0);
                }
            }
        }
    }
}
void write() {
    cout << 77;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}