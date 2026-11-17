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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e4;
ll n, w, a[N + 1];

void read() {
    cin >> n >> w;
    FOR(i, 1, n) cin >> a[i];
}

ll cnt = 0;

void solve() {
    FOR(i, 1, n) FOR(j, i + 1, n) if(a[i] < a[j]) FOR(k, j + 1, n) if(a[j] < a[k]) {
        cnt += (a[i] + a[j] + a[k] <= w);
    }

    cout << cnt;
}

void write() {

}

int main() {
    boost;
    file("7E15");
    read();
    solve();
    write();
    return 0;
}