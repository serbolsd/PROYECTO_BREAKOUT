#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class C_BLOQUE
{
public:
	C_BLOQUE();
	C_BLOQUE(CDC* Dc);
	~C_BLOQUE();

	int m_posy;
	int m_posx;
	int m_alto;
	int m_ancho;
	int m_resistencia = 2;
	bool m_choque = true;
	
	string m_imgBlock = "block";
	string m_extencion = ".bmp";
	string m_bloque_res_paint;

	/*int m_block_alto;
	int m_block_ancho;*/
	BITMAP m_BLOQUESIZE;
	CDC m_bmDC1;
	CDC m_bmDC2;
	CDC m_bmDC3;
	CDC m_bmDC4;
	void Paintblock(int px, int py,int resist,CDC*dc);
	//void resistencia_del_bloque(int m_resistencia);
};

