#include "pch.h"
#include "TableLookup.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//using namespace winrt;
//using namespace Windows::Foundation;

int main(int argc, char* argv[])
{
    //init_apartment();
    //Uri uri(L"http://aka.ms/cppwinrt");
    //printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
    //_sleep(1000);
    std::vector<std::string> properties{ "T", "h", "Pr", "u", "vr", "s" };
    Lookup::PropertyNames Pn=Lookup::T;
    
    std::string props;
    std::cout << "Properties : ";
    std::cin >> props;
    for (int i = 0; i < properties.size(); ++i) {
        if (props == properties[i])
            Pn = static_cast<Lookup::PropertyNames>(i);
    }

    double val;
    std::cout << "Value : ";
    std::cin >> val;
    
    

    Lookup::TableLookup table;
    const auto [temperature, enthalpy, relativePressure, internalEnergy, relativeVolume, entropy] = table.Lookup(Pn, val);
    
    std::cout << "Temperature : " << temperature << '\n'
        << "Enthalpy : " << enthalpy << '\n'
        << "relativePressure : " << relativePressure << '\n'
        << "internalEnergy : " << internalEnergy << '\n'
        << "relativeVolume : " << relativeVolume << '\n'
        << "entropy : " << entropy << std::endl;

    _sleep(10000);
    return EXIT_SUCCESS;
}
