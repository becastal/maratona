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

	int n, q; cin >> n >> q;
	vector<int> a(n);

	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());

	auto da = [&] (int x, int b, int k) {
		return int(upper_bound(a.begin(), a.end(), b + x) - lower_bound(a.begin(), a.end(), b - x)) >= k;
	};

	for (int i = 0, bi, ki; i < q; i++) {
		cin >> bi >> ki;

		int l = 0, r = 1e9 + 10;
		while (l < r) {
			int m = (l+r)/2;
			if (da(m, bi, ki)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << l << endl;
	}
    
    return(0);
}
