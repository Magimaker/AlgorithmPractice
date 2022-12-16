#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team
{
    int teamID;
    int totalScore;
    int submitCount;
    int lastTime;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt)
    {
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        auto teams = vector<Team>(n);
        for (int i = 0; i < n; ++i)
        {
            teams[i].teamID = i + 1;
        }

        auto scores = vector<vector<int>>(n, vector<int>(k));
        for (int i = 0; i < m; ++i)
        {
            int teamID, probNum, score;
            cin >> teamID >> probNum >> score;
            // 0부터 시작하게 보정
            teamID--;
            probNum--;
            scores[teamID][probNum] = max(scores[teamID][probNum], score);
            teams[teamID].submitCount++;
            teams[teamID].lastTime = i;
        }

        // 총 점수 구하기
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                teams[i].totalScore += scores[i][j];
            }
        }

        // 등수 구하기
        sort(teams.begin(), teams.end(), [](Team& lhs, Team& rhs){
	        if (lhs.totalScore != rhs.totalScore)
	        {
                return lhs.totalScore > rhs.totalScore;
	        }
	        if (lhs.submitCount != rhs.submitCount)
	        {
                return lhs.submitCount < rhs.submitCount;
	        }
            return lhs.lastTime < rhs.lastTime;
        });

        auto iter = find_if(teams.begin(), teams.end(), [t](const Team& team) {
            return team.teamID == t;
        });
        cout << (iter - teams.begin()) + 1 << '\n';
    }

    return 0;
}