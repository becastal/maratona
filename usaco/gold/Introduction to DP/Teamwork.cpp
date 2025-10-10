#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("teamwork");

	int n, k; cin >> n >> k;
	vector<int> A(n), dp(n, -1);
	for (int& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		int mx = A[i];
		for (int j = i; j >= i - k + 1 and ~j; j--) {
			mx = max(mx, A[j]);
			dp[i] = max(dp[i], (j ? dp[j-1] : 0) + mx * (i - j + 1));
		}
	}
	cout << dp.back() << endl;

    return(0);
}
