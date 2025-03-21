class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes,
                                      vector<vector<string>>& ingredients,
                                      vector<string>& supplies) {
            int n = recipes.size();
    
            unordered_set<string> st(begin(supplies), end(supplies));
            unordered_map<string, vector<int>> adj;
            vector<int>indegree(n,0);
            /*let say for  sandwich ,index is 1 ,look in ingredients .since bread is not in supply.
            means bread is needed to make sandwich
            so push that index in adj list and increase the indegree of index, {bread}----->{0}*/
            for(int i=0;i<n;i++) {
                for(string &ing:ingredients[i]){
                    if(!st.count(ing)){
                        adj[ing].push_back(i);
                        indegree[i]++;
                    }
    
                }
            }
            /*make one queue which will handle indegree=0
            since bread had indegree =0,its index will get pushed in queue i.e,0 */
            queue<int>que;
            for(int i=0;i<n;i++){
                if(indegree[i]==0){
                    que.push(i);
                }
            }
            //since queue contains the idx,we need the string that is in our case it is bread
            //grab it ,push it in result vec and look for the neighbour of bread in adjacency list
            //decrease the indegree .if it is zero.push it in queue.
            //at last return the result.
            vector<string>result;
            while(!que.empty()){
                int i=que.front();
                que.pop();
                string recipe=recipes[i];
                result.push_back(recipe);
                for(int &idx:adj[recipe]){
                    indegree[idx]--;
                    if(indegree[idx]==0){
                        que.push(idx);
                    }
                }
            }
            return result;
        }
    };
