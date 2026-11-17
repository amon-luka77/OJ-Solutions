#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll cot[25];
map<ll, ll> cheochinh;
ll cheophu[25];
ll kq = 0;
void backtrack(ll pos) {
    for(ll j = 1; j <= n; j ++) {
        if((cheochinh[pos - j] > 0) || (cheophu[pos + j] > 0) || (cot[j] > 0)) continue;
        else {
            if(pos == n) {
                kq ++;
                return;
            }
            cheochinh[pos - j] ++;
            cheophu[pos + j] ++;
            cot[j] ++;
            backtrack(pos + 1);
            cheochinh[pos - j] --;
            cheophu[pos + j] --;
            cot[j] --;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtrack(1);
    cout << kq;
    return 0;
}