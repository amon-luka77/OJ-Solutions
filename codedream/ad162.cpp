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
const ll N = 50;
ll n;
bool mark[N + 1];
vector<pair<ll, ll>> edge[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        char x, y; ll z;
        cin >> x >> y >> z;
        if(x >= 'A' && x <= 'Z') {
            mark[x - 'A'] = 1;
        }

        x = tolower(x);
        y = tolower(y);

        edge[x - 'a'].pb({y - 'a', z});
        edge[y - 'a'].pb({x - 'a', z});
    }
}
void solve() {
    pair<ll, ll> ans = {0, 1e18};
    vector<ll> dis(27, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>> , greater<pair<ll, ll>>> pq;
    pq.push({0, 'z' - 'a'});
    dis['z' - 'a'] = 0;

    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.ft > dis[t.sc]) continue;

        for(auto i : edge[t.sc]) {
            if(dis[i.ft] > t.ft + i.sc) {
                dis[i.ft] = t.ft + i.sc;
                pq.push({dis[i.ft], i.ft});
            }
        }
    }

    for(ll i = 0; i <= 25; i ++) {
        if(mark[i]) {
            if(ans.sc > dis[i]) {
                ans = {i, dis[i]};
            }
        }
    }

    cout << char(ans.ft + 'A') << ' ' << ans.sc;
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