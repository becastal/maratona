#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	auto da = [&](int m) {
		int agr = 0, cont = 0;
		for (int i : A) {
			agr += i;			
			if (agr >= m) {
				agr = 0;
				cont++;
			}
		}
		return cont >= k;
	};

	int l = *min_element(all(A)), r = accumulate(all(A), 0LL) + 10, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (!da(m)) { 
			r = m-1;
		} else {
			res = m;
			l = m+1;
		}
	}
	cout << res << endl;

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

