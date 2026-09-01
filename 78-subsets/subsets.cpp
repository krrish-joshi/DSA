class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void allSS(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[i]);
        allSS(i + 1, nums);

        // Backtrack
        subset.pop_back();

        // Exclude current element
        allSS(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        allSS(0, nums);
        return ans;
    }
};