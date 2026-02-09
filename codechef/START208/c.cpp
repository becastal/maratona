#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, x, k; cin >> n >> x >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	sort(rall(A));
	for (int i = 0; i < k; i++) A[i] = 0;
	x += k * 100;

	int res = 0;
	for (int i : A) res += i > x;
	cout << res + 1 << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

