#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N, M;
    cin >> N >> M;

    string word;
    unordered_map<string, int> keywords;
    for (int i = 0; i < N; ++i)
    {
        cin >> word;
        keywords[word]++;
    }
    string line;
    stringstream ss;
    for (int i = 0; i < M; ++i)
    {
        cin >> line;
        ss.clear();
        ss.str(line);
        while (getline(ss, word, ','))
        {
            auto iter = keywords.find(word);
            if (iter != keywords.end())
            {
                keywords.erase(iter);
            }
        }
        cout << keywords.size() << '\n';
    }

    return 0;
}