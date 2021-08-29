#include <iostream>
#include <vector>

int main()
{
    int cityDistance, maxFuelDistance, nGasStations;
    std::cin >> cityDistance >> maxFuelDistance >> nGasStations;

    std::vector<int> destinations;

    destinations.push_back(0);

    for (int i = 0; i < nGasStations; i++)
    {
        int gasStation;
        std::cin >> gasStation;
        destinations.push_back(gasStation);
    }
    destinations.push_back(cityDistance);

    int currentDesitinationIndex = 0;
    int numberOfStops = 0;
    bool isPossible = true;

    while (currentDesitinationIndex < destinations.size() - 1 && isPossible)
    {
        int nextStopIndex = currentDesitinationIndex;
        for (int i = currentDesitinationIndex + 1; i < destinations.size(); i++)
        {
            int currentDistanceFromLocation = destinations[i] - destinations[currentDesitinationIndex];

            // can not reac next destination so the journy is imposible
            if (currentDesitinationIndex + 1 == i && currentDistanceFromLocation > maxFuelDistance)
            {
                isPossible = false;
                break;
            }
            else if (currentDistanceFromLocation <= maxFuelDistance)
            {
                nextStopIndex = i;
            }
            else
                break;
        }
        currentDesitinationIndex = nextStopIndex;

        if (nextStopIndex < destinations.size() - 1)
            numberOfStops++;
    }

    std::cout << (isPossible ? numberOfStops : -1);
}