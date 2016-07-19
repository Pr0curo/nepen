#include <iostream>
#include "nepen_form.hpp"

#include "nepen.hpp"

#include <memory>

#include "wren.h"

// int main(int argc, const char *argv[])
int main()
{
    auto nep = std::make_unique<Nepen>();

    NepenForm fm(std::move(nep));

    fm.show();

    WrenConfiguration config;
    wrenInitConfiguration(&config);

    WrenVM* vm = wrenNewVM(&config);

    WrenInterpretResult result = wrenInterpret(vm, "System.print(\"Hi!\")");


    nana::exec();

    wrenFreeVM(vm);


    return 0;
}

// ☐ sowas...
// ☐ mehr davon
