#include <iostream>
#include <cmath>


int Fib(int n) {
   if (n <= 2) 
      return 1;
   else
      for(int i=0; i < 10000000; i++){
            sin(n);
      }
      return Fib(n-1) + Fib(n-2);
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

    int result = Fib(n);

    clock_gettime(CLOCK_REALTIME, &realEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &userEnd);
    clock_gettime(CLOCK_BOOTTIME, &sysEnd);

    std::cout << "Fibonacci " << n << ": " << result << std::endl;

    long nanoseconds = realEnd.tv_nsec - realBegin.tv_nsec;
    std::cout << "Tempo de relógio: " << nanoseconds << "ns" << std::endl;

    nanoseconds = userEnd.tv_nsec - userBegin.tv_nsec;
    std::cout << "Tempo de usuário: " << nanoseconds << "ns" << std::endl;

    nanoseconds = sysEnd.tv_nsec - sysBegin.tv_nsec;
    std::cout << "Tempo do sistema: " << nanoseconds << "ns" << std::endl;

    return 0;
}