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

const ll N = 2e5;
ll n, q;
char a[N + 1];
ll prefixL[N + 1], prefixR[N + 1];
void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> q;        
    FOR(i, 1, n) {
        prefixL[i] = prefixL[i - 1] + (a[i] == 'L');
        prefixR[i] = prefixR[i - 1] + (a[i] == 'R');
    }
}

namespace Sub1 {
    bool check() {
        return (n <= 3000 && q <= 3000);
    }


    void solve() {
        FOR(i, 1, q) {
            ll l, r; cin >> l >> r;
            if(l > r) swap(l, r);
            ll res = 1e18;
            FOR(j, l, r) {
                // l -> j - 1; j + 1 -> r;
                res = min(res, prefixL[j - 1] - prefixL[l - 1] + prefixR[r] - prefixR[j]);
            }

            cout << res << el;
        }
    }
}

namespace Sub3 {
    bool check() {
        return 1;
    }

    const ll LOG = 19;
    ll minA[N + 1][LOG + 1], minValue[N + 1];

    #define MIN_A(x , y) (minValue[x] < minValue[y] ? x : y)

    ll getMin(ll l, ll r) {
        ll k = __lg(r - l + 1);
        return MIN_A(minA[l][k], minA[r - MASK(k) + 1][k]);
    }

    void solve() {
        // prefixL[i - 1] - prefixL[l - 1] + prefixR[r] - prefixR[i];
        // prefixL[i - 1] - prefixR[i] + const;

        FOR(i, 1, n) minValue[i] = prefixL[i - 1] - prefixR[i];
        FOR(i, 1, n) minA[i][0] = i;
        FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) {
            minA[i][j] = MIN_A(minA[i][j - 1], minA[i + MASK(j - 1)][j - 1]);
        } 

        FOR(i, 1, q) {
            ll l, r; cin >> l >> r; if(l > r) swap(l, r);
            ll mid = getMin(l, r);

            cout << prefixL[mid - 1] - prefixL[l - 1] + prefixR[r] - prefixR[mid] << el; 
        }
    }
}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
}

void write() {

}

int main() {
    boost;
    // file("7E16");
    read();
    solve();
    write();
    return 0;
}

/*
8
LRLRLLLR
2
2 8
4 7


*/