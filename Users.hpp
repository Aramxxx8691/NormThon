#ifndef USERS_HPP
# define USERS_HPP

# include <iostream>

class Users   {

public:
    void    setName(std::string s);
    void    setLogin(std::string s); 
    
    std::string getName(void) const;
    std::string getLogin(void) const;

private:
    std::string _name;
    std::string _login;
                };
#endif