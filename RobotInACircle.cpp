/*
* Making sure the simulation code is correct turns out to be very important!
*
* Got a funny runtime result again
* https://i.imgur.com/b1I9Y4C.png
*
* John Nguyen
* 07.16.2021
*/


#include<stdlib.h>
#include<string>
#include<iostream>

void rotate(int* x, int dir) {
    *x = (*x + dir) % 4;

    if (*x < 0) {
        *x = 3;
    }
}

class Solution {
public:
    bool isRobotBounded(std::string instructions) {
        // Not sure of any existing classes that support mathematical vector operations
        std::pair<int, int> startPosition{0, 0};
        std::pair<int, int> currentPosition{0, 0};
        int direction = 0; // 0: N, 1: W, 2: S, 3:E

        for (int j = 0; j < instructions.length(); j++) {
            switch (instructions.at(j)) {
                case 'G':
                    switch (direction) {
                        case 0:
                            currentPosition.second++;
                            break;
                        case 1:
                            currentPosition.first--;
                            break;
                        case 2:
                            currentPosition.second--;
                            break;
                        case 3:
                            currentPosition.first++;
                            break;
                    }
                    break;
                case 'L':
                    rotate(&direction, 1);
                    break;
                case 'R':
                    rotate(&direction, -1);
                    break;
            }

            // std::printf("I: %c P: (%d, %d) D: %d\n", instructions.at(j),
            //     currentPosition.first, currentPosition.second,
            //     direction
            // );
        }

        // std::printf("P: (%d, %d) D: %d\n", 
        //     currentPosition.first, currentPosition.second,
        //     direction
        // );

        if (currentPosition.first == startPosition.first
            && currentPosition.second == startPosition.second) {
            return true;

        } else {
            return direction != 0;
        }
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    std::cout << sol.isRobotBounded("GGLLGG") << "\n";
    std::cout << sol.isRobotBounded("GG") << "\n";
    std::cout << sol.isRobotBounded("GL") << "\n";
    std::cout << sol.isRobotBounded("GLL") << "\n";
    std::cout << sol.isRobotBounded("GLGLGGLGL") << "\n";
    std::cout << sol.isRobotBounded("LLGRL") << "\n";

    return 0;
};