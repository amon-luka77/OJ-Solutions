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
const ll N = 0;
ll a, b, k;
void read() {
    cin >> a >> b >> k;
}
void solve() {
    ll left_2 = sqrt(a), right_2 = sqrt(b);
    if(left_2 * left_2 < a) left_2++;

    ll left_3 = cbrt(a), right_3 = cbrt(b);
    if(left_3 * left_3 * left_3 < a) left_3++;

    ll cnt = 0;

    for(ll y = left_3; y <= right_3; y++) {
        ll y3 = y * y * y;

        ll L = max(a, y3 - k);
        ll R = min(b, y3 + k);

        if(L > R) continue;

        ll l = sqrt(L), r = sqrt(R);
        if(l * l < L) l++;
        if(r * r > R) r--;

        if(l <= r) cnt += (r - l + 1);
    }

    cout << cnt;
}
void write() {

}
int main() {
    boost;
    file("capso");
    read();
    solve();
    write();
    return 0;
}