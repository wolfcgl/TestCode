#include <iostream>

#include <sys/types.h>
#include <stdarg.h>
#include <vector>
#include <algorithm>
#include "geometric/Point.h"
#include "util.h"

using namespace std;
using namespace NS_GEOMETRIC;

void stdarg_func(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    cout << va_arg(ap, int) << ", " << va_arg(ap, int) << endl;
}

void printInt(int a)
{
    cout << a << " ";
}

int main()
{
    Point<int> p1(1, 2);
    Point<double> p2(2.3, 5.6);
    Point<int> p3(1, 2);
    Point<int> p4(2, 2);

    cout << "p1(" << p1.x << "," << p1.y << ")" << endl;
    cout << "p2(" << p2.x << "," << p2.y << ")" << endl;

    if (p1 == p3) {
        cout << "p1==p3" << endl;
    }

    if (p1 != p4) {
        cout << "p1!=p4" << endl;
    }

    Point<int> p5 = p1 + p3;
    cout << "p5(" << p5.x << "," << p5.y << ")" << endl;

    Point3D<int> p6(1,2,3);
    Point3D<int> p7(4,5,6);
    cout << "p6(" << p6.x << "," << p6.y << "," << p6.z << ")" << endl;
    cout << "p7(" << p7.x << "," << p7.y << "," << p7.z << ")" << endl;
    if (p6 == p7) {
        cout << "p6==p7" << endl;
    }
    if (p6 != p7) {
        cout << "p6!=p7" << endl;
    }

    int a = 1;
    msg_level_t level = ERROR_MSG;
    DEBUG(INFO_MSG, "a", a);
    stdarg_func("test", 2, 3);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    for_each(v.begin(), v.end(), [](int a){cout << a << " ";});
    cout << endl;

    return 0;
}
