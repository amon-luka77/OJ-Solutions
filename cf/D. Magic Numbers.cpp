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
#define FOR(i, a, b) for (ll i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i >= _a; i--)
#define boost                                                                  \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define file(name)                                                             \
  freopen(name ".inp", "r", stdin);                                            \
  freopen(name ".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const ll N = 2000;
ll n, m, dp[N + 1][10][3], b[N + 1];
string A, B;

void read() { cin >> n >> m >> A >> B; }

ll getCount(string &C) {
  ll numDigit = C.size();
  FOR(i, 0, numDigit - 1) b[i] = C[i] - '0';
  memset(dp, 0, sizeof dp);
  FOR(i, 1, b[0]) dp[0][i][(i == b[0])] = 1;

  FOR(i, 0, numDigit - 1) FOR(j, 0, 9) FOR(k, 0, 1) if (dp[i][j][k]) {
    ll left = (i % 2) ? m : 0, right = (i % 2) ? min(b[i], m) : (k ? b[i] : 9);

    FOR(t, left, right) {
      ll newJ = t;
      ll newK = k && (t == right);

      dp[i + 1][newJ][newK] += dp[i][j][k];
    }
  }

  if (!(numDigit % 2))
    return dp[numDigit][m][1] + dp[numDigit][m][0];
  else {
    ll res = 0;
    FOR(i, 0, b[numDigit - 1]) res += dp[numDigit][i][1] + dp[numDigit][i][0];
    // cout << res << el;
    return res;
  }
}

bool check(string &C) {
  FOR(i, 0, C.size() - 1) if (i % 2 && C[i] != m) { return 0; }

  return 1;
}

void solve() { cout << getCount(B) - getCount(A) + check(A); }

void write() {}

int main() {
  boost;
  // file();
  read();
  solve();
  write();
  return 0;
}