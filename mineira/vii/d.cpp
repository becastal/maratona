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

int main()
{
    _;

    int c1;

    vector <int> feijao;

    for(int i = 0; i < 4; i ++){
        cin >> c1;
        feijao.push_back(c1);
    }

    for(int i = 0; i < 4; i ++){
        if(feijao[i] == 1){
            cout << i+1 << endl;
            break;
        }
    }

    return(0);
}
