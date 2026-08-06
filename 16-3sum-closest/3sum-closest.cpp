class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());   // sort first, same as before

        int closestSum = nums[0] + nums[1] + nums[2];  // initialize with first possible sum

        for (int i = 0; i < n - 2; i++) {
            // (no duplicate-skip needed here since we just want closest sum, not unique triplets)

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // update closestSum if this one is nearer to target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum == target) {
                    return sum;   // can't get closer than exact match
                }
                else if (sum < target) {
                    left++;       // sum too small, move left up
                }
                else {
                    right--;      // sum too big, move right down
                }
            }
        }

        return closestSum;
    }
};