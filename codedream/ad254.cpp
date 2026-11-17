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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e6, mod = 1e9 + 7;
ll n, k; 
string S;

struct Node {
    Node *child[26];
    int endNode;

    Node() {
        memset(child, NULL, sizeof child);
        endNode = 0;
    }
};

Node node[N + 1];
Node *root;
int trieNode = 0;

Node *createNode() {
    return &node[++trieNode];
}

void addString(const string &s) {
    Node *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p -> child[s[i] - 'a'] == NULL) p -> child[s[i] - 'a'] = createNode();
        p = p -> child[s[i] - 'a'];
    }

    p->endNode ++;
}

void read() {
    cin >> S >> k; root = createNode();
    n = S.size(); S = ' ' + S;
    // cerr << "begin\n";
    FOR(i, 1, k) {
        string a; cin >> a; reverse(all(a));
        addString(a);
    }
    // cerr << "end\n";
}

ll dp[N + 1];

void dfs(ll pos, ll &amon) {
    Node *p = root;
    FORD(i, pos, 1) {
        if(p->child[S[i] - 'a'] == NULL) return;
        p = p->child[S[i] - 'a'];
        amon += p->endNode * dp[i - 1];
        amon %= mod;
    }
}

void solve() {
    dp[0] = 1;
    FOR(i, 1, n) dfs(i, dp[i]);
    // cerr << "begin\n";
    cout << dp[n];
    // cerr << "end\n";
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}