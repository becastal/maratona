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

const int MAX = 2e6+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(set<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.emplace(divi[n]);
}


int solve() {
	int n; cin >> n;
	map<int, int> A;
	map<int, set<int>> f;

	for (int i = 0, ai; i < n; i++) {
		cin >> ai;
		A[ai] = (i + 1);
	}

	for (auto [ai, pos] : A) {
		if (ai == 1) continue;
		fact(f[ai], ai);
	}

	map<int, int> ult;
	vector<int> dp(n, 1), pai(n, -1);
	int ii = 0;
	for (auto [ai, pos] : A) {
		for (int j : f[ai]) {
			if (ult.count(j)) {
				if (dp[ii] < dp[ult[j]] + 1) {
					dp[ii] = max(dp[ii], dp[ult[j]] + 1);
					pai[ii] = ult[j];
				}
			}
			ult[j] = ii;
		}
		ii++;
	}

	vector<int> a, res;
	for (auto [ai, pos] : A) a.push_back(ai);
	cout << *max_element(dp.begin(), dp.end()) << endl;
	
	int u = max_element(dp.begin(), dp.end()) - dp.begin();
	for (; u != -1; u = pai[u]) {
		res.push_back(A[a[u]]);
	}
	reverse(res.begin(), res.end());

	for (int i : res) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
