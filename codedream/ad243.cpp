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

const ll N = 1e5 * 30;
ll t, n, ans = 0;

struct NODE {
    NODE *child[3];
    
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

void addNum(ll a) {
    NODE *p = root;
    FORD(i, 30, 0) {
        ll k = BIT(a, i);
        if(p -> child[k] == NULL) p -> child[k] = makeNode();
        p = p -> child[k];
    }
}

void query(ll a) {
    ll res = 0; NODE *p = root;
    FORD(i, 30, 0) {
        ll k = BIT(a, i);
        if(p -> child[1 - k] != NULL) {
            res |= MASK(i);
            p = p -> child[1 - k];
        } else p = p -> child[k];
    }
    ans = max(ans, res);
}

void read() {
    cin >> t;
}

void solve() {
    FOR(i, 1, t) {
        cin >> n;
        trieNode = 0; root = makeNode();
        ans = 0;

        FOR(j, 1, n) {
            ll s; cin >> s; addNum(s); query(s);
        }
        
        cout << ans << el;
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