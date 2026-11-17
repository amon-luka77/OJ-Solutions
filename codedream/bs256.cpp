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
const ll N = 2e5;
ll n, a[N + 1], l[N + 1], r[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    stack<ll> left, right;

    for(ll i = 1; i <= n; i ++) {
        while(!left.empty() && a[left.top()] >= a[i]) left.pop();
        if(left.empty()) l[i] = 1;
        else l[i] = left.top() + 1;
        left.push(i);
    }

    for(ll i = n; i >= 1; i --) {
        while(!right.empty() && a[right.top()] >= a[i]) right.pop();
        if(right.empty()) r[i] = n;
        else r[i] = right.top() - 1;
        right.push(i);
    }

    ll ans = 0, left_n, right_n;

    for(ll i = 1; i <= n; i ++) {
        ll val = a[i] * (r[i] - l[i] + 1);
        if(ans < val) {
            ans = val;
            left_n = l[i];
            right_n = r[i];
        }
    }

    cout << ans << ' ' << left_n << ' ' << right_n;
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