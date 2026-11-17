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
const ll N = 2e5;
ll n, q, parent[N + 1], sz[N + 1];
ll ans = 0;

struct RB {
    ll u, v, united, ss;
};

stack<RB> history;

void read() {
    cin >> n >> q;
}

void make_set() {
    ans = n;

    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k];
}

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        
        ans --;
        history.push({x, y, 1, sz[x]});
        parent[y] = x;
        sz[x] += sz[y]; 
    }
}

void save_rollback() {
    history.push({-1, -1, 0, -1});
}

void rollback() {
    while(!history.empty() && history.top().united == 1) {
        auto [i, j, z, t] = history.top();
        history.pop();

        ans ++;
        parent[j] = j;
        sz[i] = t;
    }

    history.pop();
}

void solve() {
    make_set();

    for(ll i = 1; i <= q; i ++) {
        string s; ll l, r;
        cin >> s;

        if(s == "union") {
            cin >> l >> r;
            union_set(l, r);

            cout << ans << el;
        } else if(s == "persist") {
            save_rollback();
        } else {
            rollback();

            cout << ans << el;
        }
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