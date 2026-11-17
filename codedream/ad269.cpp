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
using namespace std;

const ll N = 2e5;
const ll block = sqrt(N);
ll n, q, blockColor[N / block + 1][101], a[N + 1];

ll startBlock[N + 1], endBlock[N + 1], blockId[N + 1];

void resetBlock(ll id) {
    FOR(i, 0, 100) blockColor[id][i] = i;
}

void read() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }

    ll numBlock = 0, pos = 0;
    while(pos < n) {
        numBlock ++;
        startBlock[numBlock] = pos + 1;
        endBlock[numBlock] = min(n, pos + block);
        pos += block;

        FOR(i, startBlock[numBlock], endBlock[numBlock]) {
            blockId[i] = numBlock;
        } 
        
        resetBlock(numBlock);
    }
}

void updatedAll(ll l, ll r, ll oval, ll nval) {
    FOR(i, startBlock[blockId[l]], endBlock[blockId[l]]) {
        a[i] = blockColor[blockId[l]][a[i]];
    }

        
    resetBlock(blockId[l]);

    FOR(i, l, r) if(a[i] == oval) {
        a[i] = nval;
    }
}

void updated(ll l, ll r, ll oval, ll nval) {
    // if(oval == nval) return;

    if(blockId[l] == blockId[r]) {
        updatedAll(l, r, oval, nval);
        return;
    }

    updatedAll(l, endBlock[blockId[l]], oval, nval);
    updatedAll(startBlock[blockId[r]], r, oval, nval);

    FOR(i, blockId[l] + 1, blockId[r] - 1) FOR(j, 0, 100) if(blockColor[i][j] == oval) {
        blockColor[i][j] = nval;
    }
}

void solve() {
    cin >> q;
    while(q --) {
        ll l, r, pre, cur; cin >> l >> r >> pre >> cur;
        updated(l, r, pre, cur);
    }

    FOR(i, 1, n) {
        cout << blockColor[blockId[i]][a[i]] << ' ';
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