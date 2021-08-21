#include <iostream>

int get_fibonacci_last_digit_naive(int n)
{
    // if (n <= 1)
    //     return n;

    // int previous = 0;
    // int current  = 1;

    // for (int i = 0; i < n - 1; ++i) {
    //     int tmp_previous = previous;
    //     previous = current;
    //     current = tmp_previous + current;
    // }
    int fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] % 10) + (fib[i - 2] % 10);
    }
    // std::cout << fib[n] << "\n";

    return fib[n] % 10;
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
