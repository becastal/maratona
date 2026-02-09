#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int a = 0, b = 0;
	for (int i = 0, agra = 0, agrb = 1; i < n; i++) {
		if ((A[i] & 1) == agra) {
			a++;
			agra ^= 1;
		}
		if ((A[i] & 1) == agrb) {
			b++;
			agrb ^= 1;
		}
	}
	cout << max(a, b) << endl;

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

