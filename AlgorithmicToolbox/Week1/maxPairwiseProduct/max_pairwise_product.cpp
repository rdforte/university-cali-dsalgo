#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// slow is n*n
// long long MaxPairwiseProduct(const std::vector<int> &numbers)
// {
//     long long max_product = 0;
//     int n = numbers.size();

//     for (int first = 0; first < n; ++first)
//         for (int second = first + 1; second < n; ++second)
//             max_product = std::max(max_product, (long long)numbers[first] * (long long)numbers[second]);

//     return max_product;
// }

// much faster is O(n)
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
    /** STRESS - TESTS */
    // while (true)
    // {
    //     int n = std::rand() % 10 + 2;
    //     std::vector<int> a;

    //     std::cout << n << '\n';

    //     for (int i = 0; i < n; i++)
    //     {
    //         a.push_back(std::rand() % 1000);
    //     }

    //     for (int i = 0; i < n; i++)
    //     {
    //         std::cout << a[i] << " ";
    //     }

    //     long long res1 = MaxPairwiseProduct(a);          // slower but correct
    //     long long res2 = calculateMaxPairwiseProduct(a); // faster and more efficient but not sure if correct

    //     if (res1 != res2)
    //     {
    //         std::cout << "Wrong answer " << res1 << " " << res2 << "\n";
    //         break;
    //     }
    //     else
    //     {
    //         std::cout << "'OK'\n";
    //         std::cout << "----------------------\n";
    //     }
    // }

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