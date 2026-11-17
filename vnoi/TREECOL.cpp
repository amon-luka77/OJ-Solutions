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

const ll N = 5e3;
ll t, n, dp[N + 1][2], sizeTree[N + 1]; 

void read() {
    cin >> t;
}

void dfs(ll u, ll par, const vector<vector<ll>> &edge) {
    // Ban đầu u chưa gộp con nào, u tự đóng vai trò là 1 nút
    dp[u][0] = 0; // u màu đen, chưa có cặp nào
    dp[u][1] = 0; // u màu trắng, chưa có cặp nào

    for(auto v : edge[u]) if(v != par) {
        dfs(v, u, edge);

        ll next_dp0 = -1e18, next_dp1 = -1e18;

        // Trở về bài toán gộp trạng thái i và j (ở đây i, j chỉ nhận giá trị 0 hoặc 1)
        // i đại diện cho trạng thái hiện tại của u, j đại diện cho trạng thái của con v
        for(int i = 0; i <= 1; i++) {
            for(int j = 0; j <= 1; j++) {
                ll val_v = dp[v][j];
                
                // Nếu cả u và v đều đưa trạng thái "Trắng" (1) gặp nhau tại cạnh (u, v)
                // Chúng dính nhau tạo thành 1 đường đi hoàn chỉnh -> Được +1 cặp
                ll bonus = (i == 1 && j == 1) ? 1 : 0;

                // u giữ nguyên tính chất i sau khi gộp v
                if (i == 0) {
                    next_dp0 = max(next_dp0, dp[u][0] + val_v + bonus);
                } else {
                    next_dp1 = max(next_dp1, dp[u][1] + val_v + bonus);
                }
            }
        }
        dp[u][0] = next_dp0;
        dp[u][1] = next_dp1;
    }
}

void solve() {
    while(t --) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        vector<vector<ll>> edge(n + 1, vector<ll>());

        FOR(i, 1, n - 1) {
            ll x, y; cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        dfs(1, -1, edge);

        cout << max(dp[1][0], dp[1][1]) << el;
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