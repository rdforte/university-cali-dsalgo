#include <iostream>
#include <vector>

class Position
{
public:
    int comingFrom;
    int steps;
    /**
     * 0 = no operation
     * 1 = +1
     * 2 = *2
     * 3 = *3
    */
    int operation;
    int position; // the current position/index

public:
    Position(int _comingFrom, int _steps, int _position, int _operation)
    {
        comingFrom = _comingFrom;
        steps = _steps;
        position = _position;
        operation = _operation;
    }
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<Position> positions(n + 1, Position(0, 0, 0, 0));
    int operations[3] = {1, 2, 3}; // plus 1, x2, x3;

    positions[1] = Position(0, 0, 1, 0);

    for (int i = 2; i < positions.size(); i++)
    {
        Position minPosition = positions[i - operations[0]];
        std::cout << "minPosition: " << minPosition.position << "\n";
        int minSteps = minPosition.steps + 1; // number of steps plus the current step in this case +1
        std::cout << "minSteps: " << minSteps << "\n";
        int operation = 1;
        for (int op = 1; op < 3; op++)
        {
            if (op == 1)
            {
                int remainderOperation = i % operations[op];
                int divisibleBy = i / operations[op];
                int operationSteps = positions[divisibleBy].steps;
                int totalSteps = operationSteps + 1 + remainderOperation;
                if (totalSteps < minSteps)
                {
                    minPosition = positions[divisibleBy];
                    minSteps = totalSteps;
                    operation = operations[op];
                }
            }
            else if (op == 2)
            {
                int remainderOperation = i % operations[op];
                int divisibleBy = i / operations[op];
                int operationSteps = positions[divisibleBy].steps;
                int totalSteps = operationSteps + 1 + remainderOperation;
                if (totalSteps < minSteps)
                {
                    minPosition = positions[divisibleBy];
                    minSteps = totalSteps;
                    operation = operations[op];
                }
            }
        }
        std::cout << "---------------------------------\n";
        positions[i] = Position(minPosition.position, minSteps, i, operation);
    }

    for (int i = 1; i < positions.size(); i++)
    {
        std::cout << positions[i].position << " " << positions[i].steps << " " << positions[i].comingFrom << " " << positions[i].operation << "\n";
    }

    // What is left:
    // 1. starting from the last item I need to map it backwards to the 'comingFrom' along with the operation.
    // 2. put these values into a vector with the first operation ie: 1 at the start.
    // 3. loop through the vector logging out the values.

    /**
     * NOTE: Look in notebook
    */
}