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
    int t; cin >> t;

    while (t--)
    {
        int n, k; cin >> n >> k;

        vector<int> nums(n);
        for (auto& ai : nums)
            cin >> ai;
        
        deque<int> dq;
        vector<int> resp;
        
        int soma = 0;
        for (int i = 0; i < k; i++)
            soma += nums[i];

        for (int i = 0; i < n; i++)
        {
            if (dq.size() < k)
                dq.push_back(nums[i]);
            else
            {
                
            }
        }
    }
    
    return(0);
}