#include "NormThon.hpp"
#include <sys/signal.h>

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


void ctrl_c(int sig)
{
   std::cout << sig <<std::endl;
}

int main()
{
    signal(2,SIG_IGN);
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
