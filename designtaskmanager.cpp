class TaskManager {
public:
   typedef pair<int,int>P;
   priority_queue<P>maxHeap; //priority,taskId
   unordered_map<int,int>taskprioritymap;//taskid,priority
   unordered_map<int,int>taskOwnermap;//task,owner
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task:tasks){
            add(task[0],task[1],task[2]);
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority,taskId});
        taskprioritymap[taskId]=priority;
        taskOwnermap[taskId]=userId;
        
    }
    
    void edit(int taskId, int newPriority) {
        maxHeap.push({newPriority,taskId});
        taskprioritymap[taskId]=newPriority;
        
    }
    
    void rmv(int taskId) {
        taskprioritymap[taskId]=-1;
        
    }
    
    int execTop() {
        while(!maxHeap.empty()){
            auto[prio,taskId]=maxHeap.top();
            maxHeap.pop();
            if(prio==taskprioritymap[taskId]){
                taskprioritymap[taskId]=-1;
                return taskOwnermap[taskId];
            }

        }
        return -1;
        

        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */