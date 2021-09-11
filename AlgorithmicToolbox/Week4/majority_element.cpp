#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int nItems;
    std::cin >> nItems;
    std::vector<int> items;

    int largestItem = 0;

    while (nItems--)
    {
        int item;
        std::cin >> item;
        items.push_back(item);
    }

    std::sort(items.begin(), items.end());

    int previous = items[0];
    int count = 1;
    int isMajor = false;

    for (int i = 1; i < items.size(); i++)
    {
        if (items[i] == previous)
        {
            count++;
            if (count > (items.size() / 2))
            {
                isMajor = true;
                break;
            }
        }
        else
        {
            previous = items[i];
            count = 1;
        }
    }

    std::cout << (isMajor ? 1 : 0);
}
