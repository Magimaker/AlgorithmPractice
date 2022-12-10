#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int members[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        
        unordered_map<int, int> counts;
        for (int i = 0; i < N; ++i)
        {
            cin >> members[i];
            counts[members[i]]++;
        }

        int rank = 1;
        unordered_map<int, vector<int>> teams;
        for (int i = 0; i < N; ++i)
        {
	        if (counts[members[i]] == 6)
	        {
                teams[members[i]].push_back(rank++);
	        }
        }

        int minScore = 10000;
        int minFifthScore = 1001;
        int highScoreTeam = -1;
        for (const auto & team : teams)
        {
            int score = 0;
            // 들어온 순서대로 점수 매기기 때문에 앞에 들어온 선수가 무조건 점수가 더 작음
            for (int i = 0; i < 4; ++i)
            {
                score += team.second[i];
            }
            int fifthScore = team.second[4];

            if (minScore > score)
            {
                minScore = score;
                minFifthScore = fifthScore;
                highScoreTeam = team.first;
            }
            else if (minScore == score && minFifthScore > fifthScore)
            {
                minFifthScore = fifthScore;
                highScoreTeam = team.first;
            }
        }

        cout << highScoreTeam << '\n';
    }

}