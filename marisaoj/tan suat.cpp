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
ll n, m, a[N + 1], ans[N + 1];
ll cnt[N + 1], freq[N + 1];
ll block = 0;

struct QUERY {
    ll fi, se, z, t;
};

vector<QUERY> query;

void read() {
    cin >> n >> m;

    block = sqrt(n) + 1;

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}

void add(ll k) {
    if(cnt[a[k]] > 0) freq[cnt[a[k]]] --;
    cnt[a[k]] ++;
    freq[cnt[a[k]]] ++;
}

void remove(ll k) {
    freq[cnt[a[k]]] --;
    cnt[a[k]] --;
    if(cnt[a[k]] > 0) freq[cnt[a[k]]] ++;
}

void solve() {
    for(ll i = 1; i <= m; i ++) {
        ll l, r, x; cin >> l >> r >> x;
        query.pb({l, r, x, i});
    }

    sort(all(query), [](QUERY &x, QUERY &y) {
        ll rx = x.fi / block;
        ll ry = y.fi / block;
        if(rx != ry) {
            return rx < ry;
        } else {
            if(rx % 2) return x.se < y.se;
            return x.se > y.se;
        }
    });

    ll curx = 0, cury = 0;

    for(auto [i, j, z, t] : query) {

        while(curx < i) remove(curx ++);
        while(curx > i) add(-- curx);
        while(cury < j) add(++ cury);
        while(cury > j) remove(cury --);
        
        ans[t] = freq[z];
    }

    for(ll i = 1; i <= m; i ++) {
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