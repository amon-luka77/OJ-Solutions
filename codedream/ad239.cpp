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

const ll N = 5e4 * 50;
ll t, n, ans = 0;
map<char, ll> pos;

struct NODE {
    NODE *child[4];
    int cnt = 0;

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

void addString(const string &s) {
    NODE *p = root; p -> cnt ++;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[pos[s[i]]] == NULL) p -> child[pos[s[i]]] = makeNode();
        p -> child[pos[s[i]]] -> cnt ++;
        p = p -> child[pos[s[i]]];
    }
}

void dfs(NODE *u, ll high) {
    ans = max(ans, u -> cnt * high);
    FOR(i, 0, 3) if(u -> child[i] != NULL) {
        // cerr << "[" << i << ", " << u -> child[i] -> cnt << "], ";
        dfs(u -> child[i], high + 1);
    }
}

void read() {
    cin >> t;
    pos['A'] = 0;
    pos['C'] = 1;
    pos['G'] = 2;
    pos['T'] = 3;

    FOR(i, 1, t) {
        cin >> n;

        trieNode = 0; ans = 0;
        root = makeNode();

        FOR(i, 1, n) {
            string s; cin >> s;
            addString(s);
        }
        dfs(root, 0);
        // cout << el;
        cout << "Case " << i << ": " << ans << el;
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
