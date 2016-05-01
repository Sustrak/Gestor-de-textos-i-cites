/** @file Text.hh
    @brief Especificació de la classe Text
 */

#ifndef Text_hh
#define Text_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

#include "Cita.hh"
#include "Frase.hh"
using namespace std;


class Text {

    /** @class Text
        @brief Representa un text.
    */

private:
    string _autor;
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

    /** @brief Creadora amb certs valors.
        \pre <em>Cert</em>.
        \post El resultat és un text amb autor <em>autor</em> i sense contingut.
    */
    Text(string titol);

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
    bool conte_paraules(const string& paraules);

    /** @brief Afegeix a una cita el contingut amb les frases de la x-éssima a la y-éssima del paràmetre implicit.
        \pre <em>cita</em> ja té títol i és el matéix que el del p.i., x <= y.
        \post <em>cita</em> té l'autor i el títol del p.i. i com a contingut les frases de la x-éssima a la y-éssima del p.i.
    */
    void afegir_contingut(int x, int y, Cita& cita);

    //Escriptura

    /** @brief S'escriu el contingut del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i. amb les frases numerades.
    */
    void escriure_contingut();
};
#endif /* Text_hh */
