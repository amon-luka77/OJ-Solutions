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
const ll N = 1e6;
ll n, q, block, cnt = 0, a[N + 1], ans[N + 1], blockCnt[N + 1];
vector<ll> b;

ll binary(ll k) {
    ll l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] <= k) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;

void read() {
    cin >> n >> q;
    block = sqrt(n);
    b.pb(0);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    for(ll i = 1; i <= n; i ++) {
        a[i] = binary(a[i]);
    }
    
    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        query.pb({l, r, i});
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
    blockCnt[a[k]] ++;
    if(blockCnt[a[k]] == 2) cnt ++;
    if(blockCnt[a[k]] == 3) cnt --;
}

void remove(ll k) {
    blockCnt[a[k]] --;
    if(blockCnt[a[k]] == 2) cnt ++;
    if(blockCnt[a[k]] == 1) cnt --;
}

void solve() {
    ll curL = 1, curR = 0;
    for(auto [i, j, k] : query) {
        while(curL > i) add(-- curL);
        while(curL < i) remove(curL ++);
        while(curR < j) add(++ curR);
        while(curR > j) remove(curR --);

        ans[k] = cnt;
    }

    for(ll i = 1; i <= q; i ++) cout << ans[i] << el;
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