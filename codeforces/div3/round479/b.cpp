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

	int n, mx = 0; cin >> n;
	string s, res; cin >> s;
	map<string, int> M;
	for (int i = 0; i < n-1; i++) {
		string si = ""; si.push_back(s[i]), si.push_back(s[i+1]);
		M[si]++;	
	}

	for (auto [a, b] : M) {
		if (b > mx) {
			mx = b;
			res = a;
		}
	}
	
	cout << res << endl;
    
    return(0);
}
