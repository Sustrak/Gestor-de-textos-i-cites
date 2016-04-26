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
    //CONSTRUCTORA
    
    /** @brief Creadora per defecte.
        S'executa automaticament al declarar Biblioteca b;
        /pre cert
        /post el resultat és una biblioteca buida
    */
    Biblioteca();
    
    //DESTRUCTORA
    ~Biblioteca();
    
    //MODIFICADORES TEXT
    
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
    
    //MODIFICADORES CITES
    
    /** @brief Afegex una cita
     /pre x <= y, no existeix una cita igual,
     /post S'ha creat una nova cita i se li ha assignat la referència corresponent
    */
    void afegir_cita(int x, int y);
    
    /** @brief Elimiar una cita
     /pre Existeix una cita amb la <b>referencia</b> associada
     /post S'ha eliminat la cita amb referencia <b>referencia</b>
    */
    void eliminar_cita(string referencia);
    
    //CONSULTORES
    
    /** @brief Textos d'un autor
     /pre Cert
     /post Retorna tots els textos de l'autor <b>autor</b>
    */
    void textos_autor(string autor);
    
    /** @brief Tots els textos
     /pre Cert
     /post Retorna tots els textos introduïts
    */
    void tots_textos();
    
    /** @brief Tots els autors
     /pre Cert
     /post Retorna tots els autors de la biblioteca
    */
    void tots_autors();
    
    /** @brief Informació
     /pre Hi ha un text triat
     /post Retorna autor, tı́tol, nombre de frases, nombre de paraules i cites associades de l'ultim text triat
    */
    void info();
    
    /** @brief Autor
     /pre Hi ha un text triat
     /post Retorna l'autor del text triat
    */
    void autor();
    
    /** @brief Informació
     /pre Hi ha un text triat
     /post Retorna el contingut del text triat
    */
    void contingut();
    
    /** @brief Frases {x, y}
     /pre Hi ha un text triat i x <= y
     /post Retorna les frases de la x a la y
    */
    void frasesxy (int x, int y);
    
    /** @brief Nombre de frases
     /pre Hi ha un text triat
     /post Retorna el nombre de frases de l'ultim text triat
    */
    void nombre_frases();
    
    /** @brief Taula de freqüències
     /pre Hi ha un text triat
     /post Retorna la taula de freqüencies
    */
    void taula_freq();
    
    /** @brief Frases que compleixen l'expressió
     /pre L'expressió és una expressió booleana
     /post Retorna totes les frases que compleixen l'<b>expresió</b>
    */
    void frases_expressio(string expressio);
    
    /** @brief Frases paraules
     /pre Cert
     /post Retorna les frases que contenen consecutivament les paraules <b>paraules</b>
    */
    void frases_paraules(string paraules);
    
    //CONSULTORES CITES
    
    /** @brief Informació cita
     /pre Existeix la <b>referencia</b>
     /post Retorna autor, tı́tol, número de la frase inicial i número de la frase final, contingut de la frase o frases que la componen
    */
    void info_cita(string referencia);
    
    /** @brief Cites
     /pre Hi ha un text triat
     /post Retorna totes les cites de l'ultim text triat
    */
    void cites();
    
    /** @brief Cites d'un autor
     /pre Existeix l'<b>autor</b>
     /post Retorna totes les cites de l'<b>autor</b>
    */
    void cites_autor(string autor);
    
    /** @brief Totes les cites
     /pre Cert
     /post Retorna totes les cites del sistema
     */
    void totes_cites();
    
};

#endif /* Biblioteca_hpp */
