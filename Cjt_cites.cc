/** @file Cjt_cites.cc
    @brief Implementació de les funcions de Cjt_cites.hh
*/

#include "Cjt_cites.hh"

Cjt_cites::Cjt_cites();
    
Cjt_cites::~Cjt_cites();
    
void Cjt_cites::afegir_cita(const Biblioteca& b, int x, int y);
 
void Cjt_cites::eliminar_cita(string ref);
    
bool Cjt_cites::te_cita(string ref);    
    
void Cjt_cites::info_cita(string ref);
    
void Cjt_cites::cites_autor(string autor);
    
void Cjt_cites::cites_text(const Biblioteca& b);
    
void Cjt_cites::totes_cites();
    
