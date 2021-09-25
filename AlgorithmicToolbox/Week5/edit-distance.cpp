#include <iostream>
#include <vector>
#include <string>

int main() {
   std::string firstWord; // the coloumn of the graph
   std::string secondWord; // the row of the graph
   std::cin >> firstWord >> secondWord; 

    std::vector< std::vector<int> > graph(secondWord.size() + 1); // account for empty string comparison so plus 1

    std::vector<int> rowOne(firstWord.size() + 1); // account for empty string
   for (int i = 0; i < rowOne.size(); i++) {
      rowOne[i] = i;
   }

   graph[0] = rowOne;

   for (int i = 1; i < graph.size(); i++) {
    //    std::cout << "---> " << i << "\n";
        std::vector<int> vec(firstWord.size() + 1);
       for (int f = 0; f < vec.size(); f++) {
           if (f == 0) {
               // we are comparing against an empty string so total changes will be the index position in the graph
               vec[0] = i;
           } else {
            char firstWordChar = firstWord[f - 1];
            char secondWordChar = secondWord[i - 1];

            if (secondWordChar == firstWordChar) {
                vec[f] = graph[i - 1][f - 1]; // if its the same then add the diagonal as there are no insertions, deletions or swaps.
            } else {
                std::vector<int> manipulations(3);
                int up = graph[i - 1][f];
                manipulations[0] = up;
                int diagonal = graph[i - 1][f - 1];
                manipulations[1] = diagonal;
                int left = vec[f - 1];
                manipulations[2] = left;
                // calculate the min
                int min = manipulations[0];
                for (int m = 1; m < manipulations.size(); m++) {
                    if (manipulations[m] < min) {
                        min = manipulations[m];
                    }
                }
                // becuase we are performing a manipulation we add 1
                vec[f] = min + 1;
            }
           }
       }
       graph[i] = vec;
   }

    std::cout << graph[graph.size() -1][firstWord.size()];
}