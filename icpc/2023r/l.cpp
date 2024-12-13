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

int main()
{
    _;

	string s ;cin >> s;
	int k, n = (int)s.size(); cin >> k;

	// sortar tudo que ta em uma dist k
	vector<string> v(k);
	vector<int> vis(n, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n and i + j < n and !vis[i+j]; j += k) {
			v[i].push_back(s[i+j]);
			vis[i+j] = 1;
		}
	}

	fill(vis.begin(), vis.end(), 0);
	for (string& s : v) sort(s.begin(), s.end());
	vector<char> res(n);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < (int) v[i].size(); j++) {
			res[i + j*k] = v[i][j];
		}
	}

	for (char& c : res) cout << c; cout << endl;
    
    return(0);
}
