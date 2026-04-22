#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dirs = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

const vector<char> DirsC = {
	'D',
	'R',
	'U',
	'L',
};

/*

n & 1 ^ 1
e (a + b) * 1 

*/

int solve() {
	int n, a, b; cin >> n >> a >> b;

	if ((n % 2 == 1) or ((a + b) % 2 == 0)) return cout << "No" << endl, 0;

	string Res = "";
	if (a & 1) {
		for (int j = 1; j != b - 1; j += 2) {
			Res += string(n - 1, 'D');
			Res.push_back('R');
			Res += string(n - 1, 'U');
			Res.push_back('R');
		}

		for (int i = 1; i <= n; i += 2) {
			if (i == a) {
				i++;
				Res += "D";
			} else {
				Res += "RDLD";
			}
		}
		Res += "R";

		for (int j = b + 1; j <= n - 1; j += 2) {
			Res.push_back('R');
			Res += string(n - 1, 'U');
			Res.push_back('R');
			Res += string(n - 1, 'D');
		}
	} else {
		for (int i = 1; i != a - 1; i += 2) {
			Res += string(n - 1, 'R');
			Res.push_back('D');
			Res += string(n - 1, 'L');
			Res.push_back('D');
		}

		for (int j = 1; j <= n; j += 2) {
			if (j == b) {
				j++;
				Res += "R";
			} else {
				Res += "DRUR";		
			}
		}
		Res += "D";
		
		for (int i = a + 1; i <= n; i += 2) {
			Res.push_back('D');
			Res += string(n - 1, 'L');
			Res.push_back('D');
			Res += string(n - 1, 'R');
		}
	}

	cout << "Yes" << endl << Res << endl;

	//vector<vector<int>> Vis(n + 1, vector<int>(n + 1));
	//string Res = "";

	//function<bool(int, int, int)> dfs = [&](int ui, int uj, int d) {
	//	if (ui == n and uj == n) return d == n * n - 2;

	//	for (int k = 0; k < 4; k++) {
	//		auto [di, dj] = Dirs[k];
	//		int vi = ui + di, vj = uj + dj;
	//		if (vi < 1 or vj < 1 or vi > n or vj > n or Vis[vi][vj] or (vi == a and vj == b)) continue;
	//		Vis[vi][vj] = 1;
	//		Res.push_back(DirsC[k]);
	//		if (dfs(vi, vj, d + 1)) {
	//			return true;
	//		}
	//		Vis[vi][vj] = 0;
	//		Res.pop_back();
	//	}
	//	return false;
	//};
	//Vis[1][1] = 1;


	//cout << n << ' ' << a << ' ' << b << ": ";
	//if (!dfs(1, 1, 0)) return cout << "No" << endl, 0;
	//cout << "Yes, " << Res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

