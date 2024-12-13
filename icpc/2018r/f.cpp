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
int n;


int main()
{
    _;
	cin>>n;
	vector<vector<tuple<int , int , int>>> v(n);
	
	for(int i = 0 ; i < n ; i++){
		int x;cin>>x;
		v[i].resize(x);

		for(auto& [x,y,z] : v[i]) cin >> x >> y >> z;
	}
    return(0);
}
