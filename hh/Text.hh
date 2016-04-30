/** @file Text.hh
    @brief Especificació de la classe Text
 */

#ifndef Text_hh
#define Text_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

using namespace std;

struct Taula {
    string paraula;
    int freq;
};

/** @class Text
    @brief Representa un Text*/
class Text {
private:
    string _titol;
    vector<string> _frases;
    int _nparaules;
    int _nfrases;
    vector<Taula> _tfreq;
    
    
    /** @brief Dividir el contingut.
     
     \pre <em>cert</em>
     \post Divideix tot un strign amb el contingut del text en frases i les insereix a _frases.
    */
    static void split_contingut(string contingut, vector<string> frases);
    static void ordenar_tfreq(vector<Taula> tfreq);
    
public:
    
    //Constructores

    /** @brief Creadora per defecte.
     
     \pre <em>cert</em>
     \post El resultat es un Text sense títol, frases, nparaules ni nfrases
    */
    Text();
    
    /** @brief Creadora amb certs valors.
     
     \pre <em>cert</em>
     \post El resultat es un Text amb titol <em>titol</em> i frases el <em>contingut</em> dividit també s'ha calculat el nparaules i el nfrases
    */
    Text(string titol, string contingut);
    
    //Destructora

    /** @brief destructora per defecte.
    */
    ~Text();
    
    //Consultores

    /** @brief Consultar titol.
     
     \pre El p.i no és buit.
     \post Retorna el títol del text.
    */
    string consultar_titol();
    
    /** @brief Consultar número de frases.
     
     \pre El p.i no és buit.
     \post Retorna el número de frases del text.
    */
    int consultar_nfrases();
    
    /** @brief Consultar el número de paraules.
     
     \pre El p.i no és buit.
     \post Retorna el número de paraules del text.
    */
    int consultar_nparaules();
    

    /** @brief Buscador de textos.

     \pre tipus indica si busquem per una expressió o si busquem per un seguit de paraules, les paraules a buscar estan en el vector paraules.
     \post Retorna cert si el text conté les paraules de la forma que indica tipus, altrament retorna fals.
    */
    bool buscar(bool tipus, vector<string> paraules);

    /** @brief Frases de la x a la y.

     \pre X i Y son nombres naturals amb x <= y i y < _frases.size()
     \post Retorna un vector amb les frases de la x a la y
    */
    vector<string> frases(int x, int y);

    //Escriptura

    /** @brief Escriure contingut.
     
     \pre El p.i no és buit
     \post Escriu el numero de la frase i separat amb un espai el contingut de la frase.
    */
    void escriure_contingut();
    
    /** @brief Escriure la taula de freqüències.
     
     \pre El p.i no és buit
     \post Escriu pel canal de sortida estàndar la taula de freqüències del text.
    */
    void escriure_taula_freq();

};
#endif /* Text_hh */













