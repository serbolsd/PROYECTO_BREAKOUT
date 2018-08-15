#include "stdafx.h"
#include "C_NIVEL.h"


C_NIVEL::C_NIVEL()
{
}


C_NIVEL::~C_NIVEL()
{
}

void C_NIVEL::contarNumNiveles(string niveles)
{
	fstream m_a_leer(niveles.c_str());
	m_a_leer >> m_NumDeNiveles;
	ostringstream numero;
	numero << m_NumDeNiveles;
	m_a_leer.close();
}

void C_NIVEL::m_cargarNivel(int nivelactual)
{
	ostringstream numero;
	numero << nivelactual;
	string nivel = numero.str();
	string lector="nada";
	int x, y;
	fstream* m_leerNivel=new fstream(nivel);
	while (lector!= "\0")
	{
		string posicionx;
		string posiciony;
		string resistencia;
		C_BLOQUE *Editor_bloque=new C_BLOQUE();
		getline(*m_leerNivel, lector);
		for (int i = 0; i < lector.size(); i++)
		{
			while (lector[i]!=' ')
			{
				posicionx += lector[i];
				i++;
			}
			i++;
			while (lector[i] != ' ')
			{
				posiciony += lector[i];
				i++;
			}
			i++;
			resistencia = lector[i];
				
		}
		if (lector != "\0")
		{

			Editor_bloque->m_posx = atoi(posicionx.c_str());
			Editor_bloque->m_posy = atoi(posiciony.c_str());
			Editor_bloque->m_resistencia = atoi(resistencia.c_str());
			m_listaBloques.push_back(Editor_bloque);
		}

	}
	m_NumDeBloques = m_listaBloques.size();
	m_leerNivel->close();

}

void C_NIVEL::m_reiniciarlista()
{
	while (m_listaBloques.size()>0)
	{
		m_listaBloques.pop_back();
	}
}