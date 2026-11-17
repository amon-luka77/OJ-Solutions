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

const ll N = 1e6;
ll n, a[2 * N + 1], maxPos[2 * N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {cin >> a[i]; a[i + n] = a[i];}
}

ll bit[2 * N + 1];

void updated(ll i, ll val) {
    for(; i <= 2 * n; i += i & -i) bit[i] += val;
}

ll get(ll i) {
    ll res = 0; for(; i >= 1; i -= i & -i) res += bit[i];
    return res;
}

void solve() {
    stack<ll> st;
    FOR(i, 1, 2 * n) {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        if(st.empty()) maxPos[i] = 1;
        else maxPos[i] = st.top() + 1;
        st.push(i);
    }

//    FOR(i, 1, 2 * n) cerr << maxPos[i] << ' ';
//    cerr << el;

    ll ans = 0;
    FOR(i, 1, n - 1) updated(maxPos[i], 1);

    FOR(i, 1, n) {
        ll j = i + n - 1;
        updated(maxPos[j], 1);
        ans = max(ans, get(i));
        updated(maxPos[i], -1);
    } cout << ans;
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
