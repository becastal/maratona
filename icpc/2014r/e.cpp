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
typedef pair<int, int> ii;

const ii movs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(n));
	for (auto& a : v) for (auto& b : a) cin >> b;

	auto valido = [] (int i, int j, int n, int m) { return i >= 0 and i < n and j >= 0 and j < m; };

	int res = 0;
	function<void(vector<int>, int)> f = [&](vector<int> vi, int mi) {
		if (mi == 0) {
			
			vector<vector<int>> vis((int)vi.size(), vector<int>(m));
			int cont = 0;
			for (int i = 0; i < (int)vi.size(); i++) {
				for (int j = 0; j < m; j++) {
					if (!vis[i][j] and vi[i] & (1 << j)) {
						stack<ii> st; st.emplace(i, j);
						vis[i][j] = 1;
						cont++;
						
						while (!st.empty()) {
							ii u = st.top(); st.pop();

							for (auto mov : movs) {
								ii v = {u.f + mov.f, u.s + mov.s};

								if (valido(v.f, v.s, (int)vi.size(), m) and !vis[v.f][v.s] and vi[v.f] & (1 << v.s)) {
									vis[v.f][v.s] = 1;	
									st.emplace(v);
								}
							}
						}
					}
				}
			}

			if (cont > 1) return;

			//for (int i : vi) {
			//	for (int j = 0; j < m; j++) {
			//		cout << !!(i & (1 << j));
			//	}
			//	cout << endl;
			//}
			//cout << endl;

			int s = 0;
			for (int i : vi) s |= i;
			int largura = __builtin_popcount(s), altura = vi.size();

			for (int i = 0; i <= n - altura; i++) {
				for (int j = 0; j <= n - largura; j++) {
					int agr = 0;
					for (int ii = 0; ii < altura; ii++) {
						for (int jj = 0; jj < largura; jj++) {
							agr += !!(vi[ii] & (1 << jj)) * v[i+ii][j+jj];
						}
					}
					res = max(res, agr);
				}
			}
			return;
		}

		for (int i = 0; i < (1 << m); i++) {
			if (i & vi.back() and mi - __builtin_popcount(i) >= 0) {
				auto vii = vi;
				vii.push_back(i);
				f(vii, mi - __builtin_popcount(i));
			}
		}
	};

	for (int i = 0; i < (1 << m); i++) {
		f(vector<int>{i}, m - __builtin_popcount(i));
	}
	cout << res << endl;
    
    return(0);
}
