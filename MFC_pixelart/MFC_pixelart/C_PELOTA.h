#pragma once
class C_PELOTA
{
public:
	C_PELOTA();
	C_PELOTA(CDC* Dc);
	~C_PELOTA();

	int m_posx=0, m_posy=400;
	int m_direcXx = 10, m_direcYy = -10;
	int m_Bola_alto;
	int m_Bola_ancho;
	int m_vidas = 3;

	CDC bmDC;
	BITMAP BOLASIZE;
	void PaintBall(CDC *Dc);
	void reiniciarposicion(RECT miRECT);
	void avance();
	void colision(int barraX, int barraAncho, int barraY, int blockX, int blockY, int blockancho, int blockalto, int& blockresist, bool& blockchoque,int& numeroBloques, RECT miRect,int barraAlto);
};