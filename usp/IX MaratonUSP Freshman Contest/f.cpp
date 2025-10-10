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

int t, n, x;

int bin(){
	int l = 0, r = n;

	while(l < r){
		int m = (l+r)/2;
		int total = m*x + (n-m)*(x/2);

		if(total == t) return n-m;
		else if(total < t) l = m+1;
		else r = m;
	}
}
int main()
{
    _;
	cin>>t>>n>>x;

	cout<<bin()<<endl;	
    return(0);
}
