#include "xhk.h"

// #include <chaiscript/chaiscript.hpp>

static const char *license_note =
    "cross platform hotkey daemon\n"
    "Copyright (C) 2021  Lian Studer\n\n"

    "This program is free software: you can redistribute it and/or modify\n"
    "it under the terms of the GNU General Public License as published by\n"
    "the Free Software Foundation, either version 3 of the License, or\n"
    "(at your option) any later version.\n"
    "This program is distributed in the hope that it will be useful,\n"
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    "GNU General Public License for more details.\n\n"

    "You should have received a copy of the GNU General Public License\n"
    "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

int main(int argc, char **argv)
{
    // chaiscript::ChaiScript chai;
    // chai.add(chaiscript::fun(&print_info), "print_info");
    // chai.eval(R"(
    //     print_info();
    // )");
    print_info();
    return EXIT_SUCCESS;
}

void print_info()
{
    std::cout << "xhk - version "
              << xhk_VERSION_MAJOR << "."
              << xhk_VERSION_MINOR << "."
              << xhk_VERSION_PATCH << "\n"
              << license_note << std::endl;
}