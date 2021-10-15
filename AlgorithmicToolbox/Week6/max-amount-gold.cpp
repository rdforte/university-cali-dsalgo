#include <iostream>
#include <vector>

int main()
{
    int capacity, nItems;
    std::cin >> capacity >> nItems;

    std::vector<std::vector<int> > backpack(nItems);
    std::vector<int> weights(nItems);

    for (int i = 0; i < weights.size(); i++)
    {
        // setup weights
        std::cin >> weights[i];
        // setup backpack grid
        std::vector<int> v(capacity + 1, 0);
        backpack[i] = v;
    }

    for (int w = 0; w < weights.size(); w++)
    {
        for (int b = 0; b <= capacity; b++)
        {
            if (w > 0)
                backpack[w][b] = backpack[w - 1][b];

            if (b >= weights[w])
            {
                if (w == 0)
                {
                    backpack[w][b] = weights[w];
                    continue;
                }

                int leftOverCapacity = b - weights[w];
                int weightsForLeftOverCap = backpack[w - 1][leftOverCapacity];
                int totalWeightForCap = weights[w] + weightsForLeftOverCap;

                if (totalWeightForCap > backpack[w][b])
                {
                    backpack[w][b] = totalWeightForCap;
                }
            }
        }
    }

    std::cout << backpack[nItems - 1][capacity];
}