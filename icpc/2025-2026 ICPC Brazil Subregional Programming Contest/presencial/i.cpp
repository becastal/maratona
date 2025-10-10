#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;

	vector<pair<int,int>> v(n);
	for(auto& [x, y] : v)cin>>x>>y;

	sort(v.begin(), v.end());
	int ans = -1;
	int l = 0, r = n;

	while(l < r){
		int ok = 1;
		int raio = l + (r-l)/2;

		for(int i = 0; i < n-1; i++){
			auto [x1, y1] = v[i];
			auto [x2, y2] = v[i+1];

			int dist = 	abs(x2-x1+y2-y1);
			if(raio >= dist) ok = 0;
			
			raio = dist - raio;
		}

		if(ok) l = raio + 1, ans = l; 
		else r = raio;
	}

	cout<<ans<<endl;
	return 0;
}
