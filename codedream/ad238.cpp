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
ll n, q;

struct NODE {
    NODE *child[26];
    int cnt = 0;

    NODE() {
        memset(child, NULL, sizeof child);
    }
};

NODE node[N + 1];
NODE *root;
ll trieNode = 0;

NODE *makeNode() {
    return &node[++trieNode];
}

void addString(const string &s) {
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[s[i] - 'a'] == NULL) p -> child[s[i] - 'a'] = makeNode();
        p -> child[s[i] - 'a'] -> cnt ++;
        p = p -> child[s[i] - 'a'];
    }
}

ll query(const string &s) {
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[s[i] - 'a'] == NULL) return 0;
        p = p -> child[s[i] - 'a'];
    }
    return p -> cnt;
}

void read() {
    cin >> n; root = makeNode();
    FOR(i, 1, n) {
        string s; cin >> s;
        addString(s);
    }
    cin >> q;
    FOR(i, 1, q) {
        string s; cin >> s;
        cout << query(s) << el;
    }
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