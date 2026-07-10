// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> result(nums.size(),1);
//         for (int i = 0; i < nums.size(); i++) {
//             int pr=1;
//             for (int j = 0; j < nums.size(); j++) {
//                 if (i!=j){
//                     pr*=nums[j];
//                 }
//             }
//             result[i]= pr;
//         }

//         return result;
//     }
// };


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);
        vector<int> prefix(n,1);
        vector<int> sufix(n,1);


        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            sufix[i] = sufix[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++){
            result[i] = prefix[i] * sufix[i];
        }
        return result;
    }
};