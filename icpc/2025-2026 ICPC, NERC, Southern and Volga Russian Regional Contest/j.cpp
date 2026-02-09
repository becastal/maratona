#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int pot[10];

int solve() {
	int n; cin >> n;

	auto tam = [&](int a) {
		int r = 0;
		while (a) {
			r++;
			a /= 10;
		}
		return r;
	};

	auto f = [&](int a, int b) {
		int m = tam(a);
		for (int i = 0; i < b; i++) {
			a = a / 10 + (a % 10) * pot[m-1];
		}
		return a;
	};

	int m = tam(n);
	vector<int> R;
	for (int i = 1; i < m; i++) {
		int a = f(n, i), x = a - n;
		
		if (x >= 0 and x % m == i) {
			R.push_back(x);
		}
	}

	sort(all(R));
	cout << (int)R.size() << endl;
	for (int i = 0; i < (int)R.size(); i++) {
		cout << R[i] << " \n"[i == (int)R.size()-1];
	}

	return(0);
}

int main()
{
    _;
	pot[0] = 1;
	for (int i = 1; i <= 9; i++) {
		pot[i] = pot[i-1] * 10;
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

