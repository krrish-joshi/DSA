class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        
        int l = 0;
        int ans = 0;
        int n = fruits.size();

        for (int h = 0; h < n; h++) {
            count[fruits[h]]++;

            while (count.size() > 2) {
                count[fruits[l]]--;

                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }

                l++;
            }

            ans = max(ans, h - l + 1);
        }

        return ans;
    }
};