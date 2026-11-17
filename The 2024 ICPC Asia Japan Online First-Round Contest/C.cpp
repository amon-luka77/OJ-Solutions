#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

const int OFFSET = 1000;
int dis[2 * OFFSET + 1][2 * OFFSET + 1];

vector<pair<int, int>> d = {{0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}, {-1, 1}};
int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    memset(dis, -1, sizeof dis);
    queue<pair<int, int>> q;
    q.push({OFFSET, OFFSET});
    dis[1000][1000] = 0;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for(auto &[i, j] : d) {
            int I = i + x, J = j + y;
            if(I >= 0 && I <= 2000 && J >= 0 && J <= 2000 && dis[I][J] == -1) {
                dis[I][J] = dis[x][y] + 1;
                q.push({I, J});
            }
        }
    }

    while(n --) {
        int x, y; cin >> x >> y;
        cout << dis[x + OFFSET][y + OFFSET] << "\n";
    }
}
