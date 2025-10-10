#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e6;
int naoprimo[MAX];
int solve() {

	vector<int> res;
	for (int i = 2; i < MAX; i++)  {
		if (!naoprimo[i]) res.push_back(i);
		for (int j = i + i; j < MAX; j += i) {
			naoprimo[j] = 1;
		}
	}
	cout << res.size() << endl;
	cout << res[10000] << endl;

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
