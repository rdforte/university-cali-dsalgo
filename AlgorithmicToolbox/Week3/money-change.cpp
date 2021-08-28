#include <iostream>

void divisibleByNTimes(int &n, int &c, int divisor)
{
    int nTimes = n / divisor;
    n -= (nTimes * divisor);
    c += nTimes;
}

int main()
{
    int n;
    int c = 0;
    std::cin >> n;

    if (n / 10 >= 1)
        divisibleByNTimes(n, c, 10);
    if (n / 5 >= 1)
        divisibleByNTimes(n, c, 5);
    if (n / 1 >= 1)
        divisibleByNTimes(n, c, 1);

    std::cout << c;

    return 0;
}