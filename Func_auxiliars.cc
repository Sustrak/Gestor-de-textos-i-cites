#include "Func_auxiliars.hh"

void normalitzar(string& linia)
{
  linia.erase(linia.begin());
  linia.erase(linia.end()-1);
}
