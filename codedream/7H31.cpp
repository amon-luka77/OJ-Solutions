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

const ll N = 1e5;
ll n, k, parent[N + 1], sz[N + 1], dp[N + 1][3];
vector<pair<ll, ll>> edge[N + 1];

struct CANH {
    ll id; vector<ll> w;
};

struct A {
    ll x, y, z;
};

vector<A> a;

vector<CANH> canh;

void read() {
    vector<ll> c;
    cin >> n >> k;
    FOR(i, 1, n) {
        FOR(j, 1, k) {ll x; cin >> x; c.pb(x);}
        canh.pb({i, c});
    }
}

void solve() {
    
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
