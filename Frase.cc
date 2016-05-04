/** @file Frase.cc
    @brief Implementació de les funcions de Frase.hh
*/

#include "Frase.hh"

Frase::Frase ();

Frase::~Frase ();

void Frase::llegir(string& linia);

void Frase::substitueix (string par1, string par2);

int Frase::n_paraules();

void Frase::escriure();
