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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5, block = 350;
ll n, q, deg[N + 1], lazy[N + 1], val[N + 1];
vector<ll> edge[N + 1], heavy[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        deg[x] ++; deg[y] ++;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    FOR(i, 1, n) for(auto j : edge[i]) if(deg[j] >= block) {
        heavy[i].pb(j);
    } 
}

void solve() {
    FOR(i, 1, q) {
        ll x, l, r; cin >> x >> l;
        if(x == 1) {
            cin >> r;
            if(deg[l] >= block) lazy[l] += r;
            else {
                for(auto j : edge[l]) val[j] += r;
            } 
        } else {
            ll ans = val[l];
            for(auto j : heavy[l]) ans += lazy[j];
            cout << ans << el;
        }
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