#ifndef _EXCEPT_H_
#define _EXCEPT_H_

#include <string>

class DSException
{
public:
    DSException(const std::string &msg):message_(msg) {}
    virtual ~DSException() {}
    virtual std::string toString() const
    {
        return "Exception :" + what();
    }
    virtual std::string what() const
    {
        return message_;
    }
private:
    std::string message_;
    
};

class DuplicateItemException:public DSException
{
public:
    DuplicateItemException(const std::string &msg=""):DSException(msg) {}
};

#endif

