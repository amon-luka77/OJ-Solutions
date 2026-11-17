#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
ll a[25];
map<ll, ll> ts;
void back(ll pos) {
    for(ll i = 1; i <= k; i ++) {
        if(ts[i] > 0) continue;
        else a[pos] = i;
        if(pos == n) {
            for(ll j = 1; j <= n; j ++) {
                cout << a[j] << ' ';
            }
            cout << "\n";
        } else {
            ts[i] ++;
            back(pos + 1);
            ts[i] --;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    back(1);
}