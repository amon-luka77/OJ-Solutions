#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, vector<ll>> amon;
ll n, l, r, q, x, A;
void chuanbi() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> A;
        amon[A].push_back(i);
    }
}
ll binary_right(const vector<ll>& nam, ll thao) {
    ll l = 0, r = nam.size() - 1;
    ll m = l + (r - l) / 2;
    if(thao < nam[l]) return -77;
    ll yeu = 0;
    while(l <= r) {
        if(nam[m] <= thao) {
            yeu = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
        m = l + (r - l) / 2;
    }
    return yeu;
}
ll binary_left(const vector<ll>& nam, ll thao) {
    ll l = 0, r = nam.size() - 1;
    ll m = l + (r - l) / 2;
    if(thao > nam[r]) return -77;
    ll yeu = 0;
    while(l <= r) {
        if(nam[m] >= thao) {
            yeu = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
        m = l + (r - l) / 2;
    }
    return yeu;
}
void solve() {
    while(q--) {
        cin >> l >> r >> x;
        if(amon[x].empty()) cout << 0 << "\n";
        else {
            ll namthao = binary_left(amon[x], l);
            ll thaonam = binary_right(amon[x], r);
            if((namthao == -77) || (thaonam == -77)) cout << 0 << "\n";
            else cout << thaonam - namthao + 1 << "\n";
        }
    }
}
void in() {
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
}