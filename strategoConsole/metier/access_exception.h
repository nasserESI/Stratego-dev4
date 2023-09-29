#ifndef ACCESS_EXCEPTION_H
#define ACCESS_EXCEPTION_H
#include <exception>
#include <iostream>

namespace model
{
    /**
     * @brief this methode is set to put some bounds to the possibilities of the users
     * otherwise his going to cheat.
     *
     */
    class Access_exception : std::exception
    {
    private:
        std::string message;

    public:
        Access_exception(std::string message) : message(message) {}
        std::string getMessage();
    };
    inline std::string Access_exception::getMessage()
    {
        return this->message;
    }

}

#endif // ACCESS_EXCEPTION_H
