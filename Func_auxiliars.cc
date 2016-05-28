/** @file Func_auxiliars.cc
    @brief Implementació de les funcions de Func_auxiliars.hh
*/

#include "Func_auxiliars.hh"

void normalitzar(string& linia)
{
  linia.erase(linia.begin());
  linia.erase(linia.end()-1);
}

void par_buscar(string paraules, vector<string>& v)
{
    istringstream iss(paraules);
    string aux;
    while (iss >> aux) v.push_back(aux);
}

bool es_lletra(char c)
{
    if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')) return true;
    else return false;
}

int fer_num(string& s)
{
	int n;
	istringstream iss(s);
	iss >> n;
    return n;
}
