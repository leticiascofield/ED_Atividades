#include <iostream>
#include <chrono>
#include <time.h>
#include <cmath>

using namespace std;
using namespace std::chrono;

//iterativo
int Fat (int n) {
    int fat = 1;
    while(n > 0){
        fat *= n;
        n--;
    }
    return fat;
}

int main(int argc, char* argv[]) {

    int n;
    if (argc > 1) {
        n = std::atoi(argv[1]);
    }

    struct timespec realBegin, realEnd, userBegin, userEnd, sysBegin, sysEnd; 
    clock_gettime(CLOCK_REALTIME, &realBegin);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &userBegin);
    clock_gettime(CLOCK_BOOTTIME, &sysBegin);

    int result = Fat(n);

    clock_gettime(CLOCK_REALTIME, &realEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &userEnd);
    clock_gettime(CLOCK_BOOTTIME, &sysEnd);

    std::cout << "Fatorial de " << n << ": " << result << std::endl;

    long nanoseconds = realEnd.tv_nsec - realBegin.tv_nsec;
    std::cout << "Tempo de relógio: " << nanoseconds << "ns" << std::endl;

    nanoseconds = userEnd.tv_nsec - userBegin.tv_nsec;
    std::cout << "Tempo de usuário: " << nanoseconds << "ns" << std::endl;

    nanoseconds = sysEnd.tv_nsec - sysBegin.tv_nsec;
    std::cout << "Tempo do sistema: " << nanoseconds << "ns" << std::endl;

    return 0;
}
