
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long,long>mp;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }
        mp[nums[0]]++;
        long badpairs=0;
        long numberbeforej=0;
        for(int i=1;i<n;i++){
            numberbeforej=i;
            badpairs+=i-mp[nums[i]];
             mp[nums[i]]++;
           
        }
        return badpairs;
        
    }
};