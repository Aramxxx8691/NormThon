#include "NormThon.hpp"

NormThon::NormThon(){_current = 0; _index = 0;}
NormThon::~NormThon(){}

void    empty(std::string &str, std::string display)
{
    std::cout << CYAN << display << WHITE;
    do
    {
        getline(std::cin, str);
        if (std::cin.eof())
            break ;
        if (str.empty())
            std::cout << RED "Empty line, fill it 👉 " WHITE;
    }
    while (str.empty());
}

bool only_letters(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
        if (!std::isalpha(str[i]))
            return false;
    return true;
}

void get_input(std::string &str, const std::string &display, bool (*checker)(const std::string&))
{
    std::cout << CYAN << display << WHITE;
    do
    {
        getline(std::cin, str);
        if (std::cin.eof())
            break ;
        if (str.empty())
            std::cout << RED "Empty line, fill it 👉 " WHITE;
        else if (!checker(str))
            std::cout << RED "Invalid input, try again 👉 " WHITE;
    }
    while (str.empty() || !checker(str));
}

void copyFile(const std::string& srcpath, const std::string& dest)
{
    std::string cmd = "cp " + srcpath + " " + dest;
    int res = std::system(cmd.c_str());
    if (res == 0)
        std::cout << "File copied successfully." << std::endl;
    else
        std::cerr << "File copy failed." << std::endl;
}

bool runNorminette(const std::string &filePath, Users &tmp)
{
    std::string command = "norminette " + filePath;
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Error: Failed to run Norminette." << std::endl;
        return false;
    }
    char buffer[128];
    std::string output = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            output += buffer;
    }
    pclose(pipe);
    if (output.find("Error!") != std::string::npos)
    {
        std::cout << output << std::endl;
        tmp.decrementCount();
        return false;
    }
    else if (output.find("OK!") != std::string::npos)
    {
        tmp.incrementCount();
        return true;
    }
    else
        return false;
}

void    NormThon::start()
{
    Users       tmp;
    std::string str;
    get_input(str, "Name: ", only_letters);
    tmp.setName(str);
    get_input(str, "Login: ", only_letters);
    tmp.setLogin(str);
    this->_user[_current % 1] = tmp;
    this->_current++;
    if (this->_current <= 1)
        this->_index = this->_current;
    std::cout << YELLOW << "*------ADDED-------*" << RESET << std::endl;
    std::vector<std::string> src;
    src.push_back("ft_isalpha.c");
    // src.push_back("ft_isalnum.c");
    // src.push_back("ft_isascii.c");
    std::string dst = "Rendu/NormMe.c";
    for (std::vector<std::string>::iterator it = src.begin(); it != src.end(); ++it)
    {
        std::string srcpath = "Codes/" + *it;
        copyFile(srcpath, dst);

        std::string cmd;
        while (true)
        {
            std::cout << BOLDCYAN << "Just do " << GREEN << "norm: " << RESET;
            if (std::cin.eof())
                break ;
            std::cin >> cmd;
            if (cmd == "norm")
                break;
        }
        while (cmd == "norm")
        {
            if (runNorminette(dst, _user[_current]))
            {
                std::cout << BOLDMAGENTA << "Norminette check passed for " << YELLOW << *it << RESET << std::endl;
                break;
            }
            else
            {
                while (true)
                {
                    std::cout << BOLDCYAN << "Just do " << GREEN << "norm: " << RESET;
                    if (std::cin.eof())
                        break ;
                    std::cin >> cmd;
                    if (cmd == "norm")
                        break;
                }
            }
        }
        if (it + 1 == src.end())
            std::cout << BOLDCYAN << "Level 1 passed." << RESET << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "❌ " << _user[1].getCount() << std::endl;
}

std::string resize(std::string str)
{
    if (str.length() > 10)
    {
        str.erase(str.begin() + 9, str.end());
        str.append(".");   
    }
    return (str);
}

void    NormThon::level()
{
    unsigned int    i;
    std::cout << _user[0].getCount() << std::endl;
    std::cout << GREEN "Enter the index " << WHITE;
    std::cin >> i;
    if (std::cin.fail())
        std::cout << RED << "TRY AGAIN " << WHITE << std::endl;
    else
    {
        if (i < this->_index)
        {
            std::cout << "Name: " << this->_user[i].getName() << std::endl;
            std::cout << "Login: " << this->_user[i].getLogin() << std::endl;
            std::cout << "Point: " << this->_user[i].getCount() << std::endl;
        }
        else
            std::cout << RED << "TRY AGAIN " << WHITE << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}
 