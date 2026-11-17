#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 2e5 + 5;
ll n, q, kq = 0, block = 0, a[N], ans[N], len[N];
bool vs[N]; 

struct QUERY {
    ll x, y, z;
};

struct HISTORY {
    ll val, cur_kq, left_pos, left_len, right_pos, right_len;
};

stack<HISTORY> history_stack;
vector<QUERY> query;

void read() {
    cin >> n >> q;
    block = max(1, (int)sqrt(n));

    FOR(i, 1, n) {
        cin >> a[i];
    }

    FOR(i, 1, q) {
        ll l, r; cin >> l >> r;
        query.pb({l, r, i});
    }
}

void add(ll val, bool roll) {
    if(vs[val]) return;
    vs[val] = 1;

    ll lenLeft = (val > 1 && vs[val - 1]) ? len[val - 1] : 0;
    ll lenRight = (val < n && vs[val + 1]) ? len[val + 1] : 0;

    if(roll) {
        history_stack.push({
            val, kq, 
            val - lenLeft, len[val - lenLeft], 
            val + lenRight, len[val + lenRight]
        });
    }

    ll newLen = lenLeft + 1 + lenRight;
    kq = max(kq, newLen);

    len[val - lenLeft] = newLen;
    len[val + lenRight] = newLen;
}

void rollback(ll endRoll) {
    while(history_stack.size() > endRoll) {
        auto p = history_stack.top();
        history_stack.pop();

        vs[p.val] = 0;
        kq = p.cur_kq;
        
        len[p.left_pos] = p.left_len;
        len[p.right_pos] = p.right_len;
    }   
}

ll cal(ll pos) {
    ll l = query[pos].x, r = query[pos].y;
    static int tmp_len[N];
    static bool tmp_vs[N];
    
    int max_len = 0;
    FOR(i, l, r) {
        int val = a[i];
        if (tmp_vs[val]) continue;
        tmp_vs[val] = 1;
        
        int lenLeft = (val > 1 && tmp_vs[val - 1]) ? tmp_len[val - 1] : 0;
        int lenRight = (val < n && tmp_vs[val + 1]) ? tmp_len[val + 1] : 0;
        
        int newLen = lenLeft + 1 + lenRight;
        max_len = max(max_len, newLen);
        
        tmp_len[val - lenLeft] = newLen;
        tmp_len[val + lenRight] = newLen;
    }
    
    FOR(i, l, r) {
        tmp_vs[a[i]] = 0;
        tmp_len[a[i]] = 0;
        if (a[i] > 1) tmp_len[a[i] - 1] = 0;
        if (a[i] < n) tmp_len[a[i] + 1] = 0;
    }
    return max_len;
}

void solve() {
    sort(all(query), [](const QUERY &x, const QUERY &y) {
        ll rx = x.x / block, ry = y.x / block;
        if(rx != ry) return rx < ry;
        return x.y < y.y;
    });

    ll curL = 0;
    
    while (curL < q) {
        ll current_block = query[curL].x / block;

        memset(len, 0, sizeof(len));
        memset(vs, 0, sizeof(vs));
        kq = 0;
        while(!history_stack.empty()) history_stack.pop();

        ll curR = curL;
        while(curR < q && (query[curR].x) / block == current_block) curR ++;
        curR --;

        ll L_inside = (current_block + 1) * block;
        ll R = L_inside - 1;

        FOR(j, curL, curR) {
            if(query[j].y < L_inside) {
                ans[query[j].z] = cal(j);
            } else {
                while(R < query[j].y) {
                    R++;
                    add(a[R], 0);
                }
                
                ll sz = history_stack.size();
                FORD(v, L_inside - 1, query[j].x) {
                    add(a[v], 1);
                }
                
                ans[query[j].z] = kq;

                rollback(sz);
            }
        }
        curL = curR + 1;
    }

    FOR(i, 1, q) cout << ans[i] << el;
}

int main() {
    boost;
    read();
    solve();
    return 0;
}