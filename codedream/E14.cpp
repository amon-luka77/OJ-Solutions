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
using namespace std;

const ll N = 5e4;
ll n, Q;
bool vs[101][N + 1];

void read() {
    cin >> n >> Q;
    FOR(i, 1, 100) vs[i][0] = 1;
}

void solve() {
    while(Q --) {
        ll x, y; cin >> x >> y;
        ll cnt = 0;
        FOR(i, 0, N - y) if(vs[x][i]) {
            vs[x][i + y] = 1;
        }
        // cout << 1 << el;

        FOR(i, 1, N) if(vs[x][i]) cnt ++;

        cout << cnt << el;
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