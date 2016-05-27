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
