/** @file Cjt_textos.cc
    @brief Implementació de les funcions de Cjt_textos.hh
*/

#include "Cjt_textos.hh"

Cjt_textos::Cjt_textos();
    
Cjt_textos::~Cjt_textos();
    
void Cjt_textos::afegir_text(string titol, Text text);
    
void Cjt_textos::eliminar_text(); 

void Cjt_textos::triar_text(bool& trobat, const vector<string>& paraules);

void Cjt_textos::buscar_text(bool& trobat, const vector<string>& paraules);

void Cjt_textos::substitueix (string par1, string par2);
    
void Cjt_textos::escriure_titols();
