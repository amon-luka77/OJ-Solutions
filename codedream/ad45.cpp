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
using namespace std;

const ll N = 1e6, base = 256, mod1 = 1e9 + 2277, mod2 = 998244353;
ll t, k, h[N + 5][5], mul[N + 5][5], mode[5]; 
ll hashY[3], hashZ[3];

ll getHash(ll l, ll r, ll m) {
    return (h[r][m] - h[l - 1][m] * mul[r - l + 1][m]);
}

ll binary(ll tg, const vector<ll> &b) {
    ll l = 1, r = b.size() - 1, ans = -1;

    while(l <= r) {
        ll mid = (l + r) >> 1;
        
        if(b[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

void read() {
    cin >> t;
    
    while(t --) {
        memset(hashY, 0, sizeof(hashY));
        memset(hashZ, 0, sizeof(hashZ));
        memset(mul, 0, sizeof(mul));
        memset(h, 0, sizeof(h));

        cin >> k;
        string x, y, z; cin >> x >> y >> z;

        ll sizeX = x.size(), sizeY = y.size(), sizeZ = z.size();
        x = ' ' + x; y = ' ' + y; z = ' ' + z;

        bool ok = 0;
        vector<ll> posY;
        posY.pb(0);
        mul[0][1] = 1;
        mul[0][2] = 1;

        FOR(i, 1, sizeX) {
            h[i][1] = (h[i - 1][1] * base + x[i]);
            mul[i][1] = (mul[i - 1][1] * base);
            h[i][2] = (h[i - 1][2] * base + x[i]);
            mul[i][2] = (mul[i - 1][2] * base);
        }


        FOR(i, 1, sizeY) {
            hashY[1] = (hashY[1] * base + y[i]);
            hashY[2] = (hashY[2] * base + y[i]);
        }

        FOR(i, 1, sizeZ) {
            hashZ[1] = (hashZ[1] * base + z[i]);
            hashZ[2] = (hashZ[2] * base + z[i]);
        }

        FOR(i, 1, sizeX - sizeY + 1) {
            if(getHash(i, i + sizeY - 1, 1) == hashY[1] && 
                getHash(i, i + sizeY - 1, 2) == hashY[2]) {
                    posY.pb(i);
            }
        } 

        FOR(i, 1, sizeX - sizeZ + 1) {
            if(getHash(i, i + sizeZ - 1, 1) == hashZ[1] && 
                getHash(i, i + sizeZ - 1, 2) == hashZ[2]) {

                    ll prePos = binary(i + 6, posY);
                    if(!ok && prePos != -1 && posY[prePos] <= i && (posY[prePos] + sizeY - 1) <= (i + sizeZ - 1) &&
                     ((i + sizeZ - 1) - posY[prePos] + 1) <= (sizeY + sizeZ + k)) {
                        ok = 1;
                    }
            }
        }

        if(ok) cout << "YES" << el;
        else cout << "NO" << el; 
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