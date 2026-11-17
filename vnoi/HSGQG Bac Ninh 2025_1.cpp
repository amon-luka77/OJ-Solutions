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
const ll N = 70000;
ll n, q, a[N + 1], block, cnt = 0, ans[N + 1], t[N + 1], check[N + 1];

void sang() {
    
    for(ll i = 2; i * i <= N; i ++) {
        if(check[i] == 0) {
            for(ll j = i * i; j <= N; j += i) {
                check[j] = i;
            }
        }
    }

    for(ll i = 1; i <= N; i ++) {
        if(check[i] == 0) check[i] = i;
    }
}

void add(ll k) {
    k = a[k];
    // 1 -> 0 cnt --;
    // 0 -> 1 cnt ++;
    while(k > 1) {
        ll l = check[k];
        t[l] ++;
        if(t[l] % 2) cnt ++;
        else cnt --;
        k /= l;
    }
}

void remove(ll k) {
    k = a[k];
    while(k > 1) {
        ll l = check[k];
        t[l] --;
        if(t[l] % 2) cnt ++;
        else cnt --;
        k /= l;
    }
}

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;

void read() {
    sang();

    cin >> n >> q;
    block = sqrt(n) + 1;

    for(ll i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        l --, r --;
        query.pb({l, r, i});
    }

    sort(all(query), [](QUERY &x, QUERY &y) {
        ll rx = x.x / block, ry = y.x / block;
        if(rx != ry) return rx < ry;
        else {
            if(rx % 2) return x.y < y.y;
            else return x.y > y.y;
        }
    });
}

void solve() {
    ll cur_l = 0, cur_r = -1;

    for(auto [i, j, k] : query) {

        while(cur_l > i) add(-- cur_l);
        while(cur_l < i) remove(cur_l ++);
        while(cur_r > j) remove(cur_r --);
        while(cur_r < j) add(++ cur_r);

        ans[k] = (cnt > 0);
    }

    for(ll i = 1; i <= q; i ++) {
        if(ans[i] == 0) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

void write() {

}

int main() {
    boost;
    file("SEQCP");
    read();
    solve();
    write();
    return 0;
}