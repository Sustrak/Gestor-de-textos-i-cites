
#ifndef Autor_hpp
#define Autor_hpp

#include <string>
#include <vector>

class Autor {
private:
    string nom;
    string cognom;
    vector<Text> textos;
    int n_textos;
    int n_frases;
    int n_paraules;
    
public:
    Autor();
    ~Autor();
    
    void afegir_text(Text text);
    int busca_triar_text(bool& trobat, const vector<string>& paraules)
    /* Post: trobat es cert si ha trobat el text que buscavem, fals si no l'ha trobat
             retorna -1 si error, altrament retorna la posició del vector textos */
    void eliminar_text(int pos_text);
    void substituir_text(int pos_text, string par1, string par2);
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
