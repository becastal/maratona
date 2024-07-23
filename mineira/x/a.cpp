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

    vector<int>vv(4 , 3);

    int num;
    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> num;
        if(i+num < 4)vv[i+num]--;
        if(i-num>=0)vv[i-num]--;
    }

    for(int i = 0 ; i < 4 ; i++)
        if(vv[i] == 0)cout << i+1<<endl;

    return(0);
}
