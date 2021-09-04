#include <iostream>

int calcMiddle(int l, int u)
{
    return (l + u) / 2;
}

int main()
{
    int lower;
    int upper;
    int middle;

    std::cin >> lower >> upper;
    middle = calcMiddle(lower, upper);
    std::cout << middle << "\n";

    char ls;

    while ((lower != middle || upper != middle))
    {
        std::cin >> ls;
        if (ls == 'l')
        {
            lower = middle + 1;
            middle = calcMiddle(lower, upper);
        }
        else if (ls == 's')
        {
            upper = middle - 1;
            middle = calcMiddle(lower, upper);
        }
        else
        {
            std::cout << "please provide 'l' for larger and 's' for smaller"
                      << "\n";
        }

        std::cout << middle << "\n";
    }

    return 0;
}