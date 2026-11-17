/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 1e6, mod = 30013;
ll n;
vector<ll> nen;
pair<ll, ll> dp[(ll)1e5 + 1];

pair<ll, ll> node[4 * N + 1];

pair<ll, ll> merge(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.ft == y.ft) return {x.ft, (x.sc + y.sc) % mod};
    return max(x, y);
}

void updated(ll id, ll l, ll r, ll i, pair<ll, ll> val) {
    if(l == r) {
        if(node[id].ft == val.ft) node[id].sc = (node[id].sc + val.sc) % mod;
        else node[id] = max(node[id], val);

        return;
    }

    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id * 2, l, mid, i, val);
    else updated(id * 2 + 1, mid + 1, r, i, val);

    node[id] = merge(node[id * 2], node[id * 2 + 1]);
}

pair<ll, ll> getMax(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return {0, 0};
    if(i <= l && r <= j) return node[id];

    ll mid = (l + r) >> 1;

    return merge(getMax(id * 2, l, mid, i, j), getMax(id * 2 + 1, mid + 1, r, i, j));
}

struct ARRAY {
    ll a, b, c, d;
};

struct SUB2 {
    ll x, y, z, t, h;
};

vector<SUB2> AA;
vector<ARRAY> A;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y, z, t; cin >> x >> y >> z >> t;
        nen.pb(z);
        nen.pb(t);
        A.pb({x, y, z, t});
    }
}

void solve() {
    if(n <= 5e3) {    
        sort(all(A), [](const ARRAY &x, const ARRAY &y) {
            return make_pair(x.b, x.d) < make_pair(y.b, y.d);
        });

        pair<ll, ll> ans;

        FOR(i, 0, n - 1) {
            dp[i].ft = 1;
            dp[i].sc = 1;

            FOR(j, 0, i - 1) {
                if(A[i].a >= A[j].b && A[i].c >= A[j].d) {
                    if(dp[i].ft < dp[j].ft + 1) {
                        dp[i].ft = dp[j].ft + 1;
                        dp[i].sc = dp[j].sc;
                    } else if(dp[i].ft == dp[j].ft + 1) {
                        dp[i].sc = (dp[i].sc + dp[j].sc) % mod;
                    }
                }
            }

            ans = merge(ans, dp[i]);
        }

        cout << ans.ft << ' ' << ans.sc;
    } else {
        sort(all(nen));
        nen.erase(unique(all(nen)), nen.end());
        pair<ll, ll> ans;
        FOR(i, 0, n - 1) {
            auto &[a, b, c, d] = A[i];
            c = lower_bound(all(nen), c) - nen.begin() + 1;
            d = lower_bound(all(nen), d) - nen.begin() + 1;
            AA.pb({a, 1, i + 1, c, d});
            AA.pb({b, -1, i + 1, c, d});
        }

        sort(all(AA), [](const SUB2 &x, const SUB2 &y) {
            if(x.x != y.x) return x.x < y.x;
            return x.y > y.y;
        });

        for(auto &[u, type, i, c, d] : AA) {
            if(type > 0) {
                dp[i] = {1, 1};
                auto k = getMax(1, 1, N, 1, c); k.ft ++;
                dp[i] = merge(dp[i], k);

                ans = merge(ans, dp[i]);
            } else {
                updated(1, 1, N, d, dp[i]);
            }
        }

        cout << ans.ft << ' ' << ans.sc;
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

/*
1 1
1 1
2 2
1 1
2 3
2 3
3 8
*/