/** @file Cjt_cites.hh
    @brief Especificació de la classe Cjt_cites.
*/

#ifndef Cjt_cites_hh
#define Cjt_cites_hh

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

#include "Cita.hh"
#include "Text.hh"
using namespace std;

class Cjt_cites {

    /** @class Cjt_cites
        @brief Guarda i ordena el conjunt de cites per referència.
    */
    
private:
    map<string, Cita> _cites;			//L'string es la referència.
    
public:

    //Constructora
    
    /** @brief Creadora per defecte.
        S'executa automaticament al declarar un conjunt de cites.
        \pre <em>Cert</em>.
        \post El resultat és un conjunt de cites buit.
    */
    Cjt_cites();
    
    //Destructora

    /** @brief Destructora per defecte.
    */    
    ~Cjt_cites();
    
    //Modificadores
 
    /** @brief Afegeix al paràmetre implícit una cita del text que apunta <em>it<em/>.
        \pre No existeix la mateixa cita al p.i., x <= y.
        \post S'ha afegit al p.i. una cita amb l'autor, el títol i les frases de la x-éssima a la y-éssima del text que apunta <em>it<em/>.
    */
    void afegir_cita(map<string, Text>::iterator it, int x, int y);
 
    /** @brief Elimina del paràmetre implícit la cita de referència <em>ref<em/>.
        \pre El p.i. conté una cita amb la referència <em>ref<em/>.
        \post Elimina del p.i. la cita amb la referència <em>ref<em/>.
    */
    void eliminar_cita(string ref);
    
    //Consultora
    
    /** @brief Retorna si el paràmetre implícit conté una cita amb la referència <em>ref<em/>.
        \pre <em>Cert</em>.
        \post Retorna si el p.i. conté una cita amb la referència <em>ref<em/>.
    */
    bool te_cita(string ref);    
    
    //Escriptura
    
    /** @brief S'escriu informació de la cita amb referència <em>ref<em/>..
        \pre El p.i. conté una cita amb referència <em>ref<em/>.
        \post S'escriu l'autor, el títol, el número de la frase inicial i final i el contingut de la cita amb referència <em>ref<em/> pel canal estàndard de sortida.
    */
    void info_cita(string ref);
    
    /** @brief S'escriu informació de totes les cites al paràmetre implícit amb autor <em>autor<em/>.
        \pre <em>Cert</em>.
        \post S'escriu la referència, el contingut i l'autor i el títol del text d’on provenen cada cita del p.i. amb autor <em>autor<em/>.
    */
    void cites_autor(string autor);
    
    /** @brief S'escriu informació de totes les cites al paràmetre implícit provinents del text que apunta <em>it<em/>.
        \pre <em>Cert</em>.
        \post S'escriu la referència, el contingut i l'autor i el títol del text d’on provenen cada cita del p.i. provinent del text que apunta <em>it<em/>.
    */
    void cites_text(map<string, Text>::iterator it);
    
    /** @brief S'escriu informació de totes les cites del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu la referència, el contingut i l'autor i el títol del text d’on provenen de cada cita del p.i.
    */
    void totes_cites();
    
};

#endif /* Cjt_cites_hh */
