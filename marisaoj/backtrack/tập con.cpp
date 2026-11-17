#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
ll a[25];
void back(ll pos, ll last) {
    for(ll i = last + 1; i <= n; i ++) {
        a[pos] = i;
        if(pos == k) {
            for(ll j = 1; j <= k; j ++) {
                cout << a[j] << ' ';
            }
            cout << "\n";
        } else {
            back(pos + 1, i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    back(1, 0);
}