class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(begin(meetings), end(meetings));
            int n = meetings.size();
            int start = 0;
            int end = 0;
            int result = 0;
    
            for (auto& meet : meetings) {
                if (meet[0] > end) {
                    result += meet[0] - end - 1;
                }
                end = max(end, meet[1]);
            }
            if (days > end) {
                result += days - end;
            }
            return result;
        }
    };