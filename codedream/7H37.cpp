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

const ll N = 2e5;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

namespace Sub1 {
    bool check() {return n <= 100;}
    
    void solve() {
        ll res = 0;
        FOR(j, 1, n) FOR(k, j + 1, n) {
            ll cnt = 0;
            FOR(i, 1, j - 1) cnt += ((a[i] ^ a[j]) < (a[j] ^ a[k]));
            // cout << "[" << cnt << ", " << j << ", " << k << "]\n"; 
            res += cnt;
        }
        cout << res;
    }
}

namespace Sub2 {
    bool check() {return (n <= 3000);}
 
    struct Node {
        Node *child[3];
        int cnt = 0;
        Node() {memset(child, NULL, sizeof child); cnt = 0;}
    };
 
    Node node[60 * N + 1];
    Node *root;
    int trieNode = 0; ll limit = 0;
 
    Node *createNode() {return &node[++trieNode];}
 
    void addNum(ll num) {
        Node *p = root;
        FORD(i, 60, 0) {
            int numBit = BIT(num, i);
            if(p->child[numBit] == NULL) p->child[numBit] = createNode();
            p = p->child[numBit]; p->cnt ++;
        }
    }
 
    ll dfs(Node *p, ll num, int pos) {
        if(p == NULL || pos < 0) return 0;
 
        int numBit = BIT(num, pos), bitLimit = BIT(limit, pos);
        ll res = 0;
 
        if(bitLimit) {
            res += dfs(p->child[numBit ^ 1], num, pos - 1); 
            if(p->child[numBit] != NULL) res += p->child[numBit]->cnt;
        }
        else {
            res += dfs(p->child[numBit], num, pos - 1);
        }
 
        return res;
    }
 
    void solve() {
        ll res = 0; root = createNode();
        // cerr << "begin\n";
        FOR(i, 1, n) {
            FOR(j, i + 1, n) {
                limit = a[i] ^ a[j];
                // cout << "[" << dfs(root, limit, 60, 0) << ", " << i << ", " << j << "]\n"; 
                res += dfs(root, a[i], 60);
            }
            addNum(a[i]);
        }
        // cerr << "end\n";
        cout << res;
    }
}

namespace Sub3 {
    bool check() {return 1;}

    struct Node {
        int child[2];
        int cnt;
        Node(){memset(child, 0, sizeof child); cnt = 0;}
    };

    struct Trie {
        Node node[60 * N + 1];
        int trieNode = 0;

        int createNode(){return ++trieNode;}

        void addNum(const ll &x) {
            int p = 1;
            FORD(i, 60, 0) {
                int k = BIT(x, i);
                if(!node[p].child[k]) node[p].child[k] = createNode();
                p = node[p].child[k]; node[p].cnt ++;
            }
        }
    } trieLeft, trieRight;
    ll totalPairs[61][2];

    ll getPairs(Trie &amon, ll pos, ll roll) {
        ll x = amon.node[pos].child[roll];
        return amon.node[x].cnt;
    }

    void updated(const ll &num, ll type) {
        ll pLeft = 1, pRight = 1;
        FORD(i, 60 ,0) {
            ll k = BIT(num, i);
            totalPairs[i][0] -= getPairs(trieLeft, pLeft, 0) * getPairs(trieRight, pRight, 1);
            totalPairs[i][1] -= getPairs(trieLeft, pLeft, 1) * getPairs(trieRight, pRight, 0);

            if(type == 1) {
                // xoa trieRight
                ll x = trieRight.node[pRight].child[k];
                trieRight.node[x].cnt --;
            } else {
                // them trieLeft
                if(!trieLeft.node[pLeft].child[k]) trieLeft.node[pLeft].child[k] = ++trieLeft.trieNode;
                ll x = trieLeft.node[pLeft].child[k];
                trieLeft.node[x].cnt ++;
            }

            
            totalPairs[i][0] += getPairs(trieLeft, pLeft, 0) * getPairs(trieRight, pRight, 1);
            totalPairs[i][1] += getPairs(trieLeft, pLeft, 1) * getPairs(trieRight, pRight, 0);
            
            pLeft = trieLeft.node[pLeft].child[k];
            pRight = trieRight.node[pRight].child[k];
        }
    } 

    ll query(const ll &num) {
        ll res = 0;
        FORD(i, 60, 0) {
            ll d = BIT(num, i);
            res += totalPairs[i][d];
        }
        return res;
    }

    void solve() {
        trieLeft.trieNode = 1; trieRight.trieNode = 1;
        FOR(i, 1, n) trieRight.addNum(a[i]);
        ll res = 0;
        FOR(i, 1, n) {res += query(a[i]); updated(a[i], 2); updated(a[i], 1);}
        cout << res;
    }
}

void solve() {
    // if(Sub1::check()) {Sub1::solve(); return;}
    // if(Sub2::check()) {Sub2::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
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