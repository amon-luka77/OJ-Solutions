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
ll n, ans = 0;
vector<string> a;

struct NODE {
    NODE *child[26];
    int cntNode = 0;

    NODE() {
        FOR(i, 0, 25) child[i] = NULL;
    }
};

NODE node[N + 1];
NODE *root;
ll trieNode = 0;

NODE *createNode() {
    return &node[++trieNode];
}

void addString(const string &s) {
    NODE *p = root; ll high = 0; p -> cntNode ++;
    FOR(i, 0, s.size() - 1) {
        high ++;
        if(p -> child[s[i] - 'a'] == NULL) p -> child[s[i] - 'a'] = createNode();
        p -> child[s[i] - 'a'] -> cntNode ++;
        ans += (p -> cntNode - p -> child[s[i] - 'a'] -> cntNode) * high;
        p = p -> child[s[i] - 'a'];
    }
}

void read() {
    cin >> n; root = createNode();
    FOR(i, 1, n) {
        string s; cin >> s;
        a.pb(s);
    }
    sort(all(a), [](const string &x, const string &y) {
        return x.size() > y.size();
    });
    for(auto i : a) addString(i);
    cout << ans;
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