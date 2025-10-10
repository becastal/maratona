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

	ll cont = 0, ans = 0;

	for(int i = 0, c;i < n; i++){
		cin>>c; cont+=c;

		ans = min(ans, cont);
	}
	cout<<abs(ans)<<endl;;
    return(0);
}
