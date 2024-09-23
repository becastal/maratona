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

int main()
{
    _;

	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (auto& l : v) for (auto& c : l) cin >> c;

	auto checa = [&]() {
		for (int i = 0; i < n; i++) {
			if (!is_sorted(v[i].begin(), v[i].end())) return 0;
		}

		for (int i = 0; i < n; i++) {
			vector<int> temp;
			for (int j = 0; j < n; j++) {
				temp.push_back(v[j][i]);
			}
			if (!is_sorted(temp.begin(), temp.end())) return 0;
		}

		return 1;
	};

	auto roda = [&]() {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(v[i][j], v[j][i]);
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n / 2; i++) {
				swap(v[i][j], v[n - i - 1][j]);
			}
		}
	};

	for (int i = 0; i < 4; i++) {
		if (checa()) return cout << i << endl, 0;
		roda();
	}
    
    return(0);
}
