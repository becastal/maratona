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
	vector<array<int, 4>> v(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> v[i][j];
		}
	}
    
    return(0);
}
