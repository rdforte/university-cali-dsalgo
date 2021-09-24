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
        int minSteps = minPosition.steps + 1; // number of steps plus the current step in this case +1
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
        positions[i] = Position(minPosition.position, minSteps, i, operation);
    }


    Position lastPosition = positions[positions.size() -1];
    std::vector<int> increments(lastPosition.steps + 1); // the steps is always 1 less than the total number because we start at 1 which is not included as a step.

    increments[increments.size() - 1] = lastPosition.position;

    int comingFrom = lastPosition.comingFrom;
    int currentIndex = increments.size() - 1;

    for (int i = positions.size() - 1; i >= 1; i--)
    {
        if (positions[i].position == comingFrom) {
            increments[--currentIndex] = positions[i].position;
            comingFrom = positions[i].comingFrom;
        }
    }

    std::cout << lastPosition.steps << "\n";

    for (int i = 0; i < increments.size(); i++) {
        std::cout << increments[i] << "\n";
    }
}