#ifndef __LISTEXCEPTION_H__
#define __LISTEXCEPTION_H__

#include <string>
#include <exception>


class ListException : public std::exception{
  
  private:
    std::string msg;

  public:
    explicit ListException(const char* message) : msg(message){}
    explicit ListException(const std::string& message) : msg(message){}
    virtual ~ListException() throw () {}
    virtual const char* what() const throw () {
      return msg.c_str();
    }
};


#endif // __LISTEXCEPTION_H__