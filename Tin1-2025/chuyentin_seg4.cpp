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
const ll N = 1e5;
ll n, k;
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    unordered_map<ll, ll> ts;
    for(ll i = 1; i <= n; i ++) {
        if(ts[b[i]] == 0) ts[b[i]] = i;
    }
    for(ll i = 1; i <= n; i ++) {
        a[i] = ts[a[i]];
    }
}
void solve() {
    SegmentTree node(n);
    for(ll i = 1; i <= n; i ++) {
        
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