#include <iostream>
#include <vector>
#include <cstdlib>

int partition(std::vector<int> &vec, int leftIndex, int rightIndex)
{
    int comparison = vec[leftIndex];
    int leftPointer = leftIndex;

    for (int pointer = leftPointer + 1; pointer <= rightIndex; pointer++)
    {
        if (vec[pointer] <= comparison)
        {
            leftPointer++;
            std::swap(vec[leftPointer], vec[pointer]);
        }
    }
    std::swap(vec[leftIndex], vec[leftPointer]);
    return leftPointer;
}

void quickSort(std::vector<int> &vec, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
        return; // we only have one element so return

    int pivotIndex = partition(vec, leftIndex, rightIndex);
    quickSort(vec, pivotIndex + 1, rightIndex); // right sub array
    quickSort(vec, leftIndex, pivotIndex - 1);  // left sub array
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
        std::cout << "--> " << a[i] << "\n";
    }
}