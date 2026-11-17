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
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 200;
ll n, mark[30], deg[30], ok[N + 1][N + 1];
vector<string> a;
vector<ll> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {
        string s; cin >> s; s = ' ' + s;
        a.pb(s);
    }

    FOR(i, 0, a.size() - 1) FOR(j, i + 1, min(i + 1, (ll)a.size() - 1)) {
        FOR(k, 1, min(a[i].size() - 1, a[j].size() - 1)) if(a[i][k] != a[j][k]) {
            if(!ok[a[i][k] - 'a'][a[j][k] - 'a']) {
                edge[a[i][k] - 'a'].pb(a[j][k] - 'a');
                deg[a[j][k] - 'a'] ++;
            }
            ok[a[i][k] - 'a'][a[j][k] - 'a'] = 1;
            break;
        }
    }
}

void solve() {
    queue<ll> q;
    FORD(i, 25, 0) if(deg[i] == 0) q.push(i);
    vector<ll> topo;
    
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        topo.pb(u); mark[u] = 1;
        for(auto i : edge[u]) {
            deg[i] --;
            if(deg[i] == 0) q.push(i);
        }
    }

    if(topo.size() != 26) cout << -1;
    else for(auto i : topo) cout << char(i + 'a');
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