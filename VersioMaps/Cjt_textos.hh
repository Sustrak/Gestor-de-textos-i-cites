/** @file Cjt_textos.hh
    @brief Especificació de la classe Cjt_textos. 
*/

#ifndef Cjt_textos_hh
#define Cjt_textos_hh

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

#include "Text.hh"
using namespace std;

class Cjt_textos {
	
    /** @class Cjt_textos
        @brief Representa un conjunt de textos.
    */

private:
    map<string, Text> _textos;
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
        \pre No existeix un text amb el títol titol al conjunt.
        \post El p.i. conté el textos inicials més el text text amb el títol titol.
    */
    void afegir_text(string titol, Text text);
    
    /** @brief Elimina un text del parametre implícit.
        \pre El p.i. conté el text que apunta it.
        \post El p.i. conté el textos inicials menys el text que apuntaba originalment it.
    */
    void eliminar_text(map<string, Text> :: iterator it); 

  //Consultores

    /** @brief Retorna la posició del primer text del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna la posició del primer text del p.i.
    */
    map<string, Text>::iterator primer();
    
    /** @brief Retorna la posició d'un text del paràmetre implícit que conté les paraules.
		Si el conté el paràmetre implícit, es retorna la posició del primer text a partir del que apuntaba originalment it que conté paraules i trobat té el valor contrari al original. Altrament trobat es manté com originalment.
        \pre El p.i. conté el text que apunta it.
        \post Si el conté el p.i., es retorna la posició del primer text a partir del que apuntaba originalment it que conté paraules i trobat té el valor contrari al original. Altrament trobat es manté com originalment.
    */
    map<string, Text>::iterator buscar_text(bool& trobat, const string& paraules, map<string, Text> it);

  //Escriptura
    
    /** @brief S'escriuen els títols dels textos del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriuen pel canal estàndard de sortida el títol de tots els textos del p.i. ordenats alfabèticament.
    */   
    void escriure_titols();   
};

#endif /* Cjt_textos_hh */
