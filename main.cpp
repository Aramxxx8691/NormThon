#include "NormThon.hpp"

void    display()
{   std::cout << BOLDRED << " _____________________ " << std::endl
    << "/" << YELLOW << "   🅝 🅞 🅡 🅜 🅣 🅞 🅗 🅝   " << RED "\\" << std::endl
    << "|" << YELLOW << "       /      \\      " << RED "|" << std::endl
    << "|" << YELLOW << "      /  "<<RED"EXIT"<<YELLOW"  \\     " << RED "|" << std::endl
    << "|" << YELLOW << "     /          \\    " << RED "|" << std::endl
	<< RED << "| " 
    << GREEN << " START  " << CYAN << "     LEVEL " << RED
    << " |" << std::endl << "\\_____________________/" << std::endl;
}

int main()
{
    NormThon norm;
    std::string cmd;

    display();

    while (1)
    {
        std::cout << BOLDCYAN "Norm" << GREEN "Thon:$ " << WHITE;
        getline(std::cin, cmd);
        if (std::cin.eof())
            break ;
        if (cmd == "START" || cmd == "1")
            norm.start();
        else if (cmd == "LEVEL" || cmd == "2")
            norm.level();
        else if (cmd == "EXIT" || cmd == "3")
            break ;
        else
            std::cout << RED "❌ WRONG COMMAND" << std::endl;
    }
    std::cout << std::endl; 
    std::cout << MAGENTA "NORMTHON closed" << std::endl;
    return 0;
}
