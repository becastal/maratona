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

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<char>> M(n, vector<char>(m));
	for (auto& l : M) for (auto& c : l) cin >> c;

	auto conta = [](string& s) {
		int res = 0;
		for (int i = 0; i < (int)s.size()-3; i++) {
			if (s[i]=='1' and s[i+1]=='5' and s[i+2]=='4' and s[i+3]=='3') res++;
		}
		
		return res;
	};

	int res = 0;
	for (int d = 0; d < min(n, m) / 2; d++) {
		string s = "";

		for (int j = d; j < m - d; j++) {
			s.push_back(M[d][j]);
		}

		for (int i = d + 1; i < n - d; i++) {
			s.push_back(M[i][m - d - 1]);
		}

		if (n - d - 1 > d) {
			for (int j = m - d - 2; j >= d; j--) {
				s.push_back(M[n - d - 1][j]);
			}
		}

		if (m - d - 1 > d) {
			for (int i = n - d - 2; i > d; i--) {
				s.push_back(M[i][d]);
			}
		}
		s.push_back(s[0]), s.push_back(s[1]), s.push_back(s[2]);

		res += conta(s);
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
