#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
vector<ll> a(25, 0);
void backtrack(ll pos, ll sum, const vector<ll>& a) {
    for(ll i = pos; i <= n; i ++) {
        if(sum + a[i] > k) return;
        else if(sum + a[i] < k) backtrack(i + 1, sum + a[i], a);
        else {
            cout << "YES";
            exit(0);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    backtrack(1, 0, a);
    cout << "NO";
    return 0;
}