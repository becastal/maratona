#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	vector<int> A = {0, 3, 1, 4, 1, 5, 9};
	vector<int> P = {0, 3, 4, 8, 9, 14, 23};

	char a, b; cin >> a >> b;
	//cout << int(b - 'A') << ' ' << int(a - 'A') << endl;
	if (a > b) swap(a, b);
	cout << P[b - 'A'] - P[a - 'A'] << endl;

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

