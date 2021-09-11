#include <iostream>

int binarySearch(int items[], int lower, int upper, int item)
{
    if (upper >= lower)
    {

        int middle = (lower + upper) / 2;

        if (items[middle] == item)
            return middle;

        if (item > items[middle])
        {
            return binarySearch(items, middle + 1, upper, item); // is greater than the middle so we can say it is 1 greater than the middle
        }
        else
        {
            return binarySearch(items, lower, middle - 1, item); // does not equal middle so we can say the lower is one less than the middle
        }
    }

    return -1;
};

int main()
{
    int nItems;
    std::cin >> nItems;
    int items[nItems];

    for (int i = 0; i < nItems; i++)
    {
        int item;
        std::cin >> item;
        items[i] = item;
    }

    int nSearches;
    std::cin >> nSearches;

    while (nSearches--)
    {
        int search;
        std::cin >> search;

        if (search > items[nItems - 1] || search < items[0])
            std::cout << -1 << "\n";
        else
            std::cout << binarySearch(items, 0, nItems - 1, search) << "\n";
    }

    return 0;
}
