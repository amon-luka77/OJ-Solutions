#include "solution.h"

#include <bits/stdc++.h>
#define ll int
#define el "\n"
#define MASK(i) (1 << (i))
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define all(x) (x).begin(), (x).end()
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;

const ll N = MASK(20) + 1;
ll n;
vector<ll> a, ans;
bool vs[N + 1];

int query(int i, int j);

struct NODE {
    NODE *child[3];

    NODE() {
        memset(child, NULL, sizeof child);
    }
};

NODE node[22 * (MASK(20) + 1) + 1];
NODE *root;
ll trieNode = 0;

NODE *makeNode() {return &node[++trieNode];}

bool check(ll num) {
    NODE *p = root;
    int res = 0;
    FORD(i, 30, 0) {
        ll k = BIT(num, i);
        if(p->child[1 - k] != NULL) {
            res |= MASK(i); p = p->child[1 - k];
        } else p = p->child[k];
    } return res <= n - 1;
}

void add(ll num) {
    NODE *p = root;
    FORD(i, 30, 0) {
        ll k = BIT(num, i);
        if(p->child[k] == NULL) p->child[k] = makeNode;
        p = p->child[k];
    }
}

void Solve() {
    a.assign(n, 0);
    ans.assign(n, 0);

    FOR(i, 1, n - 1) {a[i] = query(0, i); add(a[i]);}

    FOR(i, 0, n - 1) {
        if(check(i)) {
            FOR(j, 0, n - 1) ans[j] = a[j] ^ i;
            return;
        }
    }
}

std::vector<int> solve(int NN) {
    n = NN; Solve();
    return ans;
}
