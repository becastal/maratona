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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> cont(2, 0);
	cont[0] = 1;

	int agr = 0;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		agr ^= v[i];
		res += cont[agr^1];	
		cont[agr]++;
	}

	cout << res << endl;
    
    return(0);
}
