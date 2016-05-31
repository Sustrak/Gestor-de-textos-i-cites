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
#include "Taula_freq.hh"
using namespace std;

class Cjt_textos {
	
    /** @class Cjt_textos
        @brief Representa un conjunt de textos.
    */

private:
	/** @brief Si hi ha un text triat i correspon a aquest conjunt de textos, apunta al text triat  */
    map<string, Text>::iterator _text_triat;
	/** @brief Map que conté els textos d'un autor.

      Ordenat alfabèticament per títol. La clau són strings que contenen els títols i el valor és un element Text que correspon al text de la clau. */
    map<string, Text> _textos;
	/** @brief Indica el nombre de frases que tenen entre tots els textos del conjunt  */    
    int _n_frases;
	/** @brief Indica el nombre de paraules que tenen entre tots els textos del conjunt  */    
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
    void afegir_text(string& titol);
    
    /** @brief Elimina el text triat al parametre implícit.
        \pre Hi ha un text triat.
        \post El p.i. conté el textos inicials menys el text triat originalment.
    */
    void eliminar_text(); 
    
    /** @brief Busca i tria el primer text del paràmetre implícit que conté les paraules de <em>paraules</em>.
        \pre <em>Cert</em>.
        \post Si en conté, es tria el primer text que conté les paraules de <em>paraules</em> i <em>trobat</em> té el valor contrari al original. Altrament, <em>trobat</em> es manté com originalment.
    */
    void triar_text(bool& trobat, const vector<string>& paraules, string& autor);
    
    /** @brief Substitueix una paraula per una altre en el text triat.
        \pre Hi ha un text triat.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el text triat.
    */
    void substitueix (const string& par1, const string& par2);
    
  //Consultores
    
    /** @brief Busca s'hi ha un text al paràmetre implícit posterior al triat que conté les paraules de <em>paraules</em>.
     \pre <em>Cert</em>.
     \post Si hi ha un text al paràmetre implícit posterior al triat que conté les paraules de <em>paraules</em>,  <em>trobat</em> té el valor contrari al original. Altrament, <em>trobat</em> es manté com originalment.
     */
    void buscar_text(bool& trobat, const vector<string>& paraules, string& autor) const;
    
    /** @brief Retorna per referencia la taula de freqüències del text triat.
     \pre Hi ha un text triat.
     \post Retorna per referencia la taula de freqüències del text triat.
     */
    void fer_taula(Taula_freq& t) const;
    
    /** @brief Retorna si el paràmetre implícit conté textos.
     \pre <em>Cert</em>.
     \post Retorna true si el p.i és buit altrament retorna false.
     */
    bool es_buit() const;
    
    /** @brief Retorna per referencia el títol del text triat.
     \pre Hi ha un text triat.
     \post Retorna per referencia el títol del text triat.
     */
    void titol_triat(string& titol) const;
    
    /** @brief <em>c</em> té el títol i les frases de la x-éssima a la y-essima del text triat al paràmetre implícit.
        \pre Hi ha un text triat, x<=y.
        \post <em>c</em> té el títol i les frases de la x-éssima a la y-essima del text triat al p.i.
    */
    void modificar_cita(Cita& c, int x, int y) const;
    
  //Escriptura
    
    /** @brief S'escriuen els títols dels textos del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriuen pel canal estàndard de sortida el títol de tots els textos del p.i. ordenats alfabèticament.
    */   
    void escriure_titols(string& autor, bool tots) const;
    
    /** @brief S'secriuen el nombre de títols del paràmetre implicit, el nombre de frases i paraules
        \pre <em>Cert</em>
        \post S'ecriuen pel canal estàndard de sortida el nombre de titols, frases i paraules del p.i
     */
    
    void escriure_info() const;
    
    /** @brief Escriu el títol, nombre de frases i paraules del text triat
        \pre Hi ha un text triat
        \post S'escriuen pel canal estàndard de sortida el títol i el nombre de frases i paraules del text triat
     */
    void escriure_info_triat() const;
    
    /** @brief Escriu el títol del text triat
        \pre Hi ha un text triat
        \post S'escriu pel canal estàndard de sortida el títol del text triat
     */
    void escriure_titol_triat() const;
    
    /** @brief Escriu el contingut del text triat si tot es cert altrament escriurà només les frases de la x a la y
        \pre Hi ha un text triat
        \post S'escriu pel canal estàndard de sortida el contingut del text triat si tot es cert altrament s'escriu de la frase x al la frase y
     */
    void escriure_contingut(bool tot, int x, int y) const;
    
    /** @brief Escriu el nombre de frases de l'ultim text triat
        \pre Hi ha un text triat
        \post S'escriu pel canal estàndard de sortida el nombre de frases del text triat
     */
    void escriure_nombre_frases() const;
    
    /** @brief Escriu el nombre de paraules de l'ultim text triat
     \pre Hi ha un text triat
     \post S'escriu pel canal estàndard de sortida el nobre de paraules del text triat
     */
    void escriure_nombre_paraules() const;

    /** @brief S'escriuen les frases del contingut del text triat que compleixen l'expressió.
     \pre <em>Cert</em>
     \post S'escriuen les frases del contingut del text triat que compleixen l'expressió pel canal estàndard de sortida.
     */
    void frases_expressio(string& expressio) const;
    
    /** @brief S'escriuen les frases del contingut del text triat que contenen la seqüència de paraules.
     \pre <em>Cert</em>
     \post S'escriuen les frases del contingut del text triat que contenen la seqüència de paraules pel canal estàndard de sortida.
     */
    void frases_paraules(const vector<string>& paraules) const;
};

#endif /* Cjt_textos_hh */
