#include <iostream>
#include <vector>

/**
 * NOTES:
 * if for my current currency I only had a 1, 3 and 4 cent coin then how would I know that to make 8 cents the best/optimal solution would be to use 2 x 4cent pieces?
 * by subtracting 4cents from 8 I can see that to make 4cents only took 1 coin.
 * so in order to make 4 cents i would just add 1 coin. In this case it would be a 4cent coin.
 * 
 * if i subtract 3cents from 8 I can see that in order to make 5 cents it takes 2 coins. 
 * so therefore if I add 1 coin (3cent piece) to 5 this would be a total of 3 coins and that would not be optimal
*/

int main()
{
    int totalMoney;
    std::cin >> totalMoney;
    std::vector<int> money(totalMoney + 1, 0); // start from 1 cent

    std::vector<int> coins(3);
    coins[0] = 1;
    coins[1] = 3;
    coins[2] = 4;

    for (int m = 1; m < money.size(); m++)
    {
        int minNumCoins = money[m - coins[0]] + 1;
        for (int c = 1; c < coins.size(); c++)
        {
            int moneyIndex = m - coins[c];
            if (moneyIndex >= 0)
            {
                int currentMinCoin = money[moneyIndex] + 1;
                if (currentMinCoin < minNumCoins)
                {
                    minNumCoins = currentMinCoin;
                };
            }
        }
        money[m] = minNumCoins;
    }

    std::cout << money[totalMoney];
}