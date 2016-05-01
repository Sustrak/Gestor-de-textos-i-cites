/**
 * @mainpage Pràctica PRO2:  Gestió de textos i cites.

Aplicació per a gestionar informació de textos i cites associades a aquest textos.
*/

/** @file main.cc
    @brief Programa principal per la pràctica <em>Gestió de textos i cites</em>.
*/
#ifndef NO_DIAGRAM
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#endif

#include "Biblioteca.hh"
#include "Cjt_cites.hh"
#include "Text.hh"
using namespace std;

void operar (Biblioteca& b, Cjt_cites& c, string& linia)
{
	istringstream iss(linia);
	string op;
	iss >> op;

	if (op == "afegir") {
		iss >> op;
		if (op == "text") {
			b.afegir_text(linia);
		}
		else if (op == "cita") {
			int x, y;
			iss >> op;
			x = op[0] -'0';
			iss >> op;
			y = op[0] -'0';
			c.afegir_cita(b.text_triat(), x, y);
		}
	}
	else if (op == "triar") {
		iss >> op;
		if (op == "text") {
			b.triar_text(linia);
		}
	}
	else if (op == "eliminar") {
		iss >> op;
		if (op == "text") {
			b.eliminar_text();
		}
		else if (op == "cita") {
			iss >> op;
			c.eliminar_cita(op);
		}
	}
	else if (op == "substitueix") {
		string par1, par2;
		iss >> par1;
		iss >> op;
		iss >> par2;
		b.substitueix(par1, par2);
	}
	else if (op == "textos") {
		iss >> op;
		if (op == "autor") {
			iss >> op;
			b.textos_autor(op);
		}
	}
	else if (op == "tots") {
		iss >> op;
		if (op == "textos") {
			b.tots_textos();
		}
		else if (op == "autors") {
			b.tots_autors();
		}
	}
	else if (op == "info") {
		iss >> op;
		if (op == "?") b.info();
		else if (op == "cita") {
			iss >> op;
			c.info_cita(op);
		}
	}
	else if (op == "autor") {
		b.autor();
	}
	else if (linia == "contingut ?") {
		b.contingut();
	}
	else if (op == "frases") {
		int x, y;
		iss >> op;
		x = op[0] -'0';
		iss >> op;
		y = op[0] -'0';
		b.frasesxy(x, y);
	}
	else if (linia == "nombre de frases ?") {
		b.nombre_frases();
	}
	else if (linia == "nombre de paraules ?") {
		b.nombre_paraules();
	}
	else if (linia == "taula de frequencies ?") {
		b.taula_freq();
	}
	else if (op == "frases") {
		iss >> op;
		if (op[0] == '"') {
			b.frases_paraules(linia);
		}
		else b.frases_expressio(linia);
	}
	else if (op == "cites") {
		iss >> op;
		if (op == "autor") {
			iss >> op;
			c.cites_autor(op);
		}
		else if (op == "?") {
			c.cites_text(b.text_triat());
		}
	}
	else if (linia == "totes cites ?") {
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