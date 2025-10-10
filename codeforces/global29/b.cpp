#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
4 3 2 1 5 1 2 3 4 5 
0 1 2 3 4 5 6 7 8 9
*/
int solve() {
	int n; cin >> n;

	for (int i = n-1; i >= 1; i--) {
		cout << i << ' ';
	}
	cout << n << ' ';
	for (int i = 1; i <= n; i++) {
		cout << i << ' ';
	}
	cout << endl;

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

