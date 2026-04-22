#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

vector<int> divs(int n) {
	vector<int> Res;
	
	for (int i = 1; i * i <= n; i++) if (n % i == 0) {
		Res.push_back(i);
		if (i * i != n) Res.push_back(n / i);
	}
	
	return Res;
}

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> V(n), Res(n + 1), D = divs(n);

	for (int g : D) {
		
	}

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

