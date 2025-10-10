#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define vi vector<int>
#define grafo vector<vector<int>>

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n;cin>>n;

	vector<vector<char>> v(n , vector<char>(n));


	for(int i = 0 ; i < n ; i++)
		for(char& c : v[i]) cin >> c;

	for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
					if(v[i][j] != v[j][i]){
							cout << "Nao" << endl;
							return 0;
						}
				}
		}
	cout << "Sim" << endl;
	return 0;
}
