#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

vector<int> B = {
	0,
	31, // jan
	28, // feb
	31, // march
	30, // april
	31, // may
	30, // june
	31, // july
	31, // august
	30, // september
	31, // ocotober
	30, // november
	31, // december
};

int solve() {
	auto calc = [](int mes, int ano) {
		if (ano % 4 == 0 and (ano % 100 != 0 or ano % 400 == 0)) {
			if (mes == 2) return 29;
		}
		return B[mes];
	};

	int res = 0, c = 1;
	for (int ano = 1901; ano <= 2000; ano++) {
		for (int mes = 1; mes <= 12; mes++) {
			int dias = calc(mes, ano);
			for (int dia = 1; dia <= dias; dia++) {
				res += (dia == 1 and (c % 7 == 6));
				c++;
			}
		}
	}
	cout << res << endl;

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

