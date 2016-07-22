#include <iostream>
#include "nepen_form.hpp"

#include "nepen.hpp"

#include <memory>

#include <stdio.h>

// int main(int argc, const char *argv[])
int main()
{
    auto nep = std::make_unique<Nepen>();

    NepenForm fm(std::move(nep));

    fm.show();

    nana::exec();

    return 0;
}

// ☐ sowas...
// ☐ mehr davon
