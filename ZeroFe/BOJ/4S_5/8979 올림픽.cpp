#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Medal
{
    int num;
    int g;
    int s;
    int b;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<Medal> nations(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nations[i].num >> nations[i].g >> nations[i].s >> nations[i].b;
    }
    sort(nations.begin(), nations.end(), [](const Medal& lhs, const Medal& rhs) {
        if (lhs.g != rhs.g) return lhs.g > rhs.g;
	    if (lhs.s != rhs.s) return lhs.s > rhs.s;
	    if (lhs.b != rhs.b) return lhs.b > rhs.b;
	    return lhs.num < rhs.num;
    });

    int rank = 1;
    int acc = 1;
    int gold = nations[0].g;
    int silver = nations[0].s;
    int bronze = nations[0].b;
    if (nations[0].num == K)
    {
        cout << rank;
	    return 0;
    }

    for (int i = 1; i < N; ++i)
    {
        if (gold == nations[i].g && silver == nations[i].s && bronze == nations[i].b)
        {
            acc++;
        }
        else
        {
            rank += acc;
            gold = nations[i].g;
            silver = nations[i].s;
            bronze = nations[i].b;
            acc = 1;
        }

        if (nations[i].num == K)
        {
            break;
        }
    }

    cout << rank;

    return 0;
}