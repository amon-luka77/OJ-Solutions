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
const ll N = 1e3;
ll k;
struct coin {
    ll z, s, m;
    bool operator < (const coin &other) const {
        if(z != other.z) return z < other.z;
        if(s != other.s) return s < other.s;
        return m < other.m;
    }
};
coin aim, root, nhap1, nhap2;
vector<pair<coin, coin>> a;
map<coin, ll> dis;
void read() {
    cin >> k >> root.z >> root.s >> root.m;
    cin  >> aim.z >> aim.s >> aim.m;
    while(cin >> nhap1.z >> nhap1.s >> nhap1.m >> nhap2.z >> nhap2.s >> nhap2.m) {
        a.pb({nhap1, nhap2});
    }
}

void solve() {
    queue<pair<coin, ll>> q;
    q.push({root, 0});
    dis[root] = 0;
    map<coin, ll> ans;
    while(!q.empty()) {
        coin t = q.front().ft;
        ll sl = q.front().sc;
        q.pop();
        if(t.z >= aim.z && t.s >= aim.s && t.m >= aim.m) {
            if(ans.find(t) == ans.end()) ans[t] = sl;
            else ans[t] = min(sl, ans[t]);
            continue;
        }
        if(sl >= k) continue;
        for(auto i : a) {
            auto fi = i.ft, se = i.sc;
            if(t.z >= fi.z && t.s >= fi.s && t.m >= fi.m) {
                coin l;
                l.z = min(t.z - fi.z + se.z, 4LL);
                l.s = min(t.s - fi.s + se.s, 4LL);
                l.m = min(t.m - fi.m + se.m, 4LL);
                if(dis.find(l) == dis.end() || dis[l] > sl + 1) {
                    dis[l] = sl + 1;
                    q.push({l, dis[l]});
                }
            }
        }
    }
    if(ans.size() == 0) {
        cout << -1;
        exit(0);
    }
    cout << ans.size() << el;
    for(auto i : ans) {
        cout << i.ft.z << ' ' << i.ft.s << ' ' << i.ft.m << ' ' << i.sc << el;
    }
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
