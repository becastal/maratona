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

vector<int>papai;

int vertices , capacidade;

vector<int> valores;
vector<pair<int , int>> casas;
vector<int> prof;

void procuraPai(int v1 , int v2 , int agua){
		int a = -1 , b = -1;
		do{	
				if(v1 != a) valores[v1] += agua;
				if(v2 != b) valores[v2] += agua;
				
				if(prof[v1] > prof[v2])
					v1 = papai[v1];
				else
					v2 = papai[v2];
				a = v1; b = v2;
		}while(papai[v1] != papai[v2]);
	}

void dfs(vector<vector<int>> &grafo , int source){
		vector<int> visitados(vertices + 1 , 0);
		papai.resize(vertices + 1);
		prof.assign(vertices + 1 , 0);

		stack<int> ale;
		papai[source] = source;
		ale.push(source);
		visitados[source] = 1;
		while(!ale.empty()){
				int vertice = ale.top(); ale.pop();

				for(int& v : grafo[vertice]){
						if(!visitados[v]){
								visitados[v] = 1;
								papai[v] = vertice;
								ale.push(v);
								prof[v] = prof[vertice] + 1;
							}
					}
			}
}



int main()
{
    _;
	cin >> vertices >> capacidade;

	vector<vector<int>> grafo(vertices + 1);
	int v1 , v2;

	for(int i = 0 ; i < vertices - 1 ; i++){
			cin >> v1 >> v2;
			grafo[v1].push_back(v2);
		}
	
	valores.resize(vertices + 1 , 0);
	
	dfs(grafo , 1);
	
	int vendas , casa; cin >> vendas;
	
	casas.resize(vendas + 1);

	while(vendas--){
			pair<int , int> pq;
			cin >> pq.f >> pq.s;
			casas.push_back(pq);
		}

	int caminhoes; cin >> caminhoes;
	int agua;

	while(caminhoes--){
			cin >> v1 >> v2 >> agua;
			procuraPai(v1 , v2 , agua);
		}

	vector<int> dp(capacidade + 1 , 0);

	for(auto& c : casas){
		for(int j = capacidade ; j > 0 ; j--){
				if(c.s > j) continue;

				dp[j] = max(dp[j] , valores[c.f] + dp[j - c.s]);
			}
		}
	cout << dp[capacidade] << endl;
    return(0);
}
