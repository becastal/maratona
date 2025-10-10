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

	int n, m, k, cas = 0;
	while (cin >> n >> m >> k and n) {
		vector<int> n_ruim(n, 0), m_ruim(m, 0);
		while (k--) {
			int i, j; cin >> i >> j;	
			n_ruim[i] = 1;
			m_ruim[j] = 1;
		}

		auto da = [&](int a, int b) {
			return a >= 0 and b >= 0 and a < n and b < m and !n_ruim[a] and !m_ruim[b];		
		};

		int a, b, ok = 0; cin >> a >> b;
		vector<pair<int, int>> movs = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		for (auto mov : movs) {
			ok |= da(a + mov.f, b + mov.s);	
		}

		cout << "Case " << ++cas << ": " << (ok ? "Escaped again! More 2D grid problems!" : "Party time! Let's find a restaurant!") << endl;
	}
	
    
    return(0);
}
