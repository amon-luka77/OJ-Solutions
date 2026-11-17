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
string s;
ll n;

struct NODE {
    NODE *child[26], *fail, *next[26];
    int cnt;

    NODE() {
        FOR(i, 0, 25) child[i] = next[i] = NULL;
        cnt = 0;
        fail = NULL;
    }
};

NODE node[N + 1];
NODE *root;
NODE *endNode[N + 1];
vector<NODE*> order;
int trieNode = 0;

NODE *createNode() {
    return &node[++trieNode];
}

void addString(const string &s, int id) {
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p->child[s[i] - 'a'] == NULL) p->child[s[i] - 'a'] = createNode();
        p = p->child[s[i] - 'a'];
    }

    endNode[id] = p;
}

void AC_BFS() {
    queue<NODE*> que;
    root->fail = root;
    FOR(i, 0, 25) root->next[i] = root->child[i] != NULL ? root->child[i] : root;
    que.push(root);

    while(!que.empty()) {
        NODE *p = que.front(); que.pop();
        order.pb(p);

        FOR(i, 0, 25) if(p->child[i] != NULL) {
            NODE *q = p->child[i];

            // kmp[i] = i < 2 ? 0 : next[kmp[i - 1]][c];
            q->fail = p == root ? root : p->fail->next[i];

            // next[i][c] = i < lenT && s[i + 1] == c ? i + 1 : next[kmp[i]][c];
            FOR(i, 0, 25) q->next[i] = q->child[i] != NULL ? q->child[i] : q->fail->next[i];

            que.push(q);
        }
    }
}

void read() {
    cin >> s >> n;
}

void solve() {
    root = createNode();
    FOR(i, 1, n) {
        string t; cin >> t;
        addString(t, i);
    }

    AC_BFS();

    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        p = p->next[s[i] - 'a'];
        p->cnt ++;
    }

    FORD(i, order.size() - 1, 0) {
        order[i]->fail->cnt += order[i]->cnt;
    }

    FOR(i, 1, n) cout << (endNode[i]->cnt ? "YES" : "NO") << el;
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