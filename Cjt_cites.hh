/** @file Cjt_cites.hh
    @brief Especificació de la classe Cjt_cites.
*/

#ifndef Cjt_cites_hh
#define Cjt_cites_hh

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <sstream>
#endif

#include "Func_auxiliars.hh"
#include "Cita.hh"
#include "Biblioteca.hh"


class Cjt_cites {

    /** @class Cjt_cites
        @brief Guarda i ordena el conjunt de cites per referència.
    */
    
private:
	/** @brief Map que conté totes les cites amb la seva referència.

      Ordenat alfabèticament per referència. La clau són strings que contenen la referència de la cita i el valor és un element Cita que correspon a la referència de la clau. */
    map<string, Cita> _cites;			//L'string es la referència.
    
     /** @brief Crea les inicials d'un string.
        \pre <em>ini</em> és inicialment un string buit.
        \post <em>ini</em> és la concatenació de les inicals de cada una del les paraules que conté <em>autor</em>.
    */   
    static void fer_ini(string& ini, string autor);
     /** @brief Crea una referencia a partir d'unes inicials i un enter.
        \pre <em>Cert</em>.
        \post <em>ref</em> és la concatenació de <em>ini</em> i els caràcters que representen l'enter <em>i</em>.
    */
	static void fer_ref(const string& ini, int i, string& ref);
    
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
 
    /** @brief Afegeix al paràmetre implícit una cita del text triat a <em>b<em/>.
        \pre x <= y.
        \post Si <em>b</em> té un text triat i no existeix una cita igual, s'ha afegit al p.i. una cita amb l'autor, el títol i les frases de la x-éssima a la y-éssima del text triat a <em>b<em/>. Altrament, s'escriu un missatge d'error.
    */
    void afegir_cita(const Biblioteca& b, int x, int y);
 
    /** @brief Elimina del paràmetre implícit la cita de referència <em>ref<em/>.
        \pre El p.i. conté una cita amb la referència <em>ref<em/>.
        \post Elimina del p.i. la cita amb la referència <em>ref<em/>.
    */
    void eliminar_cita(string& ref);
    
    //Consultora
    
    /** @brief Retorna si el paràmetre implícit conté una cita amb la referència <em>ref<em/>.
        \pre <em>Cert</em>.
        \post Retorna si el p.i. conté una cita amb la referència <em>ref<em/>.
    */
    bool te_cita(string& ref) const;    
    
    //Escriptura
    
    /** @brief S'escriu informació de la cita amb referència <em>ref<em/>..
        \pre El p.i. conté una cita amb referència <em>ref<em/>.
        \post S'escriu l'autor, el títol, el número de la frase inicial i final i el contingut de la cita amb referència <em>ref<em/> pel canal estàndard de sortida.
    */
    void info_cita(string& ref) const;
    
    /** @brief S'escriu informació de totes les cites al paràmetre implícit amb autor <em>autor<em/>.
        \pre <em>Cert</em>.
        \post S'escriu la referència, el contingut i l'autor i el títol del text d’on provenen cada cita del p.i. amb autor <em>autor<em/>.
    */
    void cites_autor(string& autor) const;
    
    /** @brief Retorna si hi ha cites associades al text triat a <em>b<em/>, en aquest cas n'escriu la informació d'aquestes.
        \pre <em>b</em> té un text triat.
        \post Retorna si hi ha cites associades al text triat a <em>b<em/>, en aquest cas n'escriu la informació d'aquestes.
    */
    bool cites_text(const Biblioteca& b) const;
    
    /** @brief S'escriu informació de totes les cites del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu la referència, el contingut i l'autor i el títol del text d’on provenen de cada cita del p.i.
    */
    void totes_cites() const;
    
};

#endif /* Cjt_cites_hh */
