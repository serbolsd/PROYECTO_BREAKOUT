#include "stdafx.h"
#include "C_Editor.h"


C_Editor::C_Editor()
{
}


C_Editor::~C_Editor()
{
}


void C_Editor::crear_archivo(string nombre_archivo)
{
	ofstream archivo_n(nombre_archivo.c_str(), ios::out);
	archivo_n.open(nombre_archivo.c_str());
	modificarArchivo(nombre_archivo);
	m_numLeves += 1;
	modificar_archivoDeNiveles(m_numLeves);
	contarNumNiveles(m_numeroDeNiveles);
	archivo_n.close();
}

void C_Editor::contarNumNiveles(string niveles)
{
	fstream m_a_leer(niveles.c_str());
	m_a_leer >> m_numArchivos;
	m_numLeves = m_numArchivos;
	ostringstream numero,numeroAcrear;
	numero << m_numLeves;
	numeroAcrear << (m_numLeves + 1);
	m_numeroAcrear = m_numLeves + 1;
	m_nivelACrear = numeroAcrear.str();
	m_NumNivACambiar = m_numeroAcrear;
	m_nombreArchivo = numero.str();
	m_a_leer.close();
}

void C_Editor::modificarArchivo(string nombre_archivo)
{
	ofstream* m_a_modificar=new ofstream(nombre_archivo.c_str(), ios::out);
	for (int i = 0; i < m_listaBloques.size(); i++)
	{
		*m_a_modificar << m_listaBloques[i]->m_posx << " " << m_listaBloques[i]->m_posy << " " << m_listaBloques[i]->m_resistencia;
		*m_a_modificar << '\n';
	}
	m_a_modificar->close();
}

void C_Editor::modificar_archivoDeNiveles(int nuevoNumero)
{
	ofstream m_a_modificar(m_numeroDeNiveles.c_str());
	ostringstream numero;
	numero << nuevoNumero;
	m_nombreArchivo = numero.str();
	m_a_modificar << m_nombreArchivo;
}

void C_Editor::reiniciar_bloques()
{
	while (m_listaBloques.size()>0)
	{
		m_listaBloques.pop_back();
	}
}

void C_Editor::liberarArhivo()
{
	while (m_nombreArchivo.size()>0)
	{
		m_nombreArchivo.pop_back();
	}
}

void C_Editor::CargarAEditar(CString CS_string)
{
	CT2CA CSaStr(CS_string);
	m_nivelACambiar = (CSaStr);
	m_nivelACrear = m_nivelACambiar;
	m_NumNivACambiar = atoi(m_nivelACambiar.c_str());
	m_NumNivACambiar -= 1;
	ostringstream m_numeroAString;
	m_numeroAString << m_NumNivACambiar;
	m_nombreArchivo = m_numeroAString.str();

}
/*
void C_Editor::removerArchivo(string nombre_archivo)
{
	std::remove(nombre_archivo);
}*/