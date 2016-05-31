/** @file Func_auxiliars.hh
    @brief Especificació de les funcions auxiliars.
*/
#ifndef Func_auxiliars_hh
#define Func_auxiliars_hh

#ifndef NO_DIAGRAM
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#endif

using namespace std;

    /** @brief Es normalitza l'string <em>linia</em>.
        \pre <em>Cert</em>.
        \post S'elimina el primer i últim caracter del string <em>linia</em>.
    */
    void normalitzar(string& linia);
    
    /** @brief El vector <em>v</em> passa a contenir cada una de les paraules que conté <em>paraules</em> com a elements.
        \pre El vector <em>v</em> inicialment està buit.
        \post El vector <em>v</em> passa a contenir cada una de les paraules que conté <em>paraules</em> com a elements.
    */
    void par_buscar(const string& paraules, vector<string>& v);

    /** @brief Retorna si el caràcter <em>c</em> és una lletra o un dígit.
        \pre <em>Cert</em>.
        \post Retorna si el caràcter <em>c</em> és una lletra o un dígit.
    */
    bool es_lletra(char c);

    /** @brief Retorna l'enter que representa l'string <em>s</em>.
        \pre L'string <em>s</em> és una cadena de dígits.
        \post Retorna l'enter que representa l'string <em>s</em>.
    */
    int fer_num(const string& s);

#endif
