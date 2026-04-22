#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	function<int(int)> tam = [&](int a) {
		int res = 0;
		while (a) {
			res++;
			a /= 10;
		}
		return res;
	};

	vector<int> A, B;
	for (int i = 0; (1 << i) <= (int)1e9; i++) {
		A.push_back(1 << i);	
		B.push_back(tam(1 << i));
	}

	vector<int> Pot = {1};
	for (int i = 0; i < 11; i++) {
		Pot.push_back(Pot.back() * 10);
	}

	unordered_set<int> Vis;
	Vis.reserve(1100000);

	vector<int> Res;
	Res.reserve(1100000);


	function<void(int, int)> f = [&](int a, int t) {
		Vis.insert(a);
		Res.push_back(a);

		for (int i = 0; i < (int)A.size(); i++) {
			int a_ = a + Pot[t] * A[i];
			if (a_ > (int)1e9 or Vis.count(a_)) continue;
			f(a_, t + B[i]);	
		}
	};
	f(0, 0);

	sort(all(Res));
	cout << Res[n] << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

