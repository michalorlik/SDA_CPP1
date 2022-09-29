#include <iostream>
#include <optional>

std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {}; //to samo co std::nullopt
}

auto create2(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}


int main()
{
    auto opt = create(false);

    if (opt.has_value())
    {
        std::cout << opt.value() <<std::endl;
    }
    else
    {
        std::cout << "Optional byl pusty";
    }
}
