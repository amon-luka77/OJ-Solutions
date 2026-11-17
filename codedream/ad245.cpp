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
ll n;
vector<pair<string, ll>> a;

struct NODE {
    NODE *child[26];
    vector<int> pos;

    NODE() {
        memset(child, NULL, sizeof child);
    }
};

NODE node[N + 1];
NODE *root;
int trieNode = 0;
vector<pair<ll ,ll>> ans;

NODE *makeNode() {
    return &node[++ trieNode];
}

void addString(const string &s, ll idx) {
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[s[i] - 'a'] == NULL) p -> child[s[i] - 'a'] = makeNode();
        p -> child[s[i] - 'a'] -> pos.pb(idx);
        p = p -> child[s[i] - 'a'];
    }
}

ll getPairs(const string &s) {
    NODE *p = root; int ans = 0;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[s[i] - 'a'] != NULL && p -> child[s[i] - 'a'] -> pos.size() > 0) {
            int x = p -> child[s[i] - 'a'] -> pos.back();
            p -> child[s[i] - 'a'] -> pos.pop_back();
            return x;
        }
        
        if(p -> child[s[i] - 'a'] != NULL) p = p -> child[s[i] - 'a'];
        else return 0;
    }

    return 0;
}

void read() {
    cin >> n; root = makeNode();
    FOR(i, 1, 2 * n) {
        string s; cin >> s;
        a.pb({s, i});
    }

    sort(all(a), [](const pair<string, ll> &x, const pair<string, ll> &y) {
        return x.ft.size() < y.ft.size();
    });

    FOR(i, 0, 2 * n - 1) {
        ll k = getPairs(a[i].ft);
        if(k != 0) ans.pb({a[i].sc, k});
        else addString(a[i].ft, a[i].sc);
    }

    // cout << 1;
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