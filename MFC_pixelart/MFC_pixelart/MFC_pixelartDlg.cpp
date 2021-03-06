
// MFC_pixelartDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "MFC_pixelart.h"
#include "MFC_pixelartDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo de CMFCpixelartDlg



CMFCpixelartDlg::CMFCpixelartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MFC_PIXELART_DIALOG, pParent)
	, M_TxtNIvelTexto(_T(""))
	, m_CS_NumNivel(_T(""))
	, m_CS_IngresarNivel(_T(""))
	, m_CS_TxtCambioDeNivel(_T(""))
	, m_CS_TCrearBloque(_T(""))
	, m_CS_TCrearBloque2(_T(""))
	, m_CS_TextoVidas(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCpixelartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GAME_AREA, m_GameAreaWnd);
	DDX_Control(pDX, IDC_BTN_EDITOR, m_BtnEditor);
	//DDX_Control(pDX, IDC_BTN_CREATE_BLOCK, m_BtnCreateBlock);
	//DDX_Control(pDX, IDC_BTNOK, M_ID_BTNOK);
	DDX_Control(pDX, IDC_BTN_SAVENEVEL, M_BTNSaveNevel);
	DDX_Control(pDX, IDC_BTN_CLOSEEDITOR, m_BTNCloseEditor);
	DDX_Control(pDX, IDCANCEL, m_BTNCloseGame);
	DDX_Control(pDX, IDOK, m_BTNPlayGame);
	DDX_Control(pDX, IDC_TXTNivelActual, m_TxtNivelActual);
	DDX_Text(pDX, IDC_TXTNivelActual, M_TxtNIvelTexto);
	DDX_Control(pDX, IDC_Txt_NUMNIVEL, m_CN_TxtNumNiveles);
	DDX_Text(pDX, IDC_Txt_NUMNIVEL, m_CS_NumNivel);
	DDX_Control(pDX, IDC_TxtCAMBIODENIVEL, m_CN_TCambiarNivel);
	DDX_Control(pDX, IDC_TXTINGRESARNIVEL, m_CN_TxtIngresarNivel);
	DDX_Text(pDX, IDC_TXTINGRESARNIVEL, m_CS_IngresarNivel);
	DDX_Text(pDX, IDC_TxtCAMBIODENIVEL, m_CS_TxtCambioDeNivel);
	DDX_Control(pDX, IDC_BTNCARGARNIVEL, m_BtnCambiarNivel);
	DDX_Control(pDX, IDC_BTNLIMPIARNIVEL, m_BtnLimpiarNivel);
	DDX_Control(pDX, IDC_BTNBLOCK_RES1, m_BTNBlockResist1);
	DDX_Control(pDX, IDC_BTNBLOCK_RES2, m_BTNBlockResist2);
	DDX_Control(pDX, IDC_BTNBLOCK_RES3, m_BTNBlockResist3);
	DDX_Control(pDX, IDC_BTNBLOCK_RES4, m_BTNBlockResist4);
	DDX_Control(pDX, IDC_TXTCREARBLOQUE, m_CN_TCrearBloque);
	DDX_Text(pDX, IDC_TXTCREARBLOQUE, m_CS_TCrearBloque);
	DDX_Control(pDX, IDC_TXTCREARBLOQUE2, m_CN_TCrearBloque2);
	DDX_Text(pDX, IDC_TXTCREARBLOQUE2, m_CS_TCrearBloque2);
	DDX_Control(pDX, IDC_TXTVIDAS, m_CN_TextoVidas);
	DDX_Text(pDX, IDC_TXTVIDAS, m_CS_TextoVidas);
}

