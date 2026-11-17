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

const ll N = 1e4;
string s;
int len[N + 1];

struct Node {
    Node *child[26];
    int id;

    Node() {
        memset(child, NULL, sizeof child);
        id = 0;
    }
};

Node node[N + 1];
Node *root;
int trieNode = 0;

Node *createNode() {
    return &node[++trieNode];
}

void addString(const string &s, int numNode) {
    Node *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p->child[s[i] - 'a'] == NULL) p->child[s[i] - 'a'] = createNode();
        p = p->child[s[i] - 'a'];
    }

    p->id = numNode;
}

void read() {
    cin >> s; root = createNode();
    string t; int i = 0;
    while(cin >> t) {
        i ++; len[i] = t.size();
        reverse(all(t));
        addString(t, i);
    }
}

pair<int, int> dp[N + 1];

void dfs(int pos, pair<int, int> &res) {
    Node *p = root; res = {0, 0};
    FORD(i, pos, 1) {
        if(p->child[s[i] - 'a'] == NULL) break;
        p = p->child[s[i] - 'a'];
        if(p->id && dp[i - 1].ft) {
            if(!res.ft) res = {dp[i - 1].ft + 1, p->id};
            else if(res.ft > dp[i - 1].ft + 1) {
                res = {dp[i - 1].ft + 1, p->id};
            }
            // if(pos == 6) cerr << dp[i - 1].ft << ' ' << p->id << el;
        }
    }
}

void solve() {
    dp[0] = {1, 0}; s = ' ' + s;
    FOR(i, 1, s.size() - 1) dfs(i, dp[i]);

    // cerr << 77 << el;

    // FOR(i, 1, s.size() - 1) cerr << "xau " << s.substr(1, i) << (dp[i].ft ? " DUOC chon " : " KHONG duoc chon ") << "cau tao ra duoc la " << dp[i].sc << el;

    if(!dp[s.size() - 1].ft) cout << 0;
    else {
        vector<int> trace;
        ll num = s.size() - 1;
        while(num > 0) {
            trace.pb(dp[num].sc);
            // cout << num << ' ' << dp[num].sc << el;
            num = num - len[dp[num].sc];
        }
        
        cout << trace.size() << el;
        FORD(i, trace.size() - 1, 0) cout << trace[i] << ' ';
    }
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