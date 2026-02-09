#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int burro() {
	int n; cin >> n;

	vector<int> P(n);
	iota(all(P), 0);

	auto mex = [&](int l, int r) {
		vector<int> vis(n, 0);
		
		for (int i = l; i <= r; i++) {
			vis[P[i]] = 1;
		}

		int res = 0;
		while (res < n and vis[res]) res++;
		return res;
	};

	map<int, int> M;

	do {
		set<int> S;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				S.insert(mex(i, j));	
			}
		}

		cout << "[";
		for (int i = 0; i < n; i++) {
			cout << P[i] << (i == n-1 ? "" : ", ");
		}
		cout << "] S = " << (int)S.size() << endl;
		M[(int)S.size()]++;

	} while(next_permutation(all(P)));

	for (auto [a, b] : M) {
		cout << "n = " << n << ", k = " << a << ": " << b << endl;
	}

	return(0);
}

int solve() {

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		burro();
		//solve();
	}
    
    return(0);
}