BEGIN_MESSAGE_MAP(CMFCpixelartDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCpixelartDlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BTN_EDITOR, &CMFCpixelartDlg::OnBnClickedBtnEditor)
	//ON_BN_CLICKED(IDC_BTN_CREATE_BLOCK, &CMFCpixelartDlg::OnBnClickedBtnCreateBlock)
	//ON_BN_CLICKED(IDC_BTNOK, &CMFCpixelartDlg::OnBnClickedBtnok)
	ON_WM_MOUSEACTIVATE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BTN_CLOSEEDITOR, &CMFCpixelartDlg::OnBnClickedBtnCloseeditor)
	ON_BN_CLICKED(IDC_BTN_SAVENEVEL, &CMFCpixelartDlg::OnBnClickedBtnSavenevel)
	ON_BN_CLICKED(IDCANCEL, &CMFCpixelartDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_TXTNivelActual, &CMFCpixelartDlg::OnEnChangeTxtnivelactual)
	ON_BN_CLICKED(IDC_BTNLIMPIARNIVEL, &CMFCpixelartDlg::OnBnClickedBtnlimpiarnivel)
	ON_BN_CLICKED(IDC_BTNCARGARNIVEL, &CMFCpixelartDlg::OnBnClickedBtncargarnivel)
	ON_EN_CHANGE(IDC_TXTINGRESARNIVEL, &CMFCpixelartDlg::OnEnChangeTxtingresarnivel)
	ON_EN_CHANGE(IDC_Txt_NUMNIVEL, &CMFCpixelartDlg::OnEnChangeTxtNumnivel)
	ON_BN_CLICKED(IDC_BTNBLOCK_RES2, &CMFCpixelartDlg::OnBnClickedBtnblockRes2)
	ON_BN_CLICKED(IDC_BTNBLOCK_RES1, &CMFCpixelartDlg::OnBnClickedBtnblockRes1)
	ON_BN_CLICKED(IDC_BTNBLOCK_RES3, &CMFCpixelartDlg::OnBnClickedBtnblockRes3)
	ON_BN_CLICKED(IDC_BTNBLOCK_RES4, &CMFCpixelartDlg::OnBnClickedBtnblockRes4)
	ON_STN_CLICKED(IDC_GAME_AREA, &CMFCpixelartDlg::OnStnClickedGameArea)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCpixelartDlg

BOOL CMFCpixelartDlg::OnInitDialog()
{


	CDialog::OnInitDialog();

	m_GameAreaWnd.GetClientRect(&m_miRect);
	m_AREA = m_GameAreaWnd.GetDC();
	ball = new C_PELOTA(m_AREA);
	bar = new C_BARRA(m_AREA);
	bloq = new C_BLOQUE(m_AREA);
	Editor = new C_Editor();
	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: Editor aquí inicialización adicional
	//SetTimer(1, 33, NULL);
	//SetTimer(2, 499, NULL);

	//m_BtnCreateBlock.ShowWindow(SW_HIDE);
	//M_ID_BTNOK.ShowWindow(SW_HIDE);
	M_BTNSaveNevel.ShowWindow(SW_HIDE);
	m_BTNCloseEditor.ShowWindow(SW_HIDE);
	m_TxtNivelActual.ShowWindow(SW_HIDE);
	m_CN_TxtNumNiveles.ShowWindow(SW_HIDE);
	m_CN_TxtIngresarNivel.ShowWindow(SW_HIDE);
	m_CN_TCambiarNivel.ShowWindow(SW_HIDE);
	m_BtnCambiarNivel.ShowWindow(SW_HIDE);
	m_BtnLimpiarNivel.ShowWindow(SW_HIDE);
	m_BTNBlockResist1.ShowWindow(SW_HIDE);
	m_BTNBlockResist2.ShowWindow(SW_HIDE);
	m_BTNBlockResist3.ShowWindow(SW_HIDE);
	m_BTNBlockResist4.ShowWindow(SW_HIDE);
	m_CN_TCrearBloque.ShowWindow(SW_HIDE);
	m_CN_TCrearBloque2.ShowWindow(SW_HIDE);
	m_CN_TextoVidas.ShowWindow(SW_HIDE);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCpixelartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCpixelartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCpixelartDlg::OnBnClickedOk()
{

	//nivel.m_listaBloques = Editor->m_listaBloques;
	m_BtnEditor.ShowWindow(SW_HIDE);
	m_BTNPlayGame.ShowWindow(SW_HIDE);
	m_CN_TextoVidas.ShowWindow(SW_SHOW);
	m_CS_TextoVidas = Mostrar_vidas(ball->m_vidas);
	UpdateData(FALSE);
	bar->m_posy = m_miRect.bottom - 60;
	nivel.contarNumNiveles(Editor->m_numeroDeNiveles);
	nivel.m_cargarNivel(nivel.m_nivelActual);
	ball->m_posy = m_miRect.bottom - ball->m_Bola_alto*2;
	SetTimer(1, 33, NULL);
}



void CMFCpixelartDlg::Paintwhitet()
{
	CDC* pDC = this->GetDC();
	pDC->Rectangle(0,0,m_miRect.right,m_miRect.bottom);
}


void CMFCpixelartDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	
	//int Posicion_x_cursorante = Posicion_x_cursor;
	//Paintbafondo(Posicion_x_cursorante-1);
	//OnTimer(2);
		//Paintwhite(x-Xx,y-Yy);
	

	if (nIDEvent==1)
	{
		movimiento();
	}
	if (nIDEvent == 2)
	{
		Paintwhitet();
		for (int i = 0; i < Editor->m_listaBloques.size(); i++)
		{
			bloq->Paintblock(Editor->m_listaBloques[i]->m_posx, Editor->m_listaBloques[i]->m_posy, Editor->m_listaBloques[i]->m_resistencia, m_AREA);
		}
		bloq->Paintblock(m_Posicion_x_cursor - bloq->m_ancho / 2, m_Posicion_y_cursor - bloq->m_alto / 2, bloq->m_resistencia, m_AREA);
	}
	if (nIDEvent == 3)
	{
		for (int i = 0; i < Editor->m_listaBloques.size(); i++)
		{
			bloq->Paintblock(Editor->m_listaBloques[i]->m_posx, Editor->m_listaBloques[i]->m_posy, Editor->m_listaBloques[i]->m_resistencia, m_AREA);
		}
	}


}


void CMFCpixelartDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	CDialog::OnMouseMove(nFlags, point);
	m_Posicion_x_cursor = point.x;
	m_Posicion_y_cursor = point.y;
}

void CMFCpixelartDlg::movimiento()
{
	Paintwhitet();
	bar->PaintBar(m_miRect,m_AREA,m_Posicion_x_cursor);
	
	if (nivel.m_NumDeBloques>0)
	{
		for (int i = 0; i < nivel.m_listaBloques.size(); i++)
		{
			if (nivel.m_listaBloques[i]->m_choque)
			{
				bloq->Paintblock(nivel.m_listaBloques[i]->m_posx, nivel.m_listaBloques[i]->m_posy, nivel.m_listaBloques[i]->m_resistencia, m_AREA);
			}
			ball->colision(bar->m_posx, bar->m_barra_ancho, bar->m_posy, nivel.m_listaBloques[i]->m_posx, nivel.m_listaBloques[i]->m_posy, bloq->m_ancho, bloq->m_alto, nivel.m_listaBloques[i]->m_resistencia, nivel.m_listaBloques[i]->m_choque,nivel.m_NumDeBloques, m_miRect,bar->m_barra_alto);
		}
		m_CS_TextoVidas = Mostrar_vidas(ball->m_vidas);
		UpdateData(FALSE);
		ball->avance();
		ball->PaintBall(m_AREA);
		if (ball->m_vidas<=0)
		{
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			reiniciar_game();
			//CDialog::OnCancel();
			MessageBox(_T("¡¡¡PERDISTE!!! \n¡TE HAS QUEDADO SIN VIDAS!"));
		}
	}
	else if (nivel.m_nivelActual<nivel.m_NumDeNiveles -1)
	{ 
		ball->reiniciarposicion(m_miRect);
		nivel.m_reiniciarlista();
		nivel.m_nivelActual += 1;
		nivel.m_cargarNivel(nivel.m_nivelActual);

	}
	else
	{
		KillTimer(1);
		KillTimer(2);
		KillTimer(3);
		MessageBox(_T("¡¡¡FELICIDADES!!! \n¡HAS LOGRADO PASAR TODOS LOS NIVELES EXISTENTES!"));
		//CDialog::OnCancel();
		reiniciar_game();
	}
	
}


