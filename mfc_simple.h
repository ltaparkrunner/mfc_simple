
// mfc_simple.h: основной файл заголовка для приложения mfc_simple
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CmfcsimpleApp:
// Сведения о реализации этого класса: mfc_simple.cpp
//

class CmfcsimpleApp : public CWinApp
{
public:
	CmfcsimpleApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CmfcsimpleApp theApp;
