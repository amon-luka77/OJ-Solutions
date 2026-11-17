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
const ll N = 3e5;
ll n, m, sum = 0, parent[N + 1], sz[N + 1], ans[N + 1];
vector<vector<pair<ll, ll>>> node;
void read() {
    cin >> n >> m;
}

void make_set() {
    sum = n;
    node.assign(4 * m + 1, vector<pair<ll, ll>>());
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    ll root = k;
    while(root != parent[root]) {
        root = parent[root];
    }

    return root;
}

struct HS {
    ll start_node, end_node, kk;
};

stack<HS> history;

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        history.push({x, y, sz[x]});
        parent[y] = x;
        sz[x] += sz[y];
        sum --;
    }
}

void updated(ll id, ll l, ll r, ll i, ll j, pair<ll, ll> t) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {
        node[id].pb(t);
        return;
    }

    ll mid = (l + r) >> 1;

    updated(id * 2, l, mid, i, j, t);
    updated(id * 2 + 1, mid + 1, r, i, j, t);
}

void get_set(ll id, ll l, ll r) {
    history.push({-1LL, 0LL, 0LL});

    for(auto &[i, j] : node[id]) {
        union_set(i, j);
    }

    if(l == r) {
        ans[l] = sum;
    } else {
        ll mid = (l + r) >> 1;
        get_set(id * 2, l, mid);
        get_set(id * 2 + 1, mid + 1, r);
    }

    while(history.top().start_node != -1) {
        auto [i, j, z] = history.top();
        history.pop();

        sum ++;
        parent[j] = j;
        sz[i] = z;
    }

    history.pop();
}

void solve() {
    make_set();
    vector<ll> query;
    map<pair<ll, ll>, ll> pos;

    for(ll i = 1; i <= m; i ++) {
        char s; ll x, y; cin >> s;

        if(s == '?') {
            query.pb(i);
        } else {
            cin >> x >> y;
            if(x > y) swap(x, y);
            if(s == '+') {
                pos[{x, y}] = i;
            } else {
                updated(1, 1, m, pos[{x, y}], i - 1, {x, y});
                pos[{x, y}] = 0;
            }
        }
    }

    for(auto [t, k] : pos) {
        if(k != 0) {
            updated(1, 1, m, k, m, t);
        }
    }

    get_set(1, 1, m);

    for(auto i : query) {
        cout << ans[i] << el;
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