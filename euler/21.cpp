#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 10001;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) {
		divi[i] = 1;
	}

	for (int i = 2; i <= lim; i++) {
		for (int j = i; j <= lim; j += i) {
			divi[j] += i;
		}
		divi[i] -= i;
	}
}

int solve() {
	int res = 0;

	for (int i = 2; i < MAX; i++) {
		if (divi[i] < MAX and divi[i] != i and divi[divi[i]] == i) {
			res += divi[i];
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

