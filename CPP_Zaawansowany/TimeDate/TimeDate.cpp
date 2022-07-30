
#include <iostream>
#include <chrono>
#include <iomanip>

long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    auto start = std::chrono::steady_clock::now(); //pobiera aktualny time_point (jakas "magiczna" wartosc)
    std::cout << "fib(42) = " << fibonacci(42) << std::endl;
    auto end = std::chrono::steady_clock::now(); //pobiera drugi time_point po zkakonczeniu funkcji

    std::chrono::duration<double, std::milli> elapsed = end - start; 

    auto functionDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;

    // end - start zwraca std::chrono_duration dla nanosekund
    // konsertujemy ten wynik na milisekundy uzywajac std::chrono::duration_cast<std::chrono::milliseconds>
    // count zamienia std::chrono::miliseconds na long long (bo std::chrono::miliseconds nie ma operatora << (bedzie w C++20))
 
    std::cout << "Wyliczenie tego zajelo " << functionDuration << "s" << std::endl;
    std::cout << "Wyliczenie tego zajelo " << elapsed.count() << "ms" << std::endl;
}
