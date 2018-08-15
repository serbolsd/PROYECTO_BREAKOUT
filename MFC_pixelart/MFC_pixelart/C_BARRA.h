#pragma once
class C_BARRA
{
public:
	C_BARRA();
	C_BARRA(CDC* Dc);
	~C_BARRA();
	CDC m_bmDC;
	int m_posx = 0;
	int m_posx2 = 0;
	int m_barra_alto;
	int m_barra_ancho;
	int m_posy;
	BITMAP m_BARRASIZE;
	void PaintBar(RECT miRect, CDC *Dc, int posicion);
};

