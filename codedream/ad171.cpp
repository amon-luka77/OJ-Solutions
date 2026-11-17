#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ft first
#define sc second
using namespace std;
const ll N = 5000;
ll n, m, d[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    for(ll i = 1; i <= n; i ++) {
        d[i] = 1e18;
    }
}

void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    d[1] = 0;
    while(!pq.empty()) {
        auto [dis, u] = pq.top();
        pq.pop();

        if(dis > d[u]) continue;

        for(auto i : edge[u]) {
            ll chuki = abs(i - u);
            ll type = (dis / 5) / chuki;
            ll dis_i = dis;
            if(type % 2 == 0) {
                // thang di len
                // dinh luc di
                ll dinh = min(i, u) + (dis / 5) % chuki;
                if(i < u) {
                    // i --- dinh --- u
                    dis_i += chuki * 5 + (u - dinh) * 5;
                }
                else {
                    // u --- dinh --- i
                    if(u != dinh) dis_i += (i - dinh) * 5 + 10 * chuki;
                    else dis_i += chuki * 5;
                }
            }
            else {
                // thang di xuong
                // dinh luc di
                ll dinh = max(i, u) - (dis / 5) % chuki;
                if(i < u) {
                    // i --- dinh --- u
                    if(u != dinh) dis_i += (dinh - i) * 5 + 10 * chuki;
                    else dis_i += chuki * 5;
                }
                else {
                    // u --- dinh --- i
                    dis_i += chuki * 5 + (dinh - u) * 5;
                }
            }
            if(d[i] > dis_i) {
                d[i] = dis_i;
                pq.push({d[i], i});
            }
        }
    }

    cout << d[n];
}

void write() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    read();
    solve();
    write();
    return 0;
}
