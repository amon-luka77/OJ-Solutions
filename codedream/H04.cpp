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

const ll N = 3e5;
const ll Sz = 19;
ll node[Sz << 1];
ll n, q, a[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

NODE merge(NODE &x, NODE &y) {
    
}

void build() {
    FOR(i, 1, n) {
        node[i + Sz - 1].sum = a[i];
        node[i + Sz - 1].maxFirst = a[i];
        node[i + Sz - 1].maxSecond = a[i];
    }
    FORD(i, Sz - 1, 1) node[id] = merge(node[id << 1] + node[id << 1 | 1]);
}

ll getSum()

void solve() {
    build();
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