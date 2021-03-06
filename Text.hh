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

#include "Frase.hh"
#include "Cita.hh"
#include "Taula_freq.hh"
using namespace std;


class Text {

    /** @class Text
        @brief Representa un text.
    */

private:
	/** @brief Vector que té per elements les frases del contingut del text.
	 
	 Les frases estan ordenades per l'ordre en que estan en el text. */
    vector<Frase> _contingut;
	/** @brief Indica el nombre de paraules que té el text.  */  
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
    int n_frases() const;

    /** @brief Retorna el nombre de paraules del parametre implícit.
        \pre <em>Cert</em>.
        \post Retorna el nombre de paraules del p.i.
    */
    int n_paraules() const;

    /** @brief Retorna si el parametre implícit conté totes les paraules de <em>paraules</em>.
        \pre <em>Cert</em>.
        \post Retorna si el p.i. conté totes les paraules de <em>paraules</em>.
    */
    bool conte_paraules(vector<string> paraules, string& autor, string& titol) const;
    
    /** @brief Afegeix a una cita el contingut amb les frases de la x-éssima a la y-éssima del paràmetre implicit.
     \pre <em>cita</em> ja té títol i és el matéix que el del p.i., x <= y.
     \post <em>cita</em> té l'autor i el títol del p.i. i com a contingut les frases de la x-éssima a la y-éssima del p.i.
    */
    void afegir_contingut(Cita& cita, int x, int y) const;
    
    /** @brief Retorna per referencia la taula de freqüències del paràmetre implícit.
     \pre <em>Cert</em>.
     \post Retorna per referencia la taula de freqüències del p.i.
     */
    void fer_taula(Taula_freq& t) const;   
    
    //Modificadores
    
    /** @brief Llegeix un text del canal d'entrada.
     \pre El canal d'entrada estandard conté el text en una línia.
     \post _contingut s'ha omplert i ara conté el text separat en frases.
     */
    void llegir_text();
    
    /** @brief Substitueix una paraula per una altre en el paràmetre implícit.
        \pre <em>Cert</em>.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el p.i.
    */
    void substitueix (const string& par1, const string& par2);   
    
    //Escriptura
    
    /** @brief Escriu les frases del parametre implícit que contenen totes les paraules cosecutivament de <em>paraules</em>.
     \pre <em>Cert</em>.
     \post Escriu les frases del p.i. que contenen totes les paraules cosecutivament de <em>paraules</em>.
     */
    void conte_consecutives(const vector<string>& paraules) const;
    
    /** @brief S'escriu el contingut de la frase x a la y del paràmetre implícit
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i. amb les frases numerades de la x a la y.
    */
    void escriure_contingut(int x, int y) const;
   
    /** @brief S'escriuen les frases del contingut del paràmetre implícit que compleixen l'expressió.
     \pre <em>Cert</em>
     \post S'escriuen les frases del contingut del p.i. que compleixen l'expressió pel canal estàndard de sortida.
     */
    void frases_expressio(const string& expressio) const;
    
};
#endif /* Text_hh */
