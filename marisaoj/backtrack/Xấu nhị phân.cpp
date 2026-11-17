#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[15];
ll n;
void backtrack(ll pos) {
    for(ll i = 0; i <= 1; i ++) {
        a[pos] = i;
        if(pos == n) {
            for(ll j = 1; j <= pos; j ++) cout << a[j];
            cout << "\n";
        } else {
            backtrack(pos + 1);
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtrack(1);
}