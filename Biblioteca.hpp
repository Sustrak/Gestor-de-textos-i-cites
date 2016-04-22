

#ifndef Biblioteca_hpp
#define Biblioteca_hpp

class Biblioteca {
private:
    bool triat;
    int pos_autor;
    int pos_text;
    map<string, Cita> cites;
    vector<Autor> autors;
    
public:
    //Constructora
    Biblioteca();
    //Destructora
    ~Biblioteca();
    
    //Modificadores text
    void afegir_text(string titol);
    void triar_text(vector<string> paraules);
    void eliminar_text();
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
