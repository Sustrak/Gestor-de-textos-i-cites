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

using namespace std;

/** @class Cita
    @brief Representa un conjunt de frases d'un text amb el títol i autor del text */
class Cita {
private:
    string _autor;
    string _titol;
    vector<string> _frases;
    int _num_primera;
    
public:
  //Constructores 
  
  /** @brief Creadora per defecte. 

      \pre <em>cert</em>
      \post El resultat es una cita sense frases, ni referencia, ni títol, ni autor.
  */ 
    Cita ();
  
  /** @brief Creadora amb valors concrets. 

      \pre x <= y, text conté almenys y+1 cites
      \post El resultat es una cita amb les frases que van de la x-èsima a la y-èsima de text.
  */ 
    Cita (const Text& text, int x, int y);
    
  //Destructores
  
    ~Cita ();
    
  //Consultores

    /** @brief Retorna l'autor de la cita.

      \pre <em>cert</em>
      \post Es retorna l'autor del p.i.
  */     
    string consultar_autor();
    
    /** @brief Retorna el títol del text que es cita.

      \pre <em>cert</em>
      \post Es retorna el títol del p.i.
  */     
    string consultar_titol();
 

  //Escriptura
  
    /** @brief Escriu la cita.

      \pre <em>cert</em>
      \post S'escriuen pel canal estàndard les frases, l'autor i el títol del p.i.
  */      
    void escriure();
    
    /** @brief Escriu la informacío de la cita.

      \pre <em>cert</em>
      \post S'escriuen pel canal estàndard l'autor, títol, número de la frase inicial i final i frases que el p.i.
  */      
    void info();
    
};

#endif /* Cita_hh */
