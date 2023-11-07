#ifndef USERS_HPP
# define USERS_HPP

# include <iostream>

class Users
{

public:
    Users();
    void    setName(std::string s);
    void    setLogin(std::string s);
    void    setCount(int s);
    void    incrementCount();
    void    decrementCount();
    
    std::string getName() const;
    std::string getLogin() const;
    int getCount() const;

private:
    std::string _name;
    std::string _login;
    int         _count;
};

#endif