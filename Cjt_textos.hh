/** @file Cjt_textos.hh
    @brief Especificació de la classe Cjt_textos. 
*/

#ifndef Cjt_textos_hh
#define Cjt_textos_hh

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <iostream>
#endif

#include "Text.hh"
#include "Cita.hh"
using namespace std;

class Cjt_textos {
	
    /** @class Cjt_textos
        @brief Representa un conjunt de textos.
    */

private:
    map<string, Text>::iterator _text_triat;
    map<string, Text> _textos;              //string conté el títol del Text
    int _n_frases;
    int _n_paraules;
    
public:

  //Constructora 

    /** @brief Creadora per defecte.
        S'executa automaticament al declarar un conjunt de textos.
        \pre <em>Cert</em>.
        \post El resultat és un conjunt de textos sense textos.
    */
    Cjt_textos();
    
  //Destructora

    /** @brief Destructora per defecte.
    */  
    ~Cjt_textos();
    
  //Modificadores

    /** @brief Afegeix un text al conjunt.
        \pre No existeix un text amb el títol <em>titol<em/> al conjunt.
        \post El p.i. conté el textos inicials més el text amb el títol <em>titol</em>.
    */
    void afegir_text(string titol);
    
    /** @brief Elimina el text triat al parametre implícit.
        \pre Hi ha un text triat.
        \post El p.i. conté el textos inicials menys el text triat originalment.
    */
    void eliminar_text(); 
    
    /** @brief <em>c</em> té el títol i les frases de la x-éssima a la y-essima del text triat al paràmetre implícit.
        \pre Hi ha un text triat, x<=y.
        \post <em>c</em> té el títol i les frases de la x-éssima a la y-essima del text triat al p.i.
    */
    void modificar_cita(Cita& c, int x, int y);
    
    /** @brief Busca i tria el primer text del paràmetre implícit que conté les paraules de <em>paraules</em>.
        \pre <em>Cert</em>.
        \post Si en conté, es tria el primer text que conté les paraules de <em>paraules</em> i <em>trobat</em> té el valor contrari al original. Altrament, <em>trobat</em> es manté com originalment.
    */
    void triar_text(bool& trobat, const vector<string>& paraules);
    
    /** @brief Busca s'hi ha un text al paràmetre implícit posterior al triat que conté les paraules de <em>paraules</em>.
        \pre <em>Cert</em>.
        \post Si hi ha un text al paràmetre implícit posterior al triat que conté les paraules de <em>paraules</em>,  <em>trobat</em> té el valor contrari al original. Altrament, <em>trobat</em> es manté com originalment.
    */
    void buscar_text(bool& trobat, const vector<string>& paraules);
    
    /** @brief Substitueix una paraula per una altre en el text triat.
        \pre Hi ha un text triat.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el text triat.
    */
    void substitueix (string par1, string par2);
    
  //Consultores
    
    /** @brief <em>títol</em> conté el títol del text triat al paràmetre implícit.
        \pre Hi ha un text triat.
        \post <em>títol</em> conté el títol del text triat al p.i.
    */
    void titol_triat(string& titol);
    
    /** @brief Retorna per referencia el text triat
     \pre Hi ha un text triat
     \post Retorna per referencia el text triat
     */
    void text_triat(Text& text);

  //Escriptura
    
    /** @brief S'escriuen els títols dels textos del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriuen pel canal estàndard de sortida el títol de tots els textos del p.i. ordenats alfabèticament.
    */   
    void escriure_titols();
    
    /** @brief S'secriuen el nombre de títols del paràmetre implicit, el nombre de frases i paraules
        \pre <em>Cert</em>
        \post S'ecriuen pel canal estàndard de sortida el nombre de titols, frases i paraules del p.i
     */
    
    void escriure_info();
    
    /** @brief Escriu el títol, nombre de frases i paraules del text triat
        \pre Hi ha un text triat
        \post S'esciuen pel canal estàndard de sortida el títol i el nombre de frases i paraules del text triat
     */
    void escriure_info_triat();
    
    /** @brief Escriu el contingut del text triat si tot es cert altrament escriurà només les frases de la x a la y
        \pre Hi ha un text triat
        \post S'escriu pel canal estàndard de sortida el contingut del text triat si tot es cert altrament s'escriu de la frase x al la frase y
     */
    void escriure_contringut(bool tot, int x, int y);
    
    /** @brief Escriu el nombre de frases de l'ultim text triat
        \pre Hi ha un text triat
        \post S'escriu pel canal estàndard de sortida el nobre de frases del text triat
     */
    void escriure_nombre_frases();
    
    /** @brief Escriu el nombre de paraules de l'ultim text triat
     \pre Hi ha un text triat
     \post S'escriu pel canal estàndard de sortida el nobre de paraules del text triat
     */
    void escriure_nombre_paraules();
    
    /** @brief S'escriuen les frases del contingut del text triat que contenen la seqüència de paraules.
     \pre <em>Cert</em>
     \post S'escriuen les frases del contingut del text triat que contenen la seqüència de paraules pel canal estàndard de sortida.
     */
    void frases_paraules(vector<string> paraules);
};

#endif /* Cjt_textos_hh */
