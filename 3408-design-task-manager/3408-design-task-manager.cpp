class TaskManager {
public:
    unordered_map<int,int>taskToPriority;
    unordered_map<int,int>taskToUser;
    set<pair<int,int>>priToTask;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t : tasks){
            int userId = t[0], taskId = t[1], priority = t[2];
            taskToPriority[taskId] = priority;
            taskToUser[taskId] = userId;
            priToTask.insert({-priority,-taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToPriority[taskId] = priority;
        taskToUser[taskId] = userId;
        priToTask.insert({-priority,-taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = taskToPriority[taskId];
        int userId = taskToUser[taskId];

        priToTask.erase({-oldPriority,-taskId});

        priToTask.insert({-newPriority,-taskId});
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = taskToPriority[taskId];
        int userId = taskToUser[taskId];

        priToTask.erase({-priority,-taskId});
        taskToPriority.erase(taskId);
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        if(priToTask.empty()) return -1;
        auto top = *priToTask.begin();
        int taskId = - top.second;
        int userId = taskToUser[taskId];
        rmv(taskId);
        return userId;
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