# include "Users.hpp"

Users::Users(){_count = 0;}
std::string Users::getName() const  {return _name;}
std::string Users::getLogin() const {return _login;}
int         Users::getCount() const {return _count;}

void    Users::setName(std::string s)   {_name = s;}
void    Users::setLogin(std::string s)  {_login = s;}
void    Users::setCount(int s)          {_count = s;}
void    Users::incrementCount()         {_count++;}
void    Users::decrementCount()         {_count--;}
