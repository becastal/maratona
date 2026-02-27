#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, s; cin >> n >> s;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	auto calc = [](vector<int>& B) {
		int m = (int)B.size();
		
		map<int, int> R;
		for (int i = 0; i < (1 << m); i++) {
			int soma = 0;
			for (int j = 0; j < m; j++) if (i >> j & 1) {
				soma += B[j];
			}
			R[soma]++;
		}

		return R;
	};

	int m = n / 2;
	vector<int> L(A.begin(), A.begin() + m), R(A.begin() + m, A.end());

	map<int, int> Ml = calc(L), Mr = calc(R);

	int res = 0;
	for (auto [a, b] : Ml) {
		res += b * Mr[s - a];
	}


	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

