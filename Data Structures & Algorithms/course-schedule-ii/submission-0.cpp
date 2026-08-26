class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }

        return ans.size()!=numCourses?vector<int>(0):ans;
    }
};