void CMFCpixelartDlg::OnBnClickedBtnEditor()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	//m_BtnCreateBlock.ShowWindow(SW_SHOW);
	MessageBox(_T("Al crear un bloque de click para colocarlo"));
	//M_ID_BTNOK.ShowWindow(SW_SHOW);
	m_BTNCloseEditor.ShowWindow(SW_SHOW);
	M_BTNSaveNevel.ShowWindow(SW_SHOW);
	m_BTNPlayGame.ShowWindow(SW_HIDE);
	m_CN_TxtNumNiveles.ShowWindow(SW_SHOW);
	m_TxtNivelActual.ShowWindow(SW_SHOW);
	m_CN_TxtIngresarNivel.ShowWindow(SW_SHOW);
	m_CN_TCambiarNivel.ShowWindow(SW_SHOW);
	m_BtnCambiarNivel.ShowWindow(SW_SHOW);
	m_BtnLimpiarNivel.ShowWindow(SW_SHOW);
	m_BTNBlockResist1.ShowWindow(SW_SHOW);
	m_BTNBlockResist2.ShowWindow(SW_SHOW);
	m_BTNBlockResist3.ShowWindow(SW_SHOW);
	m_BTNBlockResist4.ShowWindow(SW_SHOW);
	m_CN_TCrearBloque.ShowWindow(SW_SHOW);
	m_CN_TCrearBloque2.ShowWindow(SW_SHOW);
	Editor->contarNumNiveles(Editor->m_numeroDeNiveles);
	m_CS_TCrearBloque = "Crear bloque con";
	m_CS_TCrearBloque2 = "resistencia:";
	M_TxtNIvelTexto = "Nivel actual:";
	m_CS_NumNivel = CString(Editor->m_nivelACrear.c_str());
	m_CS_TxtCambioDeNivel = "Cambiar de nivel:";
	UpdateData(FALSE);
}

/*
void CMFCpixelartDlg::OnBnClickedBtnCreateBlock()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	SetTimer(2, 33, NULL);


}*/


void CMFCpixelartDlg::OnBnClickedBtnok()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	NUEVO_BLOQUE = new C_BLOQUE(m_AREA);
	NUEVO_BLOQUE->m_posx = m_clickPosicion_x_cursor - NUEVO_BLOQUE->m_ancho / 2;
	NUEVO_BLOQUE->m_posy = m_clickPosicion_y_cursor - NUEVO_BLOQUE->m_alto / 2;
	NUEVO_BLOQUE->m_resistencia = bloq->m_resistencia;
	Editor->m_listaBloques.push_back(NUEVO_BLOQUE);
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
}


int CMFCpixelartDlg::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	return CDialog::OnMouseActivate(pDesktopWnd, nHitTest, message);
}


void CMFCpixelartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	CDialog::OnLButtonDown(nFlags, point);
	m_clickPosicion_x_cursor = m_Posicion_x_cursor;
	m_clickPosicion_y_cursor=m_Posicion_y_cursor;
	NUEVO_BLOQUE = new C_BLOQUE(m_AREA);
	NUEVO_BLOQUE->m_posx = m_clickPosicion_x_cursor - NUEVO_BLOQUE->m_ancho / 2;
	NUEVO_BLOQUE->m_posy = m_clickPosicion_y_cursor - NUEVO_BLOQUE->m_alto / 2;
	NUEVO_BLOQUE->m_resistencia = bloq->m_resistencia;
	Editor->m_listaBloques.push_back(NUEVO_BLOQUE);
}


void CMFCpixelartDlg::OnBnClickedBtnCloseeditor()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	m_BTNPlayGame.ShowWindow(SW_SHOW);
	//m_BtnCreateBlock.ShowWindow(SW_HIDE);
	M_BTNSaveNevel.ShowWindow(SW_HIDE);
	//M_ID_BTNOK.ShowWindow(SW_HIDE);
	m_BTNCloseEditor.ShowWindow(SW_HIDE);
	m_CN_TxtNumNiveles.ShowWindow(SW_HIDE);
	m_TxtNivelActual.ShowWindow(SW_HIDE);
	m_CN_TxtIngresarNivel.ShowWindow(SW_HIDE);
	m_CN_TCambiarNivel.ShowWindow(SW_HIDE);
	m_BtnCambiarNivel.ShowWindow(SW_HIDE);
	m_BtnLimpiarNivel.ShowWindow(SW_HIDE);
	m_BTNBlockResist1.ShowWindow(SW_HIDE);
	m_BTNBlockResist2.ShowWindow(SW_HIDE);
	m_BTNBlockResist3.ShowWindow(SW_HIDE);
	m_BTNBlockResist4.ShowWindow(SW_HIDE);
	m_CN_TCrearBloque.ShowWindow(SW_HIDE);
	m_CN_TCrearBloque2.ShowWindow(SW_HIDE);
	Editor->reiniciar_bloques();
	Paintwhitet();
	KillTimer(2);
	KillTimer(3);
}


