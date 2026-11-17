#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k;
ll A[15];
ll sum[15];
ll vt[15];
void backtrack(ll pos, ll target) {
    for(ll i = 1; i <= k; i ++) {
        if(sum[i] + A[pos] <= target) {
            sum[i] += A[pos];
            vt[pos] = i;
            if(pos == n) {
                for(ll j = 1; j <= k; j ++) {
                    if(sum[j] != target) return;
                }
                for(ll j = 1; j <= n; j ++) {
                    cout << vt[j] << ' ';
                }
                exit(0);
            }
            backtrack(pos + 1, target);
            sum[i] -= A[pos];
        } else continue;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    ll target = 0;
    for(ll i = 1; i <= n; i ++) {
        cin >> A[i];
        target += A[i];
    }
    if(target % k != 0) {
        cout << "ze";
        return 0;
    }
    target /= k;
    backtrack(1, target);
    cout << "ze";
}