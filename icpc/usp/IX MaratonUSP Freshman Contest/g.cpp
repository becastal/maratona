#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<int> divs(int x) {
	vector<int> res;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res.push_back(i);
			if (x / i != i) res.push_back(x / i);
		}
	}
	return res;
}

int main()
{
    _;

	int n; cin >> n;
	map<int, int> f;

	for (int i = 1; i <= n; i++) {
		ll agr = i, s = 1;
		while (s + agr <= n) {
			s += agr;	
			agr *= i;
			f[s]++;
		}
	}

	for (auto [a, b] : f) {
		if (b != 2) cout << a << ' ' << b << endl;
	}

	int res = 0;
	for (int i : divs(n)) {
		res += f[i];
	}
	cout << res << endl;
    
    return(0);
}
