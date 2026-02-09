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

	int n, k, x; cin >> n >> k >> x;

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int xi; cin >> xi; 
		v.push_back(xi);
		if (i == k) v.push_back(x);
	}
	for (int i : v) cout << i << ' '; cout << endl;
    
    return(0);
}
