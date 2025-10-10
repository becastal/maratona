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
	vector Ha(n, vector<int>(m));
	for (auto& i : A) cin >> i;

	for (int j = 0; j < m; j++) {
		for (int l = 0, r; l < n; l = r) {
			r = l + 1;
			if (A[l][j] == '#') {
				Ha[l][j] = 0;
				continue;
			}

			while (r < n and A[r][j] == '.') r++;
			for (int i = l; i < r; i++) {
				Ha[i][j] = r;
			}
		}
	}

	vector<int> melhor(n+1, 0);
	for (int i = 0; i < n; i++) {
		vector<int> H(m);
		for (int j = 0; j < m; j++) {
			H[j] = max(0, Ha[i][j] - i);
		}

		stack<int> S;
		vector<int> L(m), R(m);
		for (int j = 0; j < m; j++) {
			while (S.size() and H[S.top()] >= H[j]) S.pop();
			L[j] = (S.size() ? S.top() : -1);
			S.push(j);
		}

		while (S.size()) S.pop();
		for (int j = m-1; j >= 0; j--) {
			while (S.size() and H[S.top()] > H[j]) S.pop();
			R[j] = (S.size() ? S.top() : m);
			S.push(j);
		}

		for (int j = 0; j < m; j++) {
			melhor[H[j]] = max(melhor[H[j]], (R[j] - L[j] - 1));
		}
	}

	for (int i = n-1; i >= 1; i--) {
		melhor[i] = max(melhor[i], melhor[i+1]);	
	}
	//for (int i : melhor) cout << i << endl;

	int maior_area = 0, maior_l = 0, h_, l_, q;
	cin >> q;
	for (int i = 0, h, l; i < q; i++) {
		cin >> h >> l;

		auto ok = [&](int h, int l) {
			if (h < 1 or h > n or l < 1) return false;
			return melhor[h] >= l;
		};
		if (ok(h, l) or ok(l, h)) {
			if (maior_area < h * l or (maior_area == h * l and l_ < l)) {
				maior_area = h * l;
				h_ = h;
				l_ = l;
			}
		}
	}

	cout << h_ << ' ' << l_ << endl;

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

