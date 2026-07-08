1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>>adj(numCourses);
5        vector<int>indegree(numCourses,0);
6        for(auto &p:prerequisites){
7            adj[p[1]].push_back(p[0]);
8            indegree[p[0]]++;
9        }
10        queue<int>q;
11        for(int i=0;i<numCourses;i++){
12            if(indegree[i]==0){
13                q.push(i);
14            }
15        }
16        vector<int>ans;
17        while(!q.empty()){
18            int node=q.front();
19            q.pop();
20            ans.push_back(node);
21            for(auto it:adj[node]){
22                indegree[it]--;
23                if(indegree[it]==0){
24                    q.push(it);
25                }
26            }
27        }
28        if(ans.size()==numCourses){
29            return ans;
30        }
31
32        return {};
33    }
34};