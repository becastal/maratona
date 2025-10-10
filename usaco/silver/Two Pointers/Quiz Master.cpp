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

const int MAX = 1e5+10;
int divi[MAX];
vector<int> divs[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;

	for (int i = 2; i <= lim; i++) {
		for (int j = i; j <= lim; j += i) {
			divs[j].push_back(i);
		}
	}
}


int T = 1;
int solve() {
	int n, m; cin >> n >> m;
	vector<int> v(n);

	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
	if (m == 1) return cout << 0 << endl, 0;

	auto da = [&](int t) {
		vector<int> cont(m+1, 0);
		int falta = m-1;

		for (int r = 0, l = 0; r < n; r++) {
			for (int i : divs[v[r]]) {
				if (i <= m and ++cont[i] == 1) {
					falta--;
				}
			}

			while (l < r and v[r] - v[l] > t) {
				for (int i : divs[v[l]]) {
					if (i <= m and --cont[i] == 0) {
						falta++;
					}
				}
				l++;
			}
			
			if (!falta) return 1;
		}

		return 0;
	};


	int l = 0, r = (int)1e5+10;
	while (l <= r) {
		int mm = l + (r - l) / 2;	

		if (da(mm)) {
			r = mm - 1;
		} else {
			l = mm + 1;
		}
	}
	cout << (l == (int)1e5+11 ? -1 : l) << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
