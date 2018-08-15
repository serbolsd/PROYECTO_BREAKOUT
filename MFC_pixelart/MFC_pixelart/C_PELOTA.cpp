#include "stdafx.h"
#include "C_PELOTA.h"

C_PELOTA::C_PELOTA()
{

}

C_PELOTA::C_PELOTA(CDC *Dc)
{
	HANDLE hBItimap = LoadImage(0, TEXT("ball.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBItimap));
	bmDC.CreateCompatibleDC(Dc);
	bmp.GetBitmap(&BOLASIZE);
	m_Bola_alto = BOLASIZE.bmHeight;
	m_Bola_ancho = BOLASIZE.bmWidth;
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
}


C_PELOTA::~C_PELOTA()
{
}

void C_PELOTA::PaintBall(CDC*Dc)
{
	
	Dc->BitBlt(m_posx, m_posy, m_Bola_ancho, m_Bola_alto, &bmDC, 0, 0, SRCCOPY);
}

void C_PELOTA::colision(int barraX,int barraAncho,int barraY,int blockX,int blockY,int blockancho,int blockalto,int& blockresist,bool& blockchoque,int& numeroBloques,RECT miRect,int barraAlto)
{
	if (m_posx > (miRect.right) - m_Bola_ancho)
	{
		m_direcXx = -10;
	}
	if (m_posx <= 0)
	{
		m_direcXx = 10;
	}
	if (m_posy > (miRect.bottom) - m_Bola_ancho)
	{
		m_vidas -= 1;
		reiniciarposicion(miRect);
	}
	if (m_posy < 0)
	{
		m_direcYy = 10;
	}
	if (m_posx + m_Bola_ancho > barraX && m_posx <barraX + barraAncho)
	{
		if (m_posy + m_Bola_ancho > barraY && m_posy + m_Bola_ancho < barraY + barraAlto)
		{
			m_direcYy = -10;
		}
	}
	if (blockchoque)
	{

		if (m_posy + m_Bola_alto > blockY && m_posy < (blockY + blockalto))
		{
			// Condiciones Mouse Middle
			if (m_posx + m_Bola_ancho > blockX + 10 && m_posx< blockX + blockancho - 10) // m_BitBallHeight / 2 = 32
			{
				if (m_direcYy == -10)
					m_direcYy = 10;
				else
					m_direcYy = -10;
				blockresist -= 1;
				//Ball.DirX = 5;
			}
		}
		if (m_posx + m_Bola_ancho > blockX  && m_posx< blockX + blockancho)
		{
			// Condiciones Mouse Middle
			if (m_posy + m_Bola_alto > blockY + 10 && m_posy < (blockY + blockalto - 10)) // m_BitBallHeight / 2 = 32
			{
				if (m_direcXx == -10)
					m_direcXx = 10;
				else
					m_direcXx = -10;
				//Ball.DirX = 5;
				blockresist -= 1;
			}
		}
		if (blockresist <= 0)
		{
			blockchoque = false;
			numeroBloques -= 1;
		}
	}

}

void C_PELOTA::reiniciarposicion(RECT miRect)
{
	m_posy = miRect.bottom - m_Bola_alto * 2;
	m_posx = 0;
	m_direcXx = 10;
	m_direcYy = -10;
}
void C_PELOTA::avance()
{
	m_posx += m_direcXx;
	m_posy += m_direcYy;
}