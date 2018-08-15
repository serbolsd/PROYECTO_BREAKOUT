#include "stdafx.h"
#include "C_BARRA.h"

C_BARRA::C_BARRA(CDC* Dc)
{
	HANDLE hBItimap = LoadImage(0, TEXT("barra.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBItimap));
	m_bmDC.CreateCompatibleDC(Dc);
	bmp.GetBitmap(&m_BARRASIZE);
	m_barra_alto = m_BARRASIZE.bmHeight;
	m_barra_ancho = m_BARRASIZE.bmWidth;
	CBitmap* oldBMP = m_bmDC.SelectObject(&bmp);
}

C_BARRA::C_BARRA()
{
	
}


C_BARRA::~C_BARRA()
{
}

void C_BARRA::PaintBar(RECT miRect, CDC *Dc, int posicion)
{

	m_posx = posicion - m_barra_ancho/2;
	m_posx2 = posicion + m_barra_ancho / 2;
	if (m_posx < miRect.left)
	{
		m_posx = miRect.left;
		m_posx2 = m_posx + 120;
	}
	else if (m_posx2>miRect.right)
	{
		m_posx2 = miRect.right;
		m_posx = m_posx2 - 120;
	}
	Dc->BitBlt(m_posx, miRect.bottom - 60, 120, 40, &m_bmDC, 0, 0, SRCCOPY);
}