/** @mainpage Pràctica PRO2: Gestió de textos i cites.

	Aplicació per a gestionar informació de textos i cites associades a aquest textos.
	
	Els textos poden correspondre a llibres, articles, manuals, etc., però aquí entendrem un text com un contingut que té un autor i un títol.
	El contingut ́es una seqüència de frases. Una frase ́es una seqüència de paraules separades opcionalment per comes (,) punts i comes (;) o dos
	punts (:), i acabades en punt (.), interrogant de tancar (?) o admiració de tancar (!).
	
	Entenem una cita com una o més frases consecutives d’un	text. Cada frase té un número de frase associat que indica la seva posició en el text:
	la primera frase és la número 1, la segona frase és la número 2, i així successivament. El número de frase és una forma més robusta de referir-se
	al contingut d’un text respecte el número de pàgina, que està fortament determinat pel format de l’edició. El sistema proveeix una sèrie d’operacions
	per fer consultes sobre el contingut dels textos; per exemple, mostrar les frases que contenen un determinat conjunt de paraules, a l’estil dels
	cercadors d’internet i fins i tot més elaborades. Algunes d’aquestes operacions serveixen per definir cites.

	Els sistema interactua amb l’usuari mitjaņcant una línia de comandes basada en el canal d’entrada i sortida estàndard. Les comandes de consulta
	es distingeixen de la resta perquè acaben en ?. Una paraula és una seqüència no buida de lletres i/o dígits. En les comandes fem servir
	{<paraula1> <paraula2> ... <paraulaN>} per referir-nos al conjunt de paraules format per <paraula1>, <paraula2>... i <paraulaN>. En canvi, amb
	"<paraula1> <paraula2> ...<paraulaN>" ens referim a la seqüència <paraula1>, <paraula2>, ... i <paraulaN>. Els caràcters "..." o {...} formen
	part de la comanda. Tant els conjunts com les seqüències estan formats per almenys una paraula.
*/

/** @file main.cc
    @brief Programa principal per la pràctica <em>Gestió de textos i cites</em>.
    
    Estem suposant que les dades llegides són sempre correctes.
*/

#ifndef NO_DIAGRAM
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#endif

#include "Func_auxiliars.hh"
#include "Biblioteca.hh"
#include "Cjt_cites.hh"
using namespace std;

void operar (Biblioteca& b, Cjt_cites& c, string& linia)
{
	istringstream iss(linia);
	string op;
	iss >> op;

	if (op == "afegir") {
		iss >> op;
		if (op == "text") {
			//Acció "afegir text "<titol>".
			
			ws(iss);
			getline(iss, linia);
			b.afegir_text(linia);
		}
		else if (op == "cita") {
			//Acció "afegir cita x y".
			
			string x, y;
			iss >> x;
			iss >> y;
			c.afegir_cita(b, fer_num(x), fer_num(y));
		}
	}
	else if (op == "triar") {
		iss >> op;
		if (op == "text") {
			//Acció "triar text {<paraula1> <paraula2> ... <paraulaN>}".
			
			ws(iss);
			getline(iss, linia);
			b.triar_text(linia);
		}
	}
	else if (op == "eliminar") {
		iss >> op;
		if (op == "text") {
			//Acció "eliminar text".
			
			b.eliminar_text();
		}
		else if (op == "cita") {
			//Acció eliminar cita.
			
			iss >> op;
			c.eliminar_cita(op);
		}
	}
	else if (op == "substitueix") {
		//Acció "substitueix "<paraula1>" per "<paraula2>"".
		
		string par1, par2;
		iss >> par1;
		iss >> op;
		iss >> par2;
		b.substitueix(par1, par2);
	}
	else if (op == "textos") {
		iss >> op;
		if (op == "autor") {
			//Acció "textos autor "autor" ?".
			
			ws(iss);
			getline(iss, op);
            op.erase(op.end()-1);
            op.erase(op.end()-1);
			b.textos_autor(op);
		}
	}
	else if (op == "tots") {
		iss >> op;
		if (op == "textos") {
			//Acció "tots textos ?".
			
			b.tots_textos();
		}
		else if (op == "autors") {
			//Acció "tots autors ?".
			
			b.tots_autors();
		}
	}
	else if (op == "info") {
		iss >> op;
		if (op == "?") {
			//Acció "info ?".
			
			b.info();
			if (b.triat()) cout << "Cites Associades:" << endl;
			c.cites_text(b);
		}
		else if (op == "cita") {
			//Acció "info cita "<referencia>" ?"
			
			iss >> op;
			c.info_cita(op);
		}
	}
	else if (op == "autor") {
		//Acció "autor ?"
		
		b.autor();
	}
	else if (linia == "contingut ?") {
		//Acció "contingut ?"
		
		b.contingut();
	}
	else if (linia == "nombre de frases ?") {
		//Acció "nombre de frases ?"
		
		b.nombre_frases();
	}
	else if (linia == "nombre de paraules ?") {
		//Acció "nombre de paraules ?"
		
		b.nombre_paraules();
	}
	else if (linia == "taula de frequencies ?") {
		//Acció "taula de frequencies ?"
		
		b.taula_freq();
	}
	else if (op == "frases") {
		ws(iss);
		getline(iss, linia);
		istringstream iss(linia);
		if (linia[0] == '(' or linia[0] == '{') {
			//Acció "frases <expressio> ?"
			
			b.frases_expressio(linia);
		}
		else if (linia[0] == '"') {
			//Acció "frases "<paraula1> <paraula2> ... <paraulaN>" ?"
			
			b.frases_paraules(linia);
		}
		else {
			//Acció "frases x y ?"
			
			string x, y;
			iss >> x;
			iss >> y;
			b.frasesxy(fer_num(x), fer_num(y));
		}
	}
	else if (op == "cites") {
		iss >> op;
		if (op == "autor") {
			//Acció "cites autor "<autor>" ?"
			
			ws(iss);
			getline(iss, op);
			c.cites_autor(op);
		}
		else if (op == "?") {
			//Acció "cites ?"
			
			if (not b.triat()) cout << "error" << endl;		//Si no hi ha un text triat, s'escriu error.
			if(c.cites_text(b)) b.autor_titol();			//Si el text té cites, s'escriuen seguides de l'autor i el títol.
		}
	}
	else if (linia == "totes cites ?") {
		//Acció "totes cites ?"
		
		c.totes_cites();
	}
}

/** @brief Programa principal per la pràctica <em>Gestió de textos i cites</em>.
*/
int main()
{
	string linia;
	getline(cin,linia);
    Biblioteca b;
    Cjt_cites c;
    while (linia != "sortir") {
		cout << linia << endl;
		operar (b, c, linia);
		getline(cin,linia);
	}
}
