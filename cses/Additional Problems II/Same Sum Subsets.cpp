#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

unordered_map<ll, int> calc(vector<ll>& A) {
    int n = (int)A.size();
    const int MAX = 1 << n;

    vector<ll> sums(MAX, 0);
    for (int m = 1; m < MAX; m++) {
        int lsb = m & -m;
        int b = __builtin_ctz(lsb);
        sums[m] = sums[m ^ lsb] + A[b];
    }

    unordered_map<ll, int> M;
    M.reserve(MAX);
    M.max_load_factor(0.7f);
    for (int m = 1; m < MAX; ++m) {
        ll s = sums[m];
        if (!M.count(s)) M.emplace(s, m);
    }
    return M;
}

vector<ll> trad(vector<ll>& A, int msk) {
	int n = (int)A.size();

	vector<ll> V;
	for (int i = 0; i < n; i++) if (msk & (1 << i)) {
		V.push_back(A[i]);
	}
	return V;
}

int solve() {
	random_device rd;
    mt19937 g(rd());

	int n; cin >> n;
	int mid = n / 2;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	for (int t = 0; t < 10; t++) {
		shuffle(all(A), g);

		vector<ll> A1(A.begin(), A.begin() + mid), A2(A.begin() + mid, A.end());
		auto B = calc(A1), C = calc(A2);

		for (auto [i, mskb] : B) {
			if (C.count(i)) {
				int mskc = C[i];
				auto Vb = trad(A1, mskb), Vc = trad(A2, mskc);
				cout << Vb.size() << endl;
				for (ll i : Vb) cout << i << ' '; cout << endl;
				cout << Vc.size() << endl;
				for (ll i : Vc) cout << i << ' '; cout << endl;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;

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

