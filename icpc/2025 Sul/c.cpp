#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	for (int i = 0; i < n; i++) {
		A.push_back(A[i]);	
	}

	for (int i = 1; i < 2*n; i++) A[i] = min(A[i], A[i-1] + 1);
	for (int i = 2*n-2; i >= 0; i--) A[i] = min(A[i], A[i+1] + 1);

	vector<int> B(n);
	for (int i = 0; i < n; i++) {
		B[i] = min(A[i], A[i+n]);
	}

	cout << *max_element(all(B)) << endl;

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
