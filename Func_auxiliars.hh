/** @file Func_auxiliars
    @brief Especificació de les funcions auxiliars
*/
#ifndef Func_auxiliars_hh
#define Func_auxiliars_hh

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/** @brief Normalitzar una string
    \pre <em>cert</em>
    \post Elimina el primer i últim caracter d'una string
*/

string normalitzar(string linia);
vector<string> par_buscar(string paraules);

#endif