void CMFCpixelartDlg::OnBnClickedBtnSavenevel()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Editor->m_numLeves;
	if (Editor->m_NumNivACambiar == Editor->m_numeroAcrear-1)
	{
		Editor->crear_archivo(Editor->m_nombreArchivo);
	}
	else
	{
		Editor->modificarArchivo(Editor->m_nombreArchivo);
	}

	ostringstream m_numeroAString;
	m_numeroAString << Editor->m_numeroAcrear;
	Editor->m_nivelACambiar = m_numeroAString.str();
	UpdateData(TRUE);
	m_CS_NumNivel = CString(Editor->m_nivelACambiar.c_str());
	UpdateData(FALSE);
	Editor->reiniciar_bloques();
	Paintwhitet();
}


void CMFCpixelartDlg::OnBnClickedCancel()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	CDialog::OnCancel();
}


void CMFCpixelartDlg::OnEnChangeTxtnivelactual()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialog::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles
}


void CMFCpixelartDlg::OnBnClickedBtnlimpiarnivel()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	m_CS_NumNivel = CString(Editor->m_nivelACrear.c_str());
	UpdateData(FALSE);
	Editor->reiniciar_bloques();
	Paintwhitet();
}


void CMFCpixelartDlg::OnBnClickedBtncargarnivel()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Editor->reiniciar_bloques();
	Paintwhitet();
	UpdateData(TRUE);
	if (m_CS_IngresarNivel=="")
	{
		MessageBox(_T("Ingrese un nivel"));
	}
	else
	{
		CT2CA CSaStr(m_CS_IngresarNivel);
		m_CS_NumNivel = m_CS_IngresarNivel;
		Editor->CargarAEditar(m_CS_IngresarNivel);
		UpdateData(FALSE);
		if (Editor->m_NumNivACambiar < Editor->m_numeroAcrear - 1)
		{
			nivel.m_cargarNivel(Editor->m_NumNivACambiar);
			Editor->m_listaBloques = nivel.m_listaBloques;
			nivel.m_reiniciarlista();
		}
		else
		{
			MessageBox(_T("No existe ese nivel"));
			ostringstream m_numeroAString;
			m_numeroAString << Editor->m_numeroAcrear;
			Editor->m_nivelACambiar = m_numeroAString.str();
			UpdateData(TRUE);
			m_CS_NumNivel = CString(Editor->m_nivelACambiar.c_str());
			UpdateData(FALSE);
			Editor->CargarAEditar(m_CS_NumNivel);
		}
	}
	KillTimer(1);
	KillTimer(2);
	SetTimer(3, 33, NULL);
	
}


void CMFCpixelartDlg::OnEnChangeTxtingresarnivel()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialog::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles
}


void CMFCpixelartDlg::OnEnChangeTxtNumnivel()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialog::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles
}


void CMFCpixelartDlg::OnBnClickedBtnblockRes2()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	bloq->m_resistencia = 2;
	KillTimer(1);
	KillTimer(3);
	SetTimer(2, 33, NULL);
}


void CMFCpixelartDlg::OnBnClickedBtnblockRes1()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	bloq->m_resistencia = 1;
	KillTimer(1);
	KillTimer(3);
	SetTimer(2, 33, NULL);
}


void CMFCpixelartDlg::OnBnClickedBtnblockRes3()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	bloq->m_resistencia = 3;
	KillTimer(1);
	KillTimer(3);
	SetTimer(2, 33, NULL);
}


void CMFCpixelartDlg::OnBnClickedBtnblockRes4()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	bloq->m_resistencia = 4;
	KillTimer(1);
	KillTimer(3);
	SetTimer(2, 33, NULL);
}


void CMFCpixelartDlg::OnStnClickedGameArea()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
}

CString CMFCpixelartDlg::Mostrar_vidas(int vidas)
{
	CString vidasActuales;
	if (vidas == 1)
	{
		vidasActuales = "Vida=1";
	}
	else if (vidas==2)
	{
		vidasActuales = "Vida=2";
	}
	else if (vidas==3)
	{
		vidasActuales = "Vida=3";
	}
	
	return vidasActuales;
}

void CMFCpixelartDlg::reiniciar_game()
{
	Paintwhitet();
	ball->m_vidas = 3;
	nivel.m_nivelActual = 0;
	nivel.m_NumDeBloques = 0;
	nivel.m_reiniciarlista();
	ball->reiniciarposicion(m_miRect);
	m_BTNPlayGame.ShowWindow(SW_SHOW);
	m_BtnEditor.ShowWindow(SW_SHOW);
	m_CN_TextoVidas.ShowWindow(SW_HIDE);
}