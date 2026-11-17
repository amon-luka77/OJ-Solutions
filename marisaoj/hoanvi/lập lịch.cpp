#include<bits/stdc++.h>
#define ll long long
#define ft first 
#define sc second
using namespace std;
ll n;
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.sc > b.sc;
}
vector<pair<ll, ll>> a(15, {0, 0}), x, y;
map<ll, ll> ts;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i].ft >> a[i].sc;
        if(a[i].ft < a[i].sc) x.push_back({a[i].ft, a[i].sc});
        else y.push_back({a[i].ft, a[i].sc});
    }
    sort(x.begin(), x.end()); sort(y.begin(), y.end(), cmp);
    ll t1 = 0, t2 = 0;
    for(ll i = 0; i < x.size(); i ++) {
        t1 += x[i].ft;
        t2 = max(t1, t2) + x[i].sc;
    }
    for(ll i = 0; i < y.size(); i ++) {
        t1 += y[i].ft;
        t2 = max(t1, t2) + y[i].sc;
    }
    cout << t2;
}