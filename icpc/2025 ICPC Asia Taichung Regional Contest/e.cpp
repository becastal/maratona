#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

map<int, vector<string>> M;

int solve() {
	int n, aa, bb; cin >> n >> aa >> bb;
	string a = M[n][aa-1], b = M[n][bb-1];

	int tam = 0;
	while (n) {
		tam++;
		n /= 10;
	}

	int c = 0;
	for (int i = 0; i < tam; i++) {
		c += (a[i] == b[i]);
	}
	cout << c << "A" << tam - c << "B" << endl;

	return(0);
}

int main()
{
    _;

	for (int i : {12, 123, 1234}) {
		string s = to_string(i);
		
		do {
			M[i].push_back(s);	
		} while (next_permutation(all(s)));
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

