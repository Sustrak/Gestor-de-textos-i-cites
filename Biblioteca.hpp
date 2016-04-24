/** @file Estudiant.hh
    @brief Especificació de la classe Biblioteca
*/

#ifndef Biblioteca_hpp
#define Biblioteca_hpp

#include <string>
#include <map>
#include <vector>

#include "Autor.hpp"

class Biblioteca {
    
    //Tipus de modul: dades
    
    /** @class Biblioteca
        @brief Guarda i ordena els autors i les cietes
    */
    
private:
    bool triat;
    int pos_autor;
    int pos_text;
    map<string, Cita> cites;
    vector<Autor> autors;
    
public:
    //Constructora
    
    /** @brief Creadora per defecte.
        S'executa automaticament al declarar Biblioteca b;
        /pre cert
        /post el resultat és una biblioteca buida
    */
    Biblioteca();
    
    //Destructora
    ~Biblioteca();
    
    //Modificadores text
    
    /** @brief Afegeix un text a un autor
        /pre No existeix un text amb el mateix títol, el canal estandar d'entrada hi ha preparat el nom de l'autor i el contingut
        /post L'autor té un nou text associat amb títol <b>títol</b>
    */
    void afegir_text(string titol);
    
    /** @brief Tria el text que conté certes paraules
     /pre
     /post Es guarda a pos_autor i pos_text on està el text triat dins els vectors d'Autors i Text (vector dins la classe Autor), el boolea triat es posa a cert
     */
    void triar_text(vector<string> paraules);
    
    /** @brief Elimina el text triat
     /pre Hi ha un text triat (<b>triat</b> == true)
     /post Elimina del sistema el text triat, el text deixa d'estar triat (<b>triat</b> == false)
     */
    void eliminar_text();
    
    /** @brief Substitueix una paraula en el text triat
     /pre cert
     /post Canvia totes les aparicions de <b>par1</b> per <b>par2</b>
     */
    void substitueix (string par1, string par2);
    
    //Modificadores cites
    void afegir_cita(int x, int y);

    void eliminar_cita(string referencia);
    
    //Consultores
    void textos_autor(string autor);
    void tots_textos();
    void tots_autors();
    void info();
    void autor();
    void contingut();
    void frasesxy (int x, int y);
    void nombre_frases();
    void taula_freq();
    void frases_expressio(string expressio);
    void frases_paraules(string paraules);
    
    //Consultores cita
    void info_cita(string referencia);
    void cites();
    void cites_autor(string autor);
    void totes_cites();
    
};

#endif /* Biblioteca_hpp */
