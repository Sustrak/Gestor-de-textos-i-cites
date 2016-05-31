/** @file Biblioteca.hh
    @brief Especificació de la classe Biblioteca.
*/

#ifndef Biblioteca_hh
#define Biblioteca_hh

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <vector>
#endif

#include "Cjt_textos.hh"
#include "Text.hh"
#include "Taula_freq.hh"
#include "Func_auxiliars.hh"


class Biblioteca {

    /** @class Biblioteca
        @brief Guarda i ordena el conjunt dels textos per autor.
    */
    
private:
	/** @brief Indica si hi ha un text triat.  */  
    bool _triat;
	/** @brief Si hi ha un text triat, apunta al autor del text triat.  */  
    map<string, Cjt_textos>::iterator _autor_triat;
	/** @brief Map que conté tots els textos en conjunts, un per cada autor.

      Ordenat alfabèticament per autor. La clau són strings que contenen els autors i el valor és un element Cjt_textos que correspon al autor de la clau. */
    map<string, Cjt_textos> _autors;                //L'string es el nom de l'autor.
	/** @brief Si hi ha un text triat, és la taula de freqüències del text triat.  */ 
    Taula_freq _tfreq;
        
public:

    //Constructora
    
    /** @brief Creadora per defecte.
        S'executa automaticament al declarar una biblioteca.
        \pre <em>Cert</em>.
        \post El resultat és una biblioteca buida.
    */
    Biblioteca();
    
    //Destructora

    /** @brief Destructora per defecte.
    */    
    ~Biblioteca();
    
    //Modificadores
    
    /** @brief Afegeix un text a un autor.
        \pre No existeix el mateix text, el canal estàndard d'entrada hi ha preparat el nom de l'autor i el contingut.
        \post L'autor té un nou text associat amb títol <b>títol</b>.
    */
    void afegir_text(string& titol);
    
    /** @brief Tria el text que conté certes paraules.
        \pre <em>Cert</em>.
        \post La biblioteca tria un text, si és l'únic que conté totes les paraules de paraules el títol, l’autor i/o el contingut.
    */
    void triar_text(string& paraules);
    
    /** @brief Elimina el text triat.
        \pre Hi ha un text triat.
        \post Elimina del p.i. el text triat i deixa de haver un text triat.
    */
    void eliminar_text();
    
    /** @brief Substitueix una paraula per una altra en el text triat.
        \pre Hi ha un text triat.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el text triat.
    */
    void substitueix (string& par1, string& par2);
    
    //Consultores
    
    /** @brief Retorna si hi ha un text triat.
        \pre <em>Cert</em>.
        \post Retorna si hi ha un text triat.
    */
    bool triat() const;
    
    /** @brief <em>c</em> té l'autor, el títol i les frases de la x-éssima a la y-essima del text triat al paràmetre implícit.
        \pre Hi ha un text triat, x<=y.
        \post <em>c</em> té l'autor, el títol i les frases de la x-éssima a la y-essima del text triat al p.i.
    */
    void modificar_cita(Cita& c, int x, int y) const;
    
    /** @brief <em>autor</em> conté l'autor i <em>títol</em> el títol del text triat al paràmetre implícit.
        \pre Hi ha un text triat.
        \post <em>autor</em> conté l'autor i <em>títol</em> el títol del text triat al p.i.
    */
    void info_triat(string& autor, string& titol) const;
    
    //Escriptura
    
    /** @brief S'escriu el títol de tots els textos d'un autor.
        \pre <em>Cert</em>.
        \post S'escriu el títol de tots els textos de l'autor <b>autor</b>, si existeix, pel canal estàndard de sortida.
    */
    void textos_autor(string autor) const;
    
    /** @brief S'escriuen tots els textos de la biblioteca.
        \pre <em>Cert</em>.
        \post S'escriuen l'autor i el títol de tots els textos de la biblioteca pel canal estàndard de sortida.
    */
    void tots_textos() const;
    
    /** @brief S'escriuen tots els autors de la biblioteca.
        \pre <em>Cert</em>.
        \post S'escriuen tots els autors amb textos de la biblioteca, amb el nombre de textos, el nombre total de frases i de paraules del contingut dels textos de cada autor, pel canal estàndard de sortida.
    */
    void tots_autors() const;
    
    /** @brief S'escriu informació del text triat.
        \pre Hi ha un text triat.
        \post S'escriu l'autor, el títol, el nombre de frases, el nombre de paraules i les cites associades del text triat pel canal estàndard de sortida.
    */
    void info() const;
    
    /** @brief S'escriu l'autor del text triat.
        \pre Hi ha un text triat.
        \post S'escriu l'autor del text triat pel canal estàndard de sortida.
    */
    void autor() const;
    
    /** @brief S'escriu l'autor i titol del text triat.
        \pre Hi ha un text triat.
        \post S'escriu l'autor i el titol del text triat pel canal estàndard de sortida.
    */
    void autor_titol() const;
    
    /** @brief S'escriu el contingut del text triat.
        \pre Hi ha un text triat.
        \post S'escriu el contingut del text triat pel canal estàndard de sortida.
    */
    void contingut() const;
    
    /** @brief S'escriuen les frases de la x-éssima a la y-éssima del text triat.
        \pre Hi ha un text triat i x <= y.
        \post S'escriuen les frases de la x-éssima a la y-éssima del text triat pel canal estàndard de sortida.
    */
    void frasesxy (int x, int y) const;
    
    /** @brief S'escriu el nombre de frases del text triat.
        \pre Hi ha un text triat.
        \post S'escriu el nombre de frases del text triat pel canal estàndard de sortida.
    */
    void nombre_frases() const;
    
    /** @brief S'escriu el nombre de paraules del text triat.
        \pre Hi ha un text triat.
        \post S'escriu el nombre de paraules del text triat pel canal estàndard de sortida.
    */
    void nombre_paraules() const;
    
    /** @brief S'escriu la taula de freqüències del text triat.
        \pre Hi ha un text triat.
        \post S'escriu la taula de freqüències del text triat pel canal estàndard de sortida.
    */
    void taula_freq() const;
    
    /** @brief S'escriuen les frases del contingut del text triat que compleixen l’expressió.
        \pre Hi ha un text triat.
        \post S'escriuen les frases del contingut del text triat que compleixen l’expressió pel canal estàndard de sortida.
    */
    void frases_expressio(string& expressio) const;
    
    /** @brief S'escriuen les frases del contingut del text triat que contenen la seqüència de paraules.
        \pre Hi ha un text triat.
        \post S'escriuen les frases del contingut del text triat que contenen la seqüència de paraules pel canal estàndard de sortida.
    */
    void frases_paraules(string& paraules) const;
};

#endif /* Biblioteca_hh */
