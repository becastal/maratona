#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), C(35, 0);
	for (int& i : A) cin >> i;

	int or_ = accumulate(all(A), 0, [](int i, int j) { return i | j; });
	int xor_ = accumulate(all(A), 0, [](int i, int j) { return i ^ j; });

	cout << (xor_ != or_ ? "Alice" : "Bob") << endl;

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

