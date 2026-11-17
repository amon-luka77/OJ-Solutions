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
ll n, m, k, prefix[N + 1], a[N + 1], pos[N + 1];
vector<ll> b;

ll binary(ll tg) {
    ll l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(b[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r= mid - 1;
        }
    }

    return ans;
}


void read() {
    cin >> n >> k;
    b.pb(0);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        b.pb(prefix[i]);
    }
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    for(ll i = 1; i <= n; i ++) {
        pos[i] = binary(prefix[i]);
    }

    m = b.size() - 1;
}

struct FenwickTree {
    vector<ll> bit;

    FenwickTree(ll n) {
        bit.assign(n + 1, 0);
    }

    void updated(ll i, ll val) {
        for(; i <= m; i += i & -i) bit[i] += val; 
    }

    ll get(ll i) {
        ll res = 0;

        for(; i >= 1; i -= i & -i) res += bit[i];

        return res;
    }
};

bool check(ll tg) {
    // prefix[r] - prefix[l] >= tg;
    // prefix[l] <= prefix[r] - tg;

    FenwickTree bit(m);
    ll cnt = 0;

    for(ll i = 1; i <= n; i ++) {
        cnt += bit.get(binary(prefix[i] - tg));
        if(prefix[i] - tg >= 0) cnt ++;
        bit.updated(pos[i], 1);
    }

    return cnt >= k;
}

void solve() {
    ll l = -1e18, r = 1e18, ans = 0;

    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
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