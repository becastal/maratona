#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e2+10;
using namespace std;
int n;
int dijkstra(int v,int obj, vector<vector<pair<int, int>>>&g) {
	int d[MAX];
	for (int i = 0; i < n; i++) d[i] = INF;
	int save = g[v][obj].s;
	g[v][obj].s=INF;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
	g[v][obj].s=save;
	return d[obj];
}

int main()
{
    _;
	cin>>n;

	vector<vector<pair<int , int>>> grafo(n);
	
	for(int j = 0 ; j < n; j++)
		for(int i = 0, p; i<n;i++){
			cin >> p;
			grafo[j].push_back({i,p});
		}
	int cont = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(i==j)continue;
			if(i > j) continue;
			int ans = dijkstra(i,j,grafo);
			if(ans < grafo[i][j].s){
				cout << -1 << endl;
				return 0;
			}
			else if(ans == grafo[i][j].s){
				cont++;
			}
		}
	}

	cout << cont << endl;

    return(0);
}
