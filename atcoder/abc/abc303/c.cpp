#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, h, k; cin >> n >> m >> h >> k;
	string S; cin >> S;

	set<array<int, 2>> A;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		A.insert({a, b});
	}

	map<char, array<int, 2>> mov = {
		{'R', {+1, 0}},
		{'L', {-1, 0}},
		{'U', {0, +1}},
		{'D', {0, -1}}
	};

	int ui = 0, uj = 0;
	for (char c : S) {
		auto [di, dj] = mov[c];
		h--;
		if (h < 0) return cout << "No" << endl, 0;

		int vi = ui + di, vj = uj + dj;
		if (A.count({vi, vj}) and h < k) {
			h = k;
			A.erase({vi, vj});
		}
		tie(ui, uj) = {vi, vj};
	}
	cout << "Yes" << endl;

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

