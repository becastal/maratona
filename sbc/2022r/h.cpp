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
int n , m;

vector<vector<int>> grafo;
vector<bool>p;
vector<bool>visitados;
int soma = 0;
int cont = 0;
void bfs(int s){
		queue<int> f;f.push(s);

		while(!f.empty()){
				int v = f.front();f.pop();
				visitados[v] = true;
				if(!p[v]) soma++;
				for(auto& x : grafo[v]){
						if(!visitados[x]){
								f.push(x);
								visitados[x] = true;
							}	
					}
			}
	}

int main()
{
    _;
	cin >> n >> m;

	grafo.resize(n+1);
	p.resize(n+1 , false);
	visitados.resize(n+1,false);
	int v1 , v2; 

	for(int i = 0 ; i < m ; i++){
			cin >> v1 >> v2;

			grafo[v1].push_back(v2);
			p[v2] = true;
		}
	for(int i = 1 ; i <= n ; i++){
			if(grafo[i].size() == 0){
					soma++;
			}
			else if(!visitados[i]){
					bfs(i);
				}
		}
	soma += (cont/2) + (cont%2);

	cout << soma << endl;
    return(0);
}
