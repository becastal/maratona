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
struct Ponto {
    int x, y;
	int id;
};

bool operator <(const Ponto &p1, const Ponto &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int verCurva(const Ponto &O, const Ponto &A, const Ponto &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

 void convex_hull(vector<Ponto> P)
{
	int n = P.size(), k = 0;
	vector<Ponto> H(2*n);

	// Ordena os pontos
	// Obs: Conforme função que sobrecarrega o operador "<"
	sort(P.begin(), P.end());

	// Constrói a borda inferior do convex hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && verCurva(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	// Constrói a borda inferior do convex hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && verCurva(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	set<int> s;
	for(auto& p : H)s.insert(p.id);
	bool cond = true;
	for(auto& x : s){
		if(cond){
			cond=false;
			cout<<x;
		}
		else{
			cout << ' ' << x;
			}
	}
	cout <<  endl;
}
int main()
{
    _;
	int n;cin>>n;    
	vector<Ponto> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].y;v[i].id=i+1;
	}
	convex_hull(v);
	
    return(0);
}
