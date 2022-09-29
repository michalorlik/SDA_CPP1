#include <iostream>

void g()
{

}

void h()
{

}

void i()
{

}


void f(int n)
{
    switch (n)
    {
    case 1:
    case 2:
        g();
        [[fallthrough]];
    case 3: // no warning on fallthrough
        h();
    case 4: // compiler may warn on fallthrough
        if (n < 3)
        {
            i();
            [[fallthrough]]; // OK
        }
        else
        {
            return;
        }
    case 5:
        while (false)
        {
            [[fallthrough]]; // ill-formed: next statement is not
                             //             part of the same iteration
        }
    case 6:
        [[fallthrough]]; // ill-formed, no subsequent case or default label
    }
}

[[nodiscard]] std::string superFun()
{
    return "NIE INGNORUJ MNIE";
}

int main()
{
    //f(3);
    int x(10);

    [[maybe_unused]] bool b = true && false;
    
    std::cout << "Hello/n";

    superFun();

    return 0;
}