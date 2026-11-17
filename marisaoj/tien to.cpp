/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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

const ll N = 1e5;
ll n;
vector<string> query;

struct NODE {
    ll child[26];

    NODE() {
        memset(child, -1, sizeof child);
    }
};

NODE node[20 * N + 1];
ll trieNode = 0;
ll root;

ll createNode() {
    return ++trieNode;
}

bool checkString(const string &s) {
    ll p = root;
    FOR(i, 0, s.size() - 1) {
        if(node[p].child[s[i] - 'a'] < 0) return 0;
        node[p].child[s[i] - 'a'];
    }
    return 1;
}

void addString(const string &s) {
    ll p = root;
    FOR(i, 0, s.size() - 1) {
        if(node[p].child[s[i] - 'a'] < 0) node[p].child[s[i] - 'a'] = createNode();
        node[p].child[s[i] - 'a'];
    }
}

void read() {
    cin >> n; root = createNode();
    FOR(i, 1, n) {
        string s; cin >> s;
        query.pb(s);
    }
    sort(all(query), [](const string &x, const string &y) {
        return x.size() > y.size();
    });
}

void solve() {
    for(auto i : query) {
        if(checkString(i)) {cout << "YES"; return;}
        addString(i);
    }

    cout << "NO";
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