#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	vector<int> A(8);
	for (int& i : A) cin >> i;

	if (!is_sorted(all(A))) return cout << "No" << endl, 0;
	if (*min_element(all(A)) < 100 or *max_element(all(A)) > 675) return cout << "No" << endl, 0;
	if (accumulate(all(A), 0, [](int a, int b) { return gcd(a, b); }) % 25) return cout << "No" << endl, 0;
	cout << "Yes" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

