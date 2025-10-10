#include <iostream> 
#include <vector>   
#include <algorithm> 
#include <utility>  

using namespace std;

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        vector<pair<int, int>> presentes; // <volume do presente, id do presente>.
        for (int j = 0; j < n; j++)
        {
            int id, h, w, l;
            scanf("%d %d %d %d", &id, &h, &w, &l);
            presentes.push_back({ h * w * l, -id });
        }
        sort(presentes.begin(), presentes.end());

        vector<int> ids(k);
        for (int l = 0; l < k; l++)
        {
            ids[l] = -presentes.back().second;
            presentes.pop_back();
        }
        sort(ids.begin(), ids.end());

        for (int m = 0; m < ids.size(); m++)
        {
            if (m != 0) cout << " ";
            cout << ids[m];
        }
        cout << endl;
    }
    return 0;
}
