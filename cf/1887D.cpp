#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 3e5;

struct QUERY {
    int x, y, idx;
};

struct LINE {
    int Time, l, r, val;
};

int n, q, a[N + 1];
bool ans[N + 1];

int maxLeft[N + 1], maxRight[N + 1], minRight[N + 1];

int bit[N + 1];

void updated(int i, int val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

bool get(int i) {
    int res = 0;
    for(; i > 0; i -= i & -i) res += bit[i];
    return res > 0;
}

#define MASK(i) (1LL << (i))
const int LOG = 20;
int minVal[N + 1][LOG + 1];

int getMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
}

int findMinLeft(int pos, int start) {
    int l = start, r = n, ans = start;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(getMin(start, mid) >= a[pos]) {
            l = mid + 1, ans = mid;
        } else r = mid - 1;
    } return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("1887D.inp", "r", stdin);
    freopen("1887D.out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> q; vector<QUERY> query;
    FOR(i, 1, q) {
        int x, y; cin >> x >> y;
        query.push_back({x, y, i});
    }

    FOR(i, 1, n) minVal[i][0] = a[i];
    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) {
        minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
    }

    stack<int> st;
    FOR(i, 1, n) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        maxLeft[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    } while(!st.empty()) st.pop();

    #define FORD(i, a ,b) for(int i = a, _b = (b); i >= _b; i --)

    FORD(i, n, 1) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        maxRight[i] = (st.empty() ? n + 1 : st.top());
        st.push(i);
    } while(!st.empty()) st.pop();

    vector<LINE> line;
    FOR(i, 1, n) {
        int x = maxLeft[i], y = maxRight[i]; if(y > n) continue;
        int z = findMinLeft(i, y);
//        cerr << "[" << x << ", " << i << ", " << y << ", " << z << "]\n";
        line.push_back({y, x, i, 1});
        line.push_back({z + 1, x, i, -1});
    }

    #define all(x) (x).begin(), (x).end()

    int j = 0;
    sort(all(line), [](const LINE &x, const LINE &y) {
        return x.Time < y.Time;
    });

    sort(all(query), [](const QUERY &x, const QUERY &y) {
       return x.y < y.y;
    });

    for(auto &[x, y, idx] : query) {
        while(j < (int)line.size() && line[j].Time <= y) {
            auto [Time, l, r, val] = line[j];
            updated(l, val);
            updated(r + 1, -val);
            j ++;
        }

        ans[idx] = get(x);
    }

    FOR(i, 1, q) cout << (ans[i] ? "Yes\n" : "No\n");
}

/*
10
5 2 8 5 9 6 8 7 8 8
10
4 5
3 6
6 9
8 10
8 10
5 6
7 10
2 5
1 2
2 9

*/
