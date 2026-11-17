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
ll n, q, block, a[N + 1], ans[N + 1], cnt[N + 1], sl = 0;

struct QUERY {
    ll fi, se, t;
};

vector<QUERY> query;
vector<ll> b;

ll binary(ll tg) {
    ll l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(b[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

void read() {
    cin >> n;

    block = sqrt(n) + 1;
    b.pb(-1);
    
    for(ll i = 0; i < n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    for(ll i = 0; i < n; i ++) {
        a[i] = binary(a[i]);
    }
}

void add(ll pos) {
    ll k = a[pos];

    if(cnt[k] == 0) sl ++;
    cnt[k] ++;
}

void remove(ll pos) {
    ll k = a[pos];

    if(cnt[k] == 1) sl --;
    cnt[k] --;
}

void solve() {
    cin >> q;

    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        query.pb({-- l,-- r, i});
    }

    sort(all(query), [](QUERY &x, QUERY &y) {
        ll rx = x.fi / block;
        ll ry = y.fi / block;

        if(rx != ry) return rx < ry;
        else {
            if(rx % 2) return x.se < y.se;
            return x.se > y.se;
        }
    });

    ll cur_l = 0, cur_r = -1;

    for(auto [i, j, t] : query) {
        
        while(cur_l < i) remove(cur_l ++);
        while(cur_l > i) add(-- cur_l);
        while(cur_r < j) add(++ cur_r);
        while(cur_r > j) remove(cur_r --);
        
        ans[t] = sl;

    }

    for(ll i = 1; i <= q; i++) {
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