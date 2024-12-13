#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e2+10;

int memo[MAX][MAX];
char mat[MAX][MAX];
int n;
int dp(int i , int j, set<char> s){
    if(i >= n or j >= n) return INF;
    if(i < 0 or j < 0) return INF;
    char c = mat[i][j];
    int& pdm = memo[i][j]; 
    if(pdm != -1) return pdm;

    if(islower(c) and s.count(c-32))return INF;
    if(isupper(c) and s.count(c+32))return INF;
    s.insert(c);

    if(i == 0 and j ==0) return 1;

    pdm = INF;

    for(int f = -1 ; f < 2 ; f++){
        if(f==0)continue;
        int x = dp(i+f, j, s);
        int y = dp(i, j+f, s);

        int ans = INF;

        if(x != INF or y != INF)
            ans = min(x,y)+1;

        pdm=min(ans,pdm);
    }
    return pdm;
}

int main() { 
	_;
    cin>>n;
    memset(memo, -1 , sizeof memo);

    for(int i = 0 ; i < n ; i++){
        string pal;cin>>pal;
        for(int j = 0 ; j < n ; j++)
            mat[i][j]=pal[j];
    }
    set<char>s;
    int ans = dp(n-1,n-1,s);

    if(ans != INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
