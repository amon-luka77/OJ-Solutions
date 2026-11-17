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
const ll N = 1e6;
ll a, b;
bool check[N + 1];
void sang() {
    for(ll i = 2; i <= N; i ++) {
        check[i] = true;
    }

    for(ll i = 2; i * i <= N; i ++) {
        if(check[i]) {
            for(ll j = i * i; j <= N; j += i) {
                check[j] = 0;
            }
        }
    }
}
void read() {
    cin >> a >> b;
}
void solve() {
    ll l = sqrt(a), r = sqrt(b);
    if(l * l != a) l ++;

    ll cnt = 0;

    for(ll i = l; i <= r; i ++) {
        if(check[i]) cnt ++;
    }

    cout << cnt;
}
void write() {

}
int main() {
    boost;
    //file();
    sang();
    read();
    solve();
    write();
    return 0;
}