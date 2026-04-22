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
	int n;cin>>n;

	vector<int> v(n);
	
	int m = INF;

	for(int& i : v){
		cin>>i; m = min(m, i);	
	}

	ll ans = 0;

	for(int x : v){
		ans += abs(x-m);
	}
	cout<<ans<<endl;
    return(0);
}
