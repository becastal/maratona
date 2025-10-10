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
 
int main()
{
    _;
 
	int n, k; cin >> n >> k;
	vector<int> v(n);
 
	ll l = 0, r = 0;
	for (int& i : v) cin >> i, r += i;
 
	auto da = [&](ll mi) {
		int res = 1;
		ll soma = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > mi) return INF;
			soma += v[i];
			if (soma > mi) {
				soma = v[i];
				res++;
			}
		}
		return res;
	};
 
	while (l < r) {
		ll m = (l+r)/2;
 
		if (da(m) > k) {
			l = m + 1;
		} else {
			r = m;
		}
	}
 
	cout << l << endl;
    
    return(0);
}
