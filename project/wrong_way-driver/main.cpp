#include "app.hpp"
#include "yoshix_fix_function.h"

#include <ctime>

// -----------------------------------------------------------------------------

void main() {

    char select;
    std::cout << std::endl << std::endl;
    std::cout << "\t\t\tW R O N G - W A Y  D R I V E R  by Dariush Naghed" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "\t\t\t\tI N S T R U C T I O N S" << std::endl << std:: endl;
    std::cout << "\tUse the left and right Arrow Keys to dodge as many cars as possible! The cars will get faster over.   " << std::endl;
    std::cout << "\tYou have 3 Lives! Afer you hit the 4th car the game will be close." << std::endl;
    std::cout << "\tType s to start the game: ";
    std::cin >> select;

    if (select == 's')
    {
        CApplication app;
        gfx::RunApplication(800, 600, "GDV-Test", &app);
    }
}