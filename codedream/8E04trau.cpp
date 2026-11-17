#include<bits/stdc++.h>
#define ft first
#define sc second
#define pb push_back
#define el "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 0;
ll n, m, k;

void read() {
    cin >> n >> m >> k;
    a.assign(n + 1, vector<ll>(m + 1, 0));
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
}


void solve() {

}

void write() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    file();
    read();
    solve();
    write();
    return 0;
}
