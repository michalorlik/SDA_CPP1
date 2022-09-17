#include <iostream>

[[deprecated("fizz() is problematic. Use buzz()")]]
void fizz(int x)
{
    std::cout << "fizz" << x <<std::endl;
}

void buzz(int x)
{
    std::cout << "buzz" << x << std::endl;
}

int main()
{
    fizz(17);

    buzz(13);

    int x = 7;

    std::auto_ptr<int> ptr(new int(7));
}
