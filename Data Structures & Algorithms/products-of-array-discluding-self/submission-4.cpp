class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        // vector<int> prefix(nums.size(), 1);
        // vector<int> suffix(nums.size(), 1);

        // for(int i=1; i<nums.size(); i++) {
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }

        // for(int i=nums.size()-2; i>=0; i--) {
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }

        // for(int i=0; i<nums.size(); i++) {
        //     res[i] = prefix[i] * suffix[i];
        // }
        
        int prefix = 1;
        for(int i=0; i<nums.size(); i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};
