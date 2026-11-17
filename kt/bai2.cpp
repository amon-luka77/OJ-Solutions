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
ll n, a[N + 1], prefix[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    for(ll i = 1; i <= n; i ++) {
        if(prefix[i] == prefix[n] - prefix[i - 1]) {
            cout << i;
            exit(0);
        }
    }

    cout << -1;
}

void solve() {

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