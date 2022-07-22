#include <iostream>
#include <cmath>
#include <sys/types.h>
#include <unistd.h>

#define A -5.0;

int main()
{
    int x = A;

    std::cout << "Привет!" << std::endl;
    std::cout << "X = " << x << std::endl;
    std::cout << "PID: " << getpid() << std::endl;

    return 0;
}
