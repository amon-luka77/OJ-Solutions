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
const ll N = 1e5;
ll n, L, R, C, st, en, c[N + 1];
vector<ll> d = {-1, 1};
vector<ll> edge[N + 1];
struct NODE {
    ll dinh, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> L >> R >> C >> st >> en;
    for(ll i = 1; i <= n; i ++) {
        cin >> c[i];
        edge[c[i]].pb(i);
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    vector<ll> dis(n + 1, 1e18);
    pq.push({st, 0});
    dis[st] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;

        for(ll i = 0; i <= 1; i ++) {
            ll chiphi = (i == 0) * L + (i == 1) * R;
            ll k = t.dinh + d[i];
            if(k < 1 || k > n) continue;
            if(dis[k] > t.kc + chiphi) {
                dis[k] = t.kc + chiphi;
                pq.push({k, dis[k]});
            }
        }

        for(auto j : edge[c[t.dinh]]) {
            if(dis[j] > C + t.kc) {
                dis[j] = C + t.kc;
                pq.push({j, dis[j]});
            }
        }
    }

    cout << dis[en];
}
void write() {

}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}