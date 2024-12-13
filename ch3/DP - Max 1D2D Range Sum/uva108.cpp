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

	int n; cin >> n;
	vector a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (j) a[i][j] += a[i][j-1];
		}
	}

	int res = -INF;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subRec = 0;
			for (int ii = 0; ii < n; ii++) {
				subRec = max(subRec + a[ii][j] - (i ? a[ii][i-1] : 0), 0);
				res = max(res, subRec);	
			}
		}
	}

	cout << res << endl;
    
    return(0);
}
