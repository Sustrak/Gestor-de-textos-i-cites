/** @file Text.hh
    @brief Especificació de la classe Text
 */

#ifndef Text_hh
#define Text_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#endif

#include "Cita.hh"
#include "Frase.hh"
using namespace std;


class Text {

    /** @class Text
        @brief Representa un text.
    */

private:
    vector<Frase> _contingut;
    int _n_paraules;

public:

    //Constructores

    /** @brief Creadora per defecte.
        S'executa automaticament al declarar un text.
        \pre <em>Cert</em>.
        \post El resultat és un text sense autor, ni contingut.
    */
    Text();

    //Destructora

    /** @brief Destructora per defecte.
    */
    ~Text();

    //Consultores

    /** @brief Retorna el nombre de frases del parametre implícit.
        \pre <em>Cert</em>.
        \post Retorna el nombre de frases del p.i.
    */
    int n_frases();

    /** @brief Retorna el nombre de paraules del parametre implícit.
        \pre <em>Cert</em>.
        \post Retorna el nombre de paraules del p.i.
    */
    int n_paraules();

    /** @brief Retorna si el parametre implícit conté totes les paraules de <em>paraules</em>.
        \pre <em>Cert</em>.
        \post Retorna si el p.i. conté totes les paraules de <em>paraules</em>.
    */
    bool conte_paraules(const vector<string>& paraules);
    
    /** @brief Llegeix un text del canal d'entrada.
     \pre El canal d'entrada estandard conté el text en una línia.
     \post _contingut s'ha omplert i ara conté el text separat en frases.
     */
    void llegir_text();
    
    /** @brief Substitueix una paraula per una altre en el paràmetre implícit.
        \pre <em>Cert</em>.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el p.i.
    */
    void substitueix (string par1, string par2);
    
    /** @brief Afegeix a una cita el contingut amb les frases de la x-éssima a la y-éssima del paràmetre implicit.
     \pre <em>cita</em> ja té títol i és el matéix que el del p.i., x <= y.
     \post <em>cita</em> té l'autor i el títol del p.i. i com a contingut les frases de la x-éssima a la y-éssima del p.i.
    */
    void afegir_contingut(Cita& cita, int x, int y);
    
    //Escriptura

    /** @brief S'escriu el contingut del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i. amb les frases numerades.
    */
    void escriure_contingut();
    
};
#endif /* Text_hh */
