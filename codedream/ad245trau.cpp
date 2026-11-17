/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e6;
ll n; bool vs[N + 1];
vector<pair<string, ll>> a;

void read() {
    cin >> n;
    FOR(i, 1, 2 * n) vs[i] = 1;
    a.pb({"0", 0});
    FOR(i, 1, 2 * n) {
        string s; cin >> s;
        a.pb({s, i});
    }
    sort(a.begin() + 1, a.end(), [](const pair<string, ll> &x, const pair<string, ll> &y) {
        return x.ft.size() < y.ft.size();
    });

    vector<pair<ll, ll>> ans;

    FOR(i, 1, 2 * n) {
        FOR(j, 1, i - 1) if(vs[a[j].sc]) {
            bool ok = 1;
            FOR(k, 0, a[j].ft.size() - 1) if(a[i].ft[k] != a[j].ft[k]) {ok = 0; break;}
            if(!ok) continue;
            vs[a[j].sc] = 0;
            vs[a[i].sc] = 0;
            ans.pb({a[i].sc, a[j].sc});
            break;
        }
    }

    for(auto &[i, j] : ans) cout << i << ' ' << j << el;
}

void solve() {

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