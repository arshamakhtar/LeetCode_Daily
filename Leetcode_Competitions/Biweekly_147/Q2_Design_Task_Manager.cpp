class TaskManager {
private:
    unordered_map<int, pair<int, int>> tInfo;
    map<pair<int, int>, int> tOrder;        
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            tInfo[t[1]] = {t[0], t[2]};
            tOrder[{t[2], t[1]}] = t[0];
        }
    }

    void add(int u, int t, int p) {
        tInfo[t] = {u, p};
        tOrder[{p, t}] = u;
    }

    void edit(int t, int p) {
        auto [u, oldP] = tInfo[t];
        tOrder.erase({oldP, t});
        tInfo[t] = {u, p};
        tOrder[{p, t}] = u;
    }

    void rmv(int t) {
        auto [u, p] = tInfo[t];
        tOrder.erase({p, t});
        tInfo.erase(t);
    }

    int execTop() {
        if (tOrder.empty()) return -1;
        auto it = tOrder.rbegin();
        int u = it->second, t = it->first.second;
        tOrder.erase({it->first.first, t});
        tInfo.erase(t);
        return u;
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
