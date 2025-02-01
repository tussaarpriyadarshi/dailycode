class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n-2;i++){
            if((nums[i]&1)==(nums[i+1]&1)){
                return false;
            }
        }
        return true;
        
    }
};

/*take AND with 1 for each number let say {3,7}
3-011 ,7-111
3&1     7&1
011     111
001     001
----- -------
001     001
same ,therefore return false

*/