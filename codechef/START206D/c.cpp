#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e4;
int primo[MAX];

void crivo(int n) {
	for (int i = 1; i <= n; i++) {
		primo[i] = 1;
	}

	for (int i = 2; i <= n; i++) if (primo[i]) {
		for (int j = i+i; j <= n; j += i) {
			primo[j] = 0;
		}
	}
}

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res += primo[A[i] + A[j]];
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

