#include <iostream>
#include <vector>
#include <cstdlib>

// int partition(std::vector<int> &vec, int leftIndex, int rightIndex)
// {
//     int comparison = vec[leftIndex];
//     int leftPointer = leftIndex;

//     for (int pointer = leftPointer + 1; pointer <= rightIndex; pointer++)
//     {
//         if (vec[pointer] <= comparison)
//         {
//             leftPointer++;
//             std::swap(vec[leftPointer], vec[pointer]);
//         }
//     }
//     std::swap(vec[leftIndex], vec[leftPointer]);
//     return leftPointer;
// }

class Partition
{
public:
    int lower;
    int upper;
    Partition(int l, int u)
    {
        lower = l;
        upper = u;
    }
};

Partition partition3(std::vector<int> &vec, int leftIndex, int rightIndex)
{
    int pivot = vec[leftIndex];
    int pivotLeftPointer = leftIndex;
    int pivotRightPointer = leftIndex;

    for (int pointer = pivotLeftPointer + 1; pointer <= rightIndex; pointer++)
    {
        if (vec[pointer] < pivot)
        {
            std::swap(vec[pointer], vec[pivotLeftPointer]);
            pivotLeftPointer++;
        }
        if (vec[pointer] == pivot)
        {
            pivotRightPointer++;
            std::swap(vec[pointer], vec[pivotRightPointer]);
        }
    }

    return Partition(pivotLeftPointer, pivotRightPointer);
};

void quickSort(std::vector<int> &vec, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
        return; // we only have one element so return

    int randomPivot = leftIndex + std::rand() % (rightIndex - leftIndex + 1);
    std::swap(vec[leftIndex], vec[randomPivot]); // swaps the left element with a random element in the vector

    Partition pivot = partition3(vec, leftIndex, rightIndex);
    quickSort(vec, pivot.upper + 1, rightIndex); // right sub array
    quickSort(vec, leftIndex, pivot.lower - 1);  // left sub array
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\n";
    }
}