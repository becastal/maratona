#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector<vector<array<int, 2>>> movs = {
		{
			{0, 0},		
			{0, 1},		
			{0, 2},		
			{0, 3},
			{0, 4}		
		},
		{
			{0, 0},		
			{1, 0},		
			{2, 0},		
			{3, 0},
			{4, 0}		
		},
		{
			{0, 0},		
			{1, -1},		
			{2, -2},		
			{3, -3},
			{4, -4}		
		},
		{
			{0, 0},		
			{1, 1},		
			{2, 2},		
			{3, 3},
			{4, 4}		
		},
		{
			{0, 0},		
			{-1, 1},		
			{-2, 2},		
			{-3, 3},
			{-4, 4}		
		}
	};
	for (int i = 0; i < 5; i++) {
		auto v_ = movs[i];
		reverse(all(v_));
		movs.push_back(v_);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (auto v : movs) {
				string s = "";
				for (auto [di, dj] : v) {
					if (i + di >= 0 and j + dj >= 0 and i + di < n and j + dj < m) s.push_back(A[i + di][j + dj]);
				}
				if (s == "snuke") {
					for (auto [di, dj] : v) {
						cout << i + di + 1 << ' ' << j + dj + 1 << endl;
					}
					return 0;
				}
				//cout << "(" << i << ", " << j << "): " << s << endl;
			}
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

