#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

vector<int> divisores(int a) {
	vector<int> R;
	for (int i = 1; i * i <= a; i++) if (a % i == 0) {
		R.push_back(i);	
		if (a / i != i) R.push_back(a / i);
	}
	return R;
}

const int MAX = 2e7+10;
int primo[MAX], divi[MAX];

void crivo(int lim) {
	memset(primo, 1, sizeof(primo));
	memset(divi, 0, sizeof(divi));

	for (int i = 2; i <= lim; i++) if (primo[i]) {
		for (int j = i+i; j <= lim; j += i) {
			primo[j] = 0;
		}
	}

	for (int i = 2; i <= lim; i++) if (primo[i]) {
		for (int j = i; j <= lim; j += i) {
			divi[j]++;
		}
	}
}


int solve() {
	int c, d, x; cin >> c >> d >> x;

	ll res = 0;
	for (int div : divisores(x)) { 
		if ((div + d) % c) continue;
		res += (1LL << divi[(div + d) / c]);
	}
	cout << res << endl;

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

