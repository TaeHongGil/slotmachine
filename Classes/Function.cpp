#include "Function.h";

int makeRandNum(std::vector<int> vecProb)
{
    std::random_device rd;            // 제너레이터
    std::mt19937 gen(rd());

    //std::discrete_distribution (이항분포) 사용 -> 가중치를주기위해
    std::discrete_distribution<int> d{ vecProb.begin(), vecProb.end() };    // 초기화
    return d(gen);
}

int makeRandNum()
{
    std::random_device rd;            // 제너레이터
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 50);
    return dis(gen);
}

int indexCheck(int index[])
{
    for (int i = 0; i < LINE - 2; i++)
    {
        if (index[i] == index[i + 1] && index[i + 1] == index[i + 2])
            return index[i];
    }

    return 0;
}

