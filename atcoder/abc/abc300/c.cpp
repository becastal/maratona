#include <bits/stdc++.h>
//#define f first
//#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<string> v(n);
	for (auto& i : v) cin >> i;

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;
	};
	auto f = [&](int i, int j, int d) {
		for (int ii : {-d, +d}) {
			for (int jj : {-d, +d}) {
				if (!valido(i + ii, j + jj) or v[i + ii][j + jj] == '.') return 0;
			}
		}
		return 1;
	};

	vector<int> res(min(n, m), 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '.') continue;

			if (f(i, j, 1)) {
				int d = 1;
				while (f(i, j, d + 1)) d++;
				res[d-1]++;
			}
		}
	}
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
