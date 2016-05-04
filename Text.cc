/** @file Text.cc
    @brief Implementació de les funcions de Text.hh
*/

#include "Text.hh"

Text::Text();

Text::Text(string titol);

Text::~Text();

int Text::n_frases();

int Text::n_paraules();

bool Text::conte_paraules(const string& paraules);

void Text::afegir_contingut(int x, int y, Cita& cita);

void Text::escriure_contingut();
