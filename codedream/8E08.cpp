#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define el "\n"
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
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

const ll N = 1000;
ll n, sumT = 0;
pair<ll, ll> a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {cin >> a[i].ft; sumT += a[i].ft;}
    FOR(i, 1, n) cin >> a[i].sc;
    sort(a + 1, a + n + 1, [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
       return x.sc < y.sc;
    });
}

ll dp[(ll)2e5 + 1][N + 1];
ll offSet = 1e5;

void solve() {

}


void write() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie();
//    file();
    read();
    solve();
    write();
    return 0;
}
