# include "Users.hpp"

std::string Users::getName(void) const     {return _name;}
std::string Users::getLogin(void) const      {return _login;}

void    Users::setName(std::string s)      {_name = s;}
void    Users::setLogin(std::string s)       {_login = s;}
