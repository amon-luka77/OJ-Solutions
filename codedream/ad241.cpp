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

const ll N = 1e5;
ll n, t; bool ok = 1;

struct NODE {
    NODE *child[10];
    bool isEnd = 0;

    NODE() {
        memset(child, NULL, sizeof child);
    }
};

NODE node[N + 1];
NODE *root;
ll trieNode = 0;

NODE *makeNode() {
    node[++trieNode] = NODE();
    return &node[trieNode];
}

void addNum(const string &s) {
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[s[i] - '0'] == NULL) p -> child[s[i] - '0'] = makeNode();
        if(p -> child[s[i] - '0'] -> isEnd == 1) ok = 0;
        p = p -> child[s[i] - '0'];
    }

    p -> isEnd = 1;
}

void read() {
    cin >> t;
}

void solve() {
    while(t --) {
        cin >> n;
        trieNode = 0; root = makeNode();
        ok = 1;

        vector<string> a;
        FOR(i, 1, n) {
            string s; cin >> s;
            a.pb(s);
        }

        sort(all(a), [](const string &x, const string &y) {
            return x.size() < y.size();
        });

        for(auto i : a) addNum(i);

        if(ok) cout << "YES" << el;
        else cout << "NO" << el;
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