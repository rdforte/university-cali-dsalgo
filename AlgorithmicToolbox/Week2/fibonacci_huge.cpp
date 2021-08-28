#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    int fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    }

    return fib[n];
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
