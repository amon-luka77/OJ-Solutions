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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, w, h;
vector<pair<ll, ll>> a;

void read() {
    cin >> n >> h >> w;
    FOR(i, 1, n) {
        ll x, y; cin >> x >> y;
        a.pb({x, y});
    }
}

map<ll, ll> diff;

void solve() {
    for(auto &[i, j] : a) {
        ll startTime = (j <= w ? 1 : 1 + j - w);
        ll endTime = min(startTime + min(j, w) - 1, h - w + 1); ll len = endTime - startTime + 1;
//        cerr << "[" << i << ", " << j << "]: " << startTime << ' ' << endTime << el;

        if(startTime <= i && i <= endTime) {diff[1] ++; diff[1 + i - startTime + 1] --;}
        if(endTime < i) {diff[i - endTime + 1] ++; diff[i - endTime + 1 + len] --;}
    }

    ll maxTime = 0, sum = 0;
    for(auto &[i, j] : diff) {
         sum += j; maxTime = max(maxTime, sum);
    } cout << maxTime;
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
