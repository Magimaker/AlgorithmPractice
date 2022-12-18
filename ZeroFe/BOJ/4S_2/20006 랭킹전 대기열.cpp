#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    using player = std::pair<string, int>;
    vector<pair<int, vector<player>>> roomList;
    for (int i = 0; i < N; ++i)
    {
        int playerLevel;
        string nickName;
        cin >> playerLevel;
        cin >> nickName;

        // 들어가는 방의 인덱스
        int idx = 0;
        for (idx = 0; idx < roomList.size(); ++idx)
        {
            // 방이 가득 찼다
            if (roomList[idx].second.size() >= M)
            {
                continue;
            }

            // 레벨 범위에 들어가는지 확인
            if (roomList[idx].first >= playerLevel - 10 && roomList[idx].first <= playerLevel + 10)
            {
                break;
            }
        }

        // idx가 범위를 넘어갔다 = 들어갈 방이 없다 = 방 새로 생성
        if (idx == roomList.size())
        {
            roomList.push_back({ playerLevel, vector<player>() });
        }
        roomList[idx].second.push_back({ nickName, playerLevel });
    }

    for (auto& room : roomList)
    {
        auto& r = room.second;
        sort(r.begin(), r.end());
        cout << (r.size() == M ? "Started!" : "Waiting!") << '\n';
        for (const auto& player : r)
        {
            cout << player.second << " " << player.first << '\n';
        }
    }

    return 0;
}