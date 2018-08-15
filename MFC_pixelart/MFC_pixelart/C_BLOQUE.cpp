#include "stdafx.h"
#include "C_BLOQUE.h"


C_BLOQUE::C_BLOQUE()
{
}

C_BLOQUE::C_BLOQUE(CDC* Dc)
{
	HANDLE hBItimap1 = LoadImage(0, TEXT("block.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp1;
	bmp1.Attach(reinterpret_cast<HBITMAP>(hBItimap1));
	m_bmDC1.CreateCompatibleDC(Dc);
	bmp1.GetBitmap(&m_BLOQUESIZE);
	m_alto = m_BLOQUESIZE.bmHeight;
	m_ancho = m_BLOQUESIZE.bmWidth;
	CBitmap* oldBMP1 = m_bmDC1.SelectObject(&bmp1);

	HANDLE hBItimap2 = LoadImage(0, TEXT("block2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp2;
	bmp2.Attach(reinterpret_cast<HBITMAP>(hBItimap2));
	m_bmDC2.CreateCompatibleDC(Dc);
	CBitmap* oldBMP2 = m_bmDC2.SelectObject(&bmp2);

	HANDLE hBItimap3 = LoadImage(0, TEXT("block3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp3;
	bmp3.Attach(reinterpret_cast<HBITMAP>(hBItimap3));
	m_bmDC3.CreateCompatibleDC(Dc);
	CBitmap* oldBMP3 = m_bmDC3.SelectObject(&bmp3);

	HANDLE hBItimap4 = LoadImage(0, TEXT("block4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp4;
	bmp4.Attach(reinterpret_cast<HBITMAP>(hBItimap4));
	m_bmDC4.CreateCompatibleDC(Dc);
	CBitmap* oldBMP4 = m_bmDC4.SelectObject(&bmp4);
}

C_BLOQUE::~C_BLOQUE()
{
}

void C_BLOQUE::Paintblock(int px, int py,int resist,CDC* Dc)
{
	if (resist==1)
	{
		Dc->BitBlt(px, py, m_ancho, m_alto, &m_bmDC1, 0, 0, SRCCOPY);
	}
	else if (resist == 2)
	{
		Dc->BitBlt(px, py, m_ancho, m_alto, &m_bmDC2, 0, 0, SRCCOPY);
	}
	else if (resist == 3)
	{
		Dc->BitBlt(px, py, m_ancho, m_alto, &m_bmDC3, 0, 0, SRCCOPY);
	}
	else if (resist == 4)
	{
		Dc->BitBlt(px, py, m_ancho, m_alto, &m_bmDC4, 0, 0, SRCCOPY);
	}
}
/*void C_BLOQUE::resistencia_del_bloque(int resistencia)
{
	m_bloque_res_paint=m_imgBlock;
	ostringstream m_numeroAString;
	m_numeroAString << resistencia;
	m_bloque_res_paint += m_numeroAString.str();
	m_bloque_res_paint+=m_extencion;
}*/