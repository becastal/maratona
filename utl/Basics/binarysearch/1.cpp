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
	for (int& vi : v)
		cin >> vi;

	sort(v.begin(), v.end());

	function<bool(int)> search = [&] (int q) {
		int l = 0, r = n - 1;

		while (l < r)
		{
			int m = (l + r) >> 1;
			if (v[m] < q)
				l = m + 1;
			else
				r = m;
		}

		return v[l] == q;
	};

	while (k--)
	{
		int q; cin >> q;
		cout << (search(q) ? "YES" : "NO") << endl;
	}
    
    return(0);
}
