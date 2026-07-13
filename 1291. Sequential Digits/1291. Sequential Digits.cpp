1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int>ans;
5        string s=123456789;
6        for(int i=2;i<=9 ; i++){
7            for(int j=0;j+i<=9;j++){
8                int num=stoi(s.substr(j,i));
9                if(num>=low && num<=high){
10                    ans.push_back(num);
11                }
12            }
13        }
14        return ans;
15        
16    }
17};