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

	int n = 5;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<pair<int, string>> res;
	for (int i = 1; i < (1 << n); i++) {
		string eu = "";
		int scr = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				scr += v[j];	
				eu.push_back('A' + j);
			}
		}
		res.emplace_back(-scr, eu);
	}
	sort(res.begin(), res.end());
	for (auto [scri, nome] : res) {
		cout << nome << endl;
	}
    
    return(0);
}
