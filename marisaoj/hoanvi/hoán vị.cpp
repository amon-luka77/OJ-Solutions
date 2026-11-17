#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[15];
map<ll, ll> ts;
void backtrack(ll pos) {
    if(pos == n + 1) {
        for(ll i = 1; i <= n; i ++) {
            cout << a[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(ll i = 1; i <= n; i ++) {
        if(ts[i] > 0) continue;
        else {
            ts[i] ++;
            a[pos] = i;
            backtrack(pos + 1);
            a[pos] -= i;
            ts[i] --;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtrack(1);
}