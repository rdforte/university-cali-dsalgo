#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

class WeightedItem
{
public:
    double weight;
    double value;

public:
    WeightedItem(double val, double wei)
    {
        weight = wei;
        value = val;
    }

public:
    double getValuePerKG()
    {
        return value / weight;
    }
};

bool sortByHeighestValue(WeightedItem a, WeightedItem b)
{
    return a.getValuePerKG() > b.getValuePerKG();
}

int main()
{
    double nItems, capacity;
    std::cin >> nItems >> capacity;
    std::vector<WeightedItem> weightedItems;

    while (nItems--)
    {
        double val, wei;
        std::cin >> val >> wei;
        weightedItems.push_back(WeightedItem(val, wei));
    }

    std::sort(weightedItems.begin(), weightedItems.end(), sortByHeighestValue);

    double value = 0;

    for (int i = 0; i < weightedItems.size(); i++)
    {
        if (capacity == 0)
            break;
        WeightedItem item = weightedItems[i];
        if (capacity >= item.weight)
        {
            value += item.value;
            capacity -= item.weight;
        }
        else
        {
            double itemVal = item.getValuePerKG() * capacity;
            value += itemVal;
            capacity = 0;
        }
    }

    std::cout << std::fixed << std::setprecision(4) << value; // set precision to 4 decimal places

    return 0;
}