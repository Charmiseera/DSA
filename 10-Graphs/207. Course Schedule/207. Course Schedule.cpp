1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>>adj(numCourses);
5        vector<int>indegree(numCourses,0);
6
7        for(auto &p:prerequisites){
8            adj[p[1]].push_back(p[0]);
9            indegree[p[0]]++;
10        }
11        queue<int>q;
12        for(int i=0;i<numCourses;i++){
13            if(indegree[i]==0){
14                q.push(i);
15            }
16        }
17        int count=0;
18        while(!q.empty()){
19            int node=q.front();
20            q.pop();
21            count++;
22            for(auto it : adj[node]){
23                indegree[it]--;
24                if(indegree[it]==0){
25                    q.push(it);
26                }
27            }
28    
29        }
30        return count==numCourses;
31    }
32};