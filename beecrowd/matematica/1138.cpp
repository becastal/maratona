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

vector<int> f(ll x) {
	vector<int> res(10, 0);	

	if (!x) {
		res[0] = 1;
		return res;
	}

	for (int i = 0; i <= 9; i++) {
		ll p = 1;

		while (p <= x) {
			ll r = x / (p*10), l = x % p;
			ll agr = (x / p) % 10;

			if (agr > i) {
				res[i] += (r + 1) * p;
			} else if (agr == i) {
				res[i] += r * p + (l + 1);
			} else {
				res[i] += r * p;	
			}

			p *= 10;

			if (!i) {
				if (r > 0) {
					res[i] -= p;
				} else {
					break;
				}
			}
		}

	}
	return res;
};

int main()
{
    _;

	int a, b;

	while (cin >> a >> b and a and b) {
		auto fl = f(a-1), fr = f(b);	

		for (int i = 0; i <= 9; i++) {
			cout << fr[i]-fl[i] << " \n"[i==9];
		}
	}
    
    return(0);
}
