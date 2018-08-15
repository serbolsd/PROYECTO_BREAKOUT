#pragma once
#include <fstream>
#include "C_BLOQUE.h"

using namespace std;
class C_NIVEL
{
public:
	C_NIVEL();
	~C_NIVEL();
	vector<C_BLOQUE*> m_listaBloques;
	int m_nivelActual=0;
	int m_NumDeNiveles;
	int m_NumDeBloques;
	string m_mivelEnPantalla;
	void contarNumNiveles(string niveles);
	void m_cargarNivel(int nivelactual);
	void m_reiniciarlista();
};

