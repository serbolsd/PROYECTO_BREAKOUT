
// MFC_pixelartDlg.h: archivo de encabezado
//

#pragma once

#include "C_PELOTA.h"
#include "C_BARRA.h"
#include "afxwin.h"
#include "C_Editor.h"
#include "C_BLOQUE.h"
#include "C_NIVEL.h"


// Cuadro de diálogo de CMFCpixelartDlg
class CMFCpixelartDlg : public CDialog
{
	// Construcción
public:
	CMFCpixelartDlg(CWnd* pParent = NULL);	// Constructor estándar
	RECT m_miRect;
	CDC *m_AREA;
	C_BLOQUE *bloq;
	C_PELOTA *ball;
	C_BARRA *bar;
	C_Editor *Editor;
	C_BLOQUE *NUEVO_BLOQUE;
	C_NIVEL nivel;

	


	int m_Posicion_x_cursor = 0;
	int m_Posicion_y_cursor = 0;
	int m_clickPosicion_x_cursor = 0;
	int m_clickPosicion_y_cursor = 0;

	void Paintwhitet();
	void movimiento();
	void reiniciar_game();
	CString Mostrar_vidas(int vidas);

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_PIXELART_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV
	
	

// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CStatic m_GameAreaWnd;
	// m_ST_Nivel_actual
	CButton m_BtnEditor;
	afx_msg void OnBnClickedBtnEditor();
	//CButton m_BtnCreateBlock;
	//afx_msg void OnBnClickedBtnCreateBlock();
	afx_msg void OnBnClickedBtnok();
	//CButton M_ID_BTNOK;
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CButton M_BTNSaveNevel;
	CButton m_BTNCloseEditor;
	CButton m_BTNCloseGame;
	CButton m_BTNPlayGame;
	afx_msg void OnBnClickedBtnCloseeditor();
	afx_msg void OnBnClickedBtnSavenevel();
	afx_msg void OnBnClickedCancel();
	CEdit m_TxtNivelActual;
	afx_msg void OnEnChangeTxtnivelactual();
	CString M_TxtNIvelTexto;
	CEdit m_CN_TxtNumNiveles;
	CString m_CS_NumNivel;
	CEdit m_CN_TCambiarNivel;
	CEdit m_CN_TxtIngresarNivel;
	CString m_CS_IngresarNivel;
	CString m_CS_TxtCambioDeNivel;
	CButton m_BtnCambiarNivel;
	CButton m_BtnLimpiarNivel;
	afx_msg void OnBnClickedBtnlimpiarnivel();
	afx_msg void OnBnClickedBtncargarnivel();
	afx_msg void OnEnChangeTxtingresarnivel();
	afx_msg void OnEnChangeTxtNumnivel();
	afx_msg void OnBnClickedBtnblockRes2();
	CButton m_BTNBlockResist1;
	CButton m_BTNBlockResist2;
	CButton m_BTNBlockResist3;
	CButton m_BTNBlockResist4;
	afx_msg void OnBnClickedBtnblockRes1();
	afx_msg void OnBnClickedBtnblockRes3();
	afx_msg void OnBnClickedBtnblockRes4();
	CEdit m_CN_TCrearBloque;
	CString m_CS_TCrearBloque;
	CEdit m_CN_TCrearBloque2;
	CString m_CS_TCrearBloque2;
	afx_msg void OnStnClickedGameArea();
	CEdit m_CN_TextoVidas;
	CString m_CS_TextoVidas;
};

