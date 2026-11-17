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

const ll N = 5e5;
string s; ll n;

struct NODE {
    NODE *child[26], *fail, *next[26];
    vector<int> found; int cnt;

    NODE() {
        FOR(i, 0, 25) child[i] = next[i] = NULL;
        fail = NULL; cnt = 0;
    }
};

NODE node[N + 1];
NODE *root;
vector<NODE*> order;
int trieNode = 0;
int ans[N + 1], len[N + 1];

NODE *makeNode() {
    return &node[++trieNode];
}

void addString(const string &s, int id) {
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        if(p->child[s[i] - 'a'] == NULL) p->child[s[i] - 'a'] = makeNode();
        p = p->child[s[i] - 'a'];
    }
    p->found.pb(id);
}

void AC_BFS() {
    queue<NODE*> que;
    root->fail = root;
    FOR(i, 0, 25) root->next[i] = root->child[i] == NULL ? root : root->child[i];
    que.push(root);

    while(!que.empty()) {
        NODE *p = que.front(); que.pop();
        order.pb(p);

        FOR(i, 0, 25) if(p->child[i] != NULL) {
            // kmp[i] = i < 2 ? 0 : next[kmp[i - 1]][i];
            NODE *q = p->child[i];
            q->fail = p == root ? root : p->fail->next[i];

            FOR(i, 0, 25) {
                // next[i][c] = i < 2 && s[i + 1] == c ? i + 1 : next[kmp[i]][c]
                q->next[i] = q->child[i] != NULL ? q->child[i] : q->fail->next[i];
            }

            que.push(q);
        }
    }
}

void read() {
    cin >> s >> n; root = makeNode();
    FOR(i, 1, n) {
        string t; cin >> t;
        len[i] = t.size();
        addString(t, i);
    }
}

void solve() {
    // cerr << "start" << el;
    AC_BFS();
    // cerr << "end" << el;
    
    NODE *p = root;
    FOR(i, 0, s.size() - 1) {
        p = p->next[s[i] - 'a'];
        if(!p->cnt) p->cnt = i + 1;
    } 

    FOR(i, 1, n) ans[i] = 1e9;

    FORD(i, order.size() - 1, 0) if(order[i]->cnt) {
        NODE *q = order[i];
        if(q->fail->cnt) q->fail->cnt = min(q->fail->cnt, q->cnt);
        else q->fail->cnt = q->cnt;
        if(!q->found.empty()) {
            for(auto j : q->found) {
                ans[j] = min(ans[j], q->cnt - len[j] + 1);
            }
        }
    }

FOR(i, 1, n) cout << (ans[i] != 1e9 ? ans[i] : -1) << el;
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