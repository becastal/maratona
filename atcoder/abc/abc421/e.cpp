#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n = 6;
	vector<int> A(6);

	for (int& i : A) {
		cin >> i;
	}

	double res = 0.0;
	vector<int> P;
	function<void(int)> f = [&](int p){
		if (p == 5) {
			map<int, int> F;

			double agr = 0.0;
			for (int i : P) {
				F[i]++;
			}


			for (int a : A) {
				int b = F[a];

				int cont = count(all(A), a);
				double p = cont / 6.0;
				double q = 1.0 - pow(1.0 - p, 2);
				double esp = (5 - b) * q;

				agr = max(agr, (b + esp) * a);
			}

			res += agr;

			return;
		}

		for (int i = 0; i < n; i++) {
			P.push_back(A[i]);				
			f(p + 1);
			P.pop_back();
		}
	};
	f(0);

	cout << fixed << setprecision(13);
	cout << res / pow(6, 5) << endl;

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

