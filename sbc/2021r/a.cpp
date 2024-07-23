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

const int mod = 1e9 + 7;

int main()
{
    _;
	int n , lim; cin >> n >> lim;

	vector<int> v(n);

	for(int& x : v)cin>>x;
	int soma = 0;
	soma = (lim - v[n-1])%mod;

	for(int i = n - 2 ; i >= 0 ; i--){
			int m = max(v[i] , v[i+1]);
			soma = ((lim - m + 1) * soma)%mod;
		}
	cout << soma + 1 << endl;
    return(0);
}
