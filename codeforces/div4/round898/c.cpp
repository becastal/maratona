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

	vector<vector<int>> pts(10, vector<int> (10, 1));
	for (int k = 1; k < 5; k++)
		for (int i = k; i < 10 - k; i++)
			for (int j = k; j < 10 - k; j++)
				pts[i][j]++;

	int t; cin >> t;
	while (t--) {
		int res = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				char c; cin >> c;
				if (c == '.') continue;
				res += pts[i][j];	
			}
		cout << res << endl;
	}
    
    return(0);
}
