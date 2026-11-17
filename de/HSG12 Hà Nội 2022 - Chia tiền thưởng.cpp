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
const ll N = 500;
ll n, sum = 0, a[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
}
void solve() {
    for(ll i = sum / 2; i >= 1; i --) {
        
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