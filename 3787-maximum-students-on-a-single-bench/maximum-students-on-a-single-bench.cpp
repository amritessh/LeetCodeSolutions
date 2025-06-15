class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        if(students.size() == 0)
            return 0;
        unordered_map<int, unordered_set<int>>Cnt;
        for(int i = 0; i < students.size(); i++){
            int student_id  = students[i][0];
            int bench_id  = students[i][1];
            Cnt[bench_id].insert(student_id);
        }
        int max = 0;
        for(auto [bench_id, set] : Cnt){
            if(set.size() > max){
                max = set.size();
            }
        }
        return max;
    }

};