#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct vertex{
	int v, state, usei;
	ll w;

	bool operator < (const vertex& v) const { return w > v.w; }
};

int solve() {
	int n, c, p;cin>>n>>c>>p;

	vector<vector<pair<ll,ll>>> uber(n), ped(n);

	for(int i = 0; i < c; i++){
		int x, y, w;cin>>x>>y>>w;
		x--, y--;
		uber[x].push_back({y, w});
	}

	for(int i = 0; i < p; i++){
		int x, y, w;cin>>x>>y>>w;
		x--, y--;
		ped[x].push_back({y, w});
		ped[y].push_back({x, w});
	}

	//vector<vector<ll>> dist(2, vector<ll>(n, LINF));
	vector dist(2, vector(2, vector<ll>(n, LINF)));
	// to usando, usei, u
	
	dist[0][0][0] = 0;
	dist[1][1][0] = 0;

	function<void()> bfs = [&] (){
		priority_queue<vertex> pq;	
		
		pq.push({0, 0, 0, 0});
		pq.push({0, 1, 1, 0});

		// 0 se estou a pe
		// 1 se estou de carro
		
		while(!pq.empty()){
			auto [s, state, usei, W] = pq.top();pq.pop();
			
			if(dist[state][usei][s] < W)continue;

			for(auto [v, peso] : ped[s]){
				if(dist[state][usei][v] > W+peso){
					dist[state][usei][v] = W+peso;
					pq.push({v, 0, usei, W+peso});
				}
			}
			
			if(!state and usei) continue;

			for(auto [v, peso] : uber[s]){
				if(dist[state][usei][v] > W+peso){
					dist[state][usei][v] = W+peso;
					pq.push({v, 1, 1, W+peso});
				}
			}
		}
	};

	bfs();

	ll res = LINF;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res = min(res, dist[i][j][n-1]);
		}
	}
	cout << res << endl;
//	cout<<dist[0][n-1]<<endl;
//	cout<<dist[1][n-1]<<endl;
	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

