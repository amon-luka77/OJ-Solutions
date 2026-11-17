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
ll n, m, a;
void read() {
    cin >> n >> m >> a;
    n = (n + a - 1) / a;
    m = (m + a - 1) / a;
    cout << n * m;
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