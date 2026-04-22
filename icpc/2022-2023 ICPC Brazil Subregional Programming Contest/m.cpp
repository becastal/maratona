#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e5 + 10;
vector<int> fatores[MAX];
int divi[MAX], C[MAX];

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;

	for (int i = 2; i <= lim; i++) {
		auto& v = fatores[i];
		fact(v, i);
		sort(all(v));
		v.erase(unique(all(v)), v.end());
	}
}

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];		
	}

	vector<array<int, 2>> Q(q);
	for (auto& [c, d] : Q) {
		cin >> c >> d;
	}

	vector<int> Res(n, -1), L(n, 0), R(n, q-1);
	vector<vector<int>> Mid(q);
	for (int rep = 0, lim = __lg(q) + 2; rep < lim; rep++) {
		for (int i = 0; i < n; i++) {
			if (L[i] <= R[i]) {
				int mid = L[i] + (R[i] - L[i]) / 2;
				Mid[mid].push_back(i);
			}
		}

		memset(C, 0, sizeof(C));
		for (int mid = 0; mid < q; mid++) {
			auto [c, d] = Q[mid];
			
			{
				int m = (int)fatores[c].size();
				vector<int> P((1 << m), 1);
				for (int mask = 1; mask < (1 << m); mask++) {
					P[mask] = P[mask & (mask - 1)] * fatores[c][__builtin_ctzll(mask)];
					C[P[mask]] += d;
				}
			}

			for (int id : Mid[mid]) {
				int i = id + 1;

				int m = (int)fatores[i].size(), acum = 0;
				vector<int> P((1 << m), 1);
				for (int mask = 1; mask < (1 << m); mask++) {
					P[mask] = P[mask & (mask - 1)] * fatores[i][__builtin_ctzll(mask)];
					acum += (__builtin_popcountll(mask) & 1 ? +C[P[mask]] : -C[P[mask]]);
				}
				
				if (acum >= A[id]) {
					R[id] = mid - 1;
					Res[id] = mid + 1;
				} else {
					L[id] = mid + 1;
				}
			}
			Mid[mid].clear();
		}
	}

	Res[0] = -1;
	for (int i = 0; i < n; i++) {
		cout << Res[i] << endl;
	}

	return(0);
}

signed main()
{
    _;
	crivo(MAX-1);

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

