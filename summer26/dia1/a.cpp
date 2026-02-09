#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int rev(int n){
	int r = 0;

	while(n){
		r *= 10;
		r += n % 10;
		n /= 10;
	}

	return r;
}

signed solve() {
	int a, b;cin>>a>>b;

	a = rev(a), b = rev(b);
	//cout<<a<<' '<<b<<endl;
	cout<<rev(a+b)<<endl;
	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
