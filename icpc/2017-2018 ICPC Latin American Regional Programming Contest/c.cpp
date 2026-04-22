#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int k, n; cin >> k >> n;

	vector<int> A(n), C(k + 1);
	for (int& i : A) {
		cin >> i;
		C[i]++;
	}

	if ((n + 1) % k == 0) {
		int quero = (n + 1) / k, cont = 0, quem = 0, ruim = 0;

		for (int a = 1; a <= k; a++) {
			int b = C[a];	
			if (b == quero - 1) {
				cont++;
				quem = a;
			} else if (b != quero) ruim = 1;
		}

		if (!ruim and cont == 1) return cout << "+" << quem << endl, 0;
	}

	if ((n - 1) % k == 0) {
		int quero = (n - 1) / k, cont = 0, quem = 0, ruim = 0;

		for (int a = 1; a <= k; a++) {
			int b = C[a];	
			if (b == quero + 1) {
				cont++;
				quem = a;
			} else if (b != quero) ruim = 1;
		}

		if (!ruim and cont == 1) return cout << "-" << quem << endl, 0;
	}

	if (n % k == 0) {
		int quero = n / k, cont_l = 0, quem_l = 0, cont_r = 0, quem_r = 0, ruim = 0;

		for (int a = 1; a <= k; a++) {
			int b = C[a];	
			if (b == quero + 1) {
				cont_r++;
				quem_r = a;
			} else if (b == quero - 1) {
				cont_l++;
				quem_l = a;
			} else if (b != quero) ruim = 1;
		}

		if (!ruim and cont_l == 1 and cont_r == 1) return cout << "-" << quem_r << " +" << quem_l << endl, 0;
	}

	cout << "*" << endl;

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

