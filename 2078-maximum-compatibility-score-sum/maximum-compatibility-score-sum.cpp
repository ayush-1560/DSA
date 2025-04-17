class Solution {
public:
    int maxScore = 0;

    int calcScore(vector<int>& a, vector<int>& b) {
        int score = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) score++;
        }
        return score;
    }

    void backtrack(int idx, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool>& used, int currScore) {
        if (idx == students.size()) {
            maxScore = max(maxScore, currScore);
            return;
        }

        for (int j = 0; j < mentors.size(); j++) {
            if (!used[j]) {
                used[j] = true;
                int score = calcScore(students[idx], mentors[j]);
                backtrack(idx + 1, students, mentors, used, currScore + score);
                used[j] = false;
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        vector<bool> used(n, false);
        backtrack(0, students, mentors, used, 0);
        return maxScore;
    }
};
