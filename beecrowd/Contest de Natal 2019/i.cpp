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

	int n;
	while (cin >> n and n) {
		vector<int> v(n), res(n, 0);
		for (int& i : v) cin >> i;
		
		int ai; cin >> ai;
		if (ai > accumulate(v.begin(), v.end(), 0)) {
			cout << "Impossible" << endl;
			continue;
		}

		while (ai) {
			for (int i = 0; i < n; i++) {
				if (ai) {
					int d = res[i] < v[i];
					ai -= d;
					res[i] += d;
				}
			}
		}

		sort(res.rbegin(), res.rend());
		for (int i : res) cout << i << endl;
	}

    return(0);
}
