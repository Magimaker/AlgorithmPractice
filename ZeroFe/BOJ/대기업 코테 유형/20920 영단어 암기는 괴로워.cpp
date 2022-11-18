#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int wordCount, minLength;
    cin >> wordCount >> minLength;

    auto map = unordered_map<string, int>();

    // 입력 받기
    string word;
    for (int i = 0; i < wordCount; ++i)
    {
        cin >> word;
        if (word.size() < minLength)
        {
            continue;
        }

        map[word] += 1;
    }

    // 배열로 만들어서 소트
    typedef pair<string, int> Word;
    vector<Word> vec;
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        vec.push_back({ iter->first, iter->second });
    }
    sort(vec.begin(), vec.end(), [](const Word& lhs, const Word& rhs){
        if (lhs.second != rhs.second)
        {
            return lhs.second > rhs.second;
        }
        if (lhs.first.size() != rhs.first.size())
        {
            return lhs.first.size() > rhs.first.size();
        }
        return lhs.first < rhs.first;
    });

    for (const auto& word : vec)
    {
        cout << word.first << '\n';
    }

    return 0;
}