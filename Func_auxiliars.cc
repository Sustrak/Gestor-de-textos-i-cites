#include "Func_auxiliars.hh"

void normalitzar(string& linia)
{
  linia.erase(linia.begin());
  linia.erase(linia.end()-1);
}

vector<string> par_buscar(string paraules)
{
    istringstream iss(paraules);
    vector<string> paraules_buscar;
    string aux;
    while (iss >> aux) paraules_buscar.push_back(aux);
    return paraules_buscar;
}