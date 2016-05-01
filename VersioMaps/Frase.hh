/** @file Frase.hh
    @brief Especificació de la classe Frase 
*/

#ifndef Frase_hh
#define Frase_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

using namespace std;

class Frase {

    /** @class Frase
        @brief Representa una frase.
    */
    
private:
    vector<string> _frase;
    int n_paraules;
    
public:

  //Constructora 
  
    /** @brief Creadora per defecte.
        S'executa automaticament al declarar una frase.
        \pre <em>Cert</em>.
        \post El resultat és una frase buida.
    */
    Frase ();

  //Destructora

    /** @brief Destructora per defecte.
    */   
    ~Frase ();

  //Modificadora
  
    /** @brief El paràmetre implícit conté la primera frase de <em>linia</em>.
        \pre <em>Cert</em>.
        \post El p.i. conté la primera frase de <em>linia</em>.
    */
    void llegir(string& linia);  
      
  //Consultora

    /** @brief Retorna el nombre de paraules del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el nombre de paraules del p.i.
    */
    int n_paraules();
 
  //Escriptura

    /** @brief S'escriu el paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i.
    */   
    void escriure();
    
};

#endif /* Cita_hh */
