/** @file Autor.hh
    @brief Especificació de la classe Autor 
*/

#ifndef Autor_hpp
#define Autor_hpp

#include <string>
#include <vector>

/** @class Autor
    @brief Representa un autor i el conjunt dels seus textos */
class Autor {
private:
    string nom;
    string cognom;
    vector<Text> textos;
    int n_textos;
    int n_frases;
    int n_paraules;
    
public:
  //Constructores 

  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un autor.
      \pre <em>cert</em>
      \post El resultat es un autor sense textos.
  */ 
    Autor();
    
  //Destructores 
    ~Autor();
    
  //Modificadores
  
    /** @brief Afegeix un text al parametre implícit. 

      \pre El paràmetre implícit no conté cap text amb el títol de text.
      \post El paràmetre implícit conté els textos originals més text.
  */ 
    void afegir_text(Text text);
    
    /** @brief Indica si el parametre implícit conté un text amb un conjunt de paraules. 

      \pre paraules és un conjunt de paraules.
      \post Si trobat era originalment cert: es manté cert i retorna -1 si existeix algun text al p.i que contingui paraules.
      Si trobat era originalment fals: trobat es cert si existeix algun text al p.i. que contingui paraules i fals altrament. I retorna la seva posició si aquest es únic i -1 si n'existeix més d'un.
  */ 
    int busca_triar_text(bool& trobat, const vector<string>& paraules)
    
    /** @brief Elimina un text del parametre implícit. 

      \pre El paràmetre implícit conté un text a la posicio pos_text.
      \post El paràmetre implícit conté els textos originals excepte el text de la posicio pos_text.
  */     
    void eliminar_text(int pos_text);
    
    /** @brief Canvia totes les aparicions d'una paraula per una altra en un text del parametre implícit. 

      \pre El paràmetre implícit conté un text a la posicio pos_text.
      \post S'han substituït totes les aparicions de par1 per par2 en el text de la posicio pos_text.
  */      
    void substituir_text(int pos_text, string par1, string par2);
    
    /** @brief Escriu el títol de tots els textos del paràmetre implicit. 

      \pre <em>cert</em>
      \post S'escriuen pel canal estàndard el títol de tots els textos del p.i. ordenats alfabèticament per tí́tol.
  */      
    void escriure_textos();
    void mostrat_titols();
    void consultar_autor();
    void info_text(int j);
    void mostra_contingut(int j);
    void frases_text(int j, int x, int y);
    void nombre_frases_text(int j);
    void nombre_paraules_text(int j);
    
};

#endif /* Autor_hpp */
