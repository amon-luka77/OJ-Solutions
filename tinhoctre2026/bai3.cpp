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
const ll N = 2000;
ll n, m, k;

void read() {
    cin >> m >> n >> k;
}

void solve() {
    if(m == k) {
        ll cnt = 1;
        ll x = n - k + 1;
        cnt += x;
        cout << cnt;
    } else if(n == k) {
        cout << 1 + m - k + 1;
    } else {
        cout << 1;
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