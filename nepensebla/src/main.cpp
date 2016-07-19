#include <iostream>
#include "nepen_form.hpp"

#include "nepen.hpp"

#include <memory>

#include "lua.hpp"

#include <stdio.h>

// int main(int argc, const char *argv[])
int main()
{
    lua_State *L;
    L = luaL_newstate();
    luaL_openlibs(L);

    auto status = luaL_loadfile(L, "script.lua");
    if(status)
    {
        std::cout << "fehler beim laden " << lua_tostring(L, -1);
    }

//---------------------------------------------------------------------------------------------------------------------

    lua_newtable(L);    /* We will pass a table */

    for (int i = 1; i <= 5; i++) {
        lua_pushnumber(L, i);   /* Push the table index */
        lua_pushnumber(L, i*2); /* Push the cell value */
        lua_rawset(L, -3);      /* Stores the pair in the table */
    }

    /* By what name is the script going to reference our table? */
    lua_setglobal(L, "foo");

    /* Ask Lua to run our little script */
    auto result = lua_pcall(L, 0, LUA_MULTRET, 0);
    if (result) {
        fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
        exit(1);
    }

    /* Get the returned value at the top of the stack (index -1) */
    auto sum = lua_tonumber(L, -1);

    std::cout << "Script returned: " << sum << "\n";

    lua_pop(L, 1);  /* Take the returned value out of the stack */

//---------------------------------------------------------------------------------------------------------------------


    auto nep = std::make_unique<Nepen>();

    NepenForm fm(std::move(nep));

    fm.show();

    nana::exec();

    lua_close(L);

    return 0;
}

// ☐ sowas...
// ☐ mehr davon
