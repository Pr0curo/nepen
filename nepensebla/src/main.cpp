#include <iostream>
#include "nepen_form.hpp"

#include "nepen.hpp"

#include <memory>

#include <stdio.h>

#include "../sol2/sol.hpp"

// int main(int argc, const char *argv[])
int main()
{
    auto nep = std::make_unique<Nepen>();

    NepenForm fm(std::move(nep));

    fm.show();

    //--
    // sol::state lua;

    // int x=0;
    // lua.set_function("beep", [&x]{std::cout << "add one" << ++x << "\n";});
    // lua.script("beep()");

    // assert(x==1);

    // sol::function b = lua["beep"];
    // b();
    // assert(x==2);
    //--

    nana::exec();

    return 0;
}


