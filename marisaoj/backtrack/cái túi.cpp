#include<bits/stdc++.h>
#define ll long long
#define ft first 
#define sc second
using namespace std;
ll n, S;
ll ans = 0;
ll gh = 0;
ll kg = 0;
vector<pair<ll, ll>> a(25, {0, 0});
void backtrack(ll pos) {
    for(ll i = pos; i <= n; i ++) {
        if(gh + a[i].ft <= S) {
            gh += a[i].ft;
            kg += a[i].sc;
            ans = max(ans, kg);
            backtrack(i + 1);
            gh -= a[i].ft;
            kg -= a[i].sc;
        } else continue;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> S;
    for(ll i = 1; i <= n; i ++) cin >> a[i].ft >> a[i].sc;
    backtrack(1);
    cout << ans;
}