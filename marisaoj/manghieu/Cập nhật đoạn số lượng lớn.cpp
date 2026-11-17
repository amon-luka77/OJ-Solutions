#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
using namespace std;
const ll N = 1e5;
ll n, q, m;
vector<pair<ll, ll>> amon;
ll mh1[N + 5], mh2[N + 5], luka[N + 5], cury[N + 5];
void chuanbi() {
    amon.push_back({0 ,0});
    cin >> n >> q >> m;
    for(ll i = 1; i <= q; i ++) {
        ll x, y;
        cin >> x >> y;
        amon.push_back({x, y});
    }
    for(ll i = 1; i <= m; i ++) {
        ll x, y;
        cin >> x >> y;
        mh2[x] ++;
        mh2[y + 1] --;
    }
    for(ll i = 1; i <= q; i ++) {
        cury[i] = cury[i - 1] + mh2[i];
    }
    for(ll i = 1; i <= q; i ++) {
        ll x = amon[i].ft, y = amon[i].sc;
        mh1[x] += cury[i];
        mh1[y + 1] -= cury[i];
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        luka[i] = luka[i - 1] + mh1[i];
    }
}
void in() {
    for(ll i = 1; i <= n; i ++) {
        cout << luka[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
}