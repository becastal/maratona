#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;

	vector<pair<int,int>> v(n);
	for(auto& [x, y] : v)cin>>x>>y;

	int ans = -1;
	ll l = 1, r = 1e9+10;

	while(l < r){
		int ok = 1;
		int mid= (r+l) / 2; 
		int raio = mid;

		for(int i = 0; i < n-1; i++){
			auto [x1, y1] = v[i];
			auto [x2, y2] = v[i+1];

			ll dist = 	abs(x2-x1+y2-y1);

			if(raio >= dist) ok = 0;

			raio = dist - raio;
		}
		if(ok) l = mid + 1, ans = mid;
		else r = mid;
	}

	cout<<ans<<endl;
	return 0;
}
