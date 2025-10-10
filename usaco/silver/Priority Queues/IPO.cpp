class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> a;
        for (int i = 0; i < (int)profits.size(); i++) {
            a.emplace_back(capital[i], profits[i]);
        }

        priority_queue<int> pq;
        sort(a.begin(), a.end());
        for (int i = 0, pos = 0; i < k; i++) {
            while (pos < (int)a.size() and w >= a[pos].first) {
                pq.emplace(a[pos++].second);
            }

            if (pq.size()) {
                w += pq.top(); pq.pop(); 
            }
        }

        return w;
    }
};
