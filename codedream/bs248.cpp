#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1000;
ll n, X, Y, m, dp[N + 1][3], check[N + 5][3];
pair<ll, ll>  path[N + 1][3];
vector<pair<ll, ll>> edge[N + 5];
struct kk {
    ll x, y, h, root;
};
vector<kk> a;
bool cmp(kk x, kk y) {
    return x.h > y.h;
};
void read() {
    cin >> n >> X >> Y >> m;
    for(ll i = 1; i <= n; i ++) {
        ll x, y, h;
        cin >> x >> y >> h;
        if(h < Y) {
            a.pb({x, y, h, i});
        }
    }
}

void solve() {
    for(ll i = 0; i < n; i ++) {
        for(ll j = 0; j <= 1; j ++) {
            dp[i][j] = 1e18;
        }
    }
    memset(check, -1, sizeof(check));
    sort(a.begin(), a.end(), cmp);
    
    for(ll i = 0; i < a.size(); i ++) {
        for(ll j = i + 1; j < a.size(); j ++) {
            if(a[i].h - a[j].h <= m && a[i].x >= a[j].x && a[i].x <= a[j].y) {
                edge[j].pb({i, 0});
                if(check[i][0] == -1) {
                    check[i][0] = j;
                }
            }
            
            if(a[i].h - a[j].h <= m && a[i].y >= a[j].x && a[i].y <= a[j].y) {
                edge[j].pb({i, 1});
                if(check[i][1] == -1) {
                    check[i][1] = j;
                }
            }
            
        }
    }
    
    for(ll i = a.size() - 1; i >= 0; i --) {
        if(check[i][0] == -1 && a[i].h <= m) {
            dp[i][0] = a[i].h;
        }
        if(check[i][1] == -1 && a[i].h <= m) {
            dp[i][1] = a[i].h;
        }

        for(auto [j, role] : edge[i]) {
            if(check[j][role] != i) continue;
            ll t = 0;
            if(role == 0) t = a[j].x;
            else t = a[j].y;
            if(dp[j][role] > dp[i][0] + a[j].h - a[i].h + abs(t - a[i].x)) {
                dp[j][role] = dp[i][0] + a[j].h - a[i].h + abs(t - a[i].x);
                path[j][role] = {i, 0}; 
            }
            if(dp[j][role] > dp[i][1] + a[j].h - a[i].h + abs(t - a[i].y)) {
                dp[j][role] = dp[i][1] + a[j].h - a[i].h + abs(t - a[i].y);
                path[j][role] = {i, 1};
            }
        }
    }

    pair<ll, ll> kq;
    for(ll i = 0; i < a.size(); i ++) {
        if(X >= a[i].x && X <= a[i].y) {
            if(dp[i][0] + Y - a[i].h + abs(X - a[i].x) <= dp[i][1] + Y - a[i].h + abs(X - a[i].y)) {
                kq = {i, 0};
                cout << dp[i][0] + Y - a[i].h + abs(X - a[i].x) << el;
            } else {
                kq = {i, 1};
                cout << dp[i][1] + Y - a[i].h + abs(X - a[i].y) << el;
            }
            break;
        }
    }

    while(1) {
        cout << a[kq.ft].root << ' ' << kq.sc << el;;
        if(check[kq.ft][kq.sc] == -1) break;
        kq = path[kq.ft][kq.sc];
    }
}

void write() {
    
}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}
/*
0 10 13
0 10 8
4 14 3
*/