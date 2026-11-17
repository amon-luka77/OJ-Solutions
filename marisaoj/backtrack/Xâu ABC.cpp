#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[15];
ll n;
void backtrack(ll pos, ll last) {
    for(ll i = 1; i <= 3; i ++) {
        if(i == last) continue;
        a[pos] = i;
        if(pos == n) {
            for(ll j = 1; j <= pos; j ++) cout << char(a[j] + 'A' - 1);
            cout << "\n";
        } else {
            backtrack(pos + 1, i);
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtrack(1, 0);
}