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
ll n, m, block, a[N + 1], b[N + 1], ans[N + 1];

struct QUERY {
    ll x, y, z, t;
};

vector<QUERY> query;

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    block = sqrt(n);

    for(ll i = 1; i <= m; i ++) {
        ll x, l, r; cin >> l >> r >> x;
        query.pb({l, r, x, i});
    }

    sort(all(query), [](QUERY &x, QUERY &y) {
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
    b[a[k]] ++;
}

void remove(ll k) {
    b[a[k]] --;
}

void solve() {
    ll curL = 1, curR = 0;
    for(auto [i, j, k, l] : query) {

        while(curL > i) add(-- curL);
        while(curL < i) remove(curL ++);
        while(curR < j) add(++ curR);
        while(curR > j) remove(curR --);

        ans[l] = b[k];
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