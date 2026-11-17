/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
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

const ll N = 1e5;
ll n, dp[N + 1];

struct AMON {
    ll x, y, z;
};

AMON a[N + 1];
vector<ll> b;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y, z; cin >> x >> y >> z;
        a[i] = {x, y, z};
        b.pb(y);
    }

    sort(all(b)); b.erase(unique(all(b)), b.end());

    FOR(i, 1, n) {
        a[i].y = lower_bound(all(b), a[i].y) - b.begin() + 1;
    }

    sort(a + 1, a + n + 1, [](const AMON &x, const AMON &y) {
        if(x.x != y.x) return x.x < y.x;
        else if(x.y != y.y) return x.y < y.y;
        return x.z > y.z;
    });
}

ll bit[N + 1];

void updated(ll i, ll val) {
    for(; i < b.size(); i += i & -i) bit[i] = max(bit[i], val);
}

ll getMax(ll i) {
    ll ans = 0;
    for(i; i >= 1; i -= i & -i) ans = max(ans, bit[i]);
    return ans;
}

void solve() {
    ll ans = 0;

    FOR(i, 1, n) {
        dp[i] = (a[i].z, getMax(a[i].y) + a[i].z);
        updated(a[i].y, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
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