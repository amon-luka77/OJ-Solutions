#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out1", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()JetBrainsMono Nerd Font
using namespace std;
const ll N = 1e6;
ll n, cnt = 0, q, block, a[N + 1], ans[N + 1], blockDiff[N + 1];

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;

void read() {
    cin >> n;
    block = sqrt(n);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    cin >> q;
    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        query.pb({l, r, i});
    }

    sort(all(query), [](QUERY &x, QUERY &y){
        ll rx = x.x / block;
        ll ry = y.x / block;

        if(rx != ry) return rx < ry;
        else {
            if(rx % 2) return x.y < y.y;
            return x.y > y.y;
        }
    });
}

void add(ll k) {
    blockDiff[a[k]] ++;
    if(blockDiff[a[k]] == 1) cnt ++;
}

void remove(ll k) {
    blockDiff[a[k]] --;
    if(blockDiff[a[k]] == 0) cnt --;
}

void solve() {
    ll curL = 0, curR = -1;
    for(auto [i, j, t] : query) {

        while(curL > i) add(-- curL);
        while(curL < i) remove(curL ++);
        while(curR > j) remove(curR --);
        while(curR < j) add(++ curR);

        ans[t] = cnt;
    }

    for(ll i = 1; i <= q; i ++) {
        cout << ans[i] << el;
    }
}

void write() {

}

int main() {
    boost;
    // file();
    read();
    solve();
    write();
    return 0;
}