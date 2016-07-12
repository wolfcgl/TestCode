#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
using namespace std;

typedef enum {
    DEBUG_MSG =0,
    INFO_MSG,
    WARNING_MSG,
    ERROR_MSG,
} msg_level_t;

#ifdef _UNIT_TEST_

    #define DEBUG(msg_level, message, value) do {                                   \
        if (ERROR_MSG == msg_level) {                                               \
            cout << __FILE__ << "(" << __LINE__ << "):" << __FUNCTION__ << endl;    \
        }                                                                           \
        cout << message << ":" << value << endl;                                    \
    } while (false)

#else
    #define DEBUG(...)
#endif /*_UNIT_TEST_*/


#endif /* _UTIL_H_ */
