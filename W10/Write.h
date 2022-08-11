#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
    class ReadWrite {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
        virtual ~ReadWrite()
        {
        }
    };
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
}
#endif