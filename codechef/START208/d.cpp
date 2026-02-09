#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e7+10;
int vis[MAX];

int solve() {
	memset(vis, 0, sizeof(vis));
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	sort(all(A));
	A.erase(unique(all(A)), A.end());

	int mx = *max_element(all(A));
	for (int Ai : A) {
		for (int j = Ai; j <= mx; j += Ai) {
			vis[j] = 1;	
		}
	}

	for (int i = mx; i >= 0; i--) {
		if (!vis[i]) {
			return cout << i << endl, 0;
		}
	}

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

