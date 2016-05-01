/** @file Cita.hh
    @brief Especificació de la classe Cita 
*/

#ifndef Cita_hh
#define Cita_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

#include "Text.hh"
#include "Frase.hh"
using namespace std;

class Cita {

    /** @class Cita
        @brief Representa un text amb autor i conjunt de frases que són el contingut.
    */
    
private:
    string _autor;
    string _titol;
    vector<Frase> _frases;
    int _n_primera; 		//Número de la primera frase de la cita en el text original.
    
public:

  //Constructores 
  
    /** @brief Creadora per defecte.
        S'executa automaticament al declarar una cita.
        \pre <em>Cert</em>.
        \post El resultat és una cita buida.
    */
    Cita ();
  
    /** @brief Creadora amb valors concrets.
        \pre x <= y.
        \post El resultat és una cita amb l'autor, el títol i les frases de la x-éssima a la y-éssima del text que apunta <em>it<em/>.
    */
    Cita (map<string, Text>::iterator it, int x, int y);
    
  //Destructora

    /** @brief Destructora per defecte.
    */   
    ~Cita ();
    
  //Consultores

    /** @brief Retorna l'autor del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna l'autor del p.i.
    */
    string autor();
    
    /** @brief Retorna el títol del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el títol del p.i.
    */  
    string titol();

    /** @brief Retorna el número de la frase inicial del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el número de la frase inicial del p.i.
    */  
    int n_primera();
    
    /** @brief Retorna el número de la frase final del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el número de la frase final del p.i.
    */   
    int n_ultima();
 
  //Escriptura

    /** @brief S'escriu el contingut del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i. amb les frases numerades.
    */   
    void escriure();
    
};

#endif /* Cita_hh */
