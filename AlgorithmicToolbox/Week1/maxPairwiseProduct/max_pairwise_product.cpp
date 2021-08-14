#include <iostream>
#include <vector>
#include <algorithm>

// long long MaxPairwiseProduct(const std::vector<int> &numbers)
// {
//     long long max_product = 0;
//     int n = numbers.size();

//     for (int first = 0; first < n; ++first)
//         for (int second = first + 1; second < n; ++second)
//             max_product = std::max(max_product, (long long)numbers[first] * (long long)numbers[second]);

//     return max_product;
// }

long long calculateMaxPairwiseProduct(std::vector<int> numbers)
{
    long long firstHighest = numbers[0] > numbers[1] ? numbers[0] : numbers[1];
    long long secondHighest = numbers[0] < numbers[1] ? numbers[0] : numbers[1];

    if (numbers.size() > 2)
    {
        for (int i = 2; i < numbers.size(); i++)
        {
            if (numbers[i] > firstHighest)
            {
                secondHighest = firstHighest;
                firstHighest = numbers[i];
            }
            else if (numbers[i] > secondHighest)
            {
                secondHighest = numbers[i];
            }
        }
    }
    return firstHighest * secondHighest;
}

int main()
{

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << calculateMaxPairwiseProduct(numbers) << "\n";
    return 0;
}