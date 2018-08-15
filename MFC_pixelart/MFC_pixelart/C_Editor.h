#pragma once
#include <fstream>
#include "C_BLOQUE.h"

using namespace std;
class C_Editor
{
public:
	C_Editor();
	~C_Editor();
	vector<C_BLOQUE*> m_listaBloques;
	C_BLOQUE m_bloque;
	int m_numArchivos;
	int m_numLeves;
	int m_numeroAcrear;
	int m_NumNivACambiar;
	string m_numeroDeNiveles = "NIVELES";
	string m_nombreArchivo;
	string m_nivelACrear;
	string m_nivelACambiar;
	void contarNumNiveles(string niveles);
	void crear_archivo(string nombre_archivo);
	void modificarArchivo(string nombre_archivo);
	void modificar_archivoDeNiveles(int nuevoNumero);
	void reiniciar_bloques();
	void liberarArhivo();
	void CargarAEditar(CString CS_string);
	//void removerArchivo(string nombre_archivo);
	//void Editor_bloque(int posx, int posy);
	
};

