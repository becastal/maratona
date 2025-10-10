#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	string s; getline(cin, s);
	stringstream ss(s);

	vector<string> a;
	string si;
	while (ss >> si) {
		a.push_back(si);
	}

	int n = (int)a.size();
	for (int i = 1; i < n; i++) {
		string u = "", v = "";

		for (char c : a[i-1]) {
			if (!isalpha(c)) continue;
			u.push_back(tolower(c));
		}

		for (char c : a[i]) {
			if (!isalpha(c)) continue;
			v.push_back(tolower(c));
		}
		
		if (u == "daniel" and v == "sad") {
			for (int j = 0; j < (int)a[i].size(); j++) {
				if (tolower(a[i][j]) == 'a') {
					a[i].insert(a[i].begin() + j, a[i][j]);
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i==n-1];
	}

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
