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

double dist(vector<tuple<int,int,int>>& v, int l, int r){
	auto [x1, y1, r1] = v[l];
	auto [x2, y2, r2] = v[r];
	double ans =  sqrt(pow(x2-x1, 2)+pow(y2-y1, 2))-r1-r2;
	dbg(ans);
	return ans;
}
int main()
{
    _;
	int t;cin>>t;

	while(t--){
		int n;cin>>n;

		vector<tuple<int,int,int>> v(n);
		for(auto& [x, y, r] : v)cin>>x>>y>>r;
			
//		sort(v.begin(), v.end());

		int l = 0;
		ll ans = 0;
		for(int r = 1; r < n; r++){

			while(dist(v, l, r) > 0.0) l++;
			
			int x = r-l;
			ans += ;
		}
		cout<<ans<<endl;
	}
    return(0);
}
