
// SosEkz.h: основной файл заголовка для приложения SosEkz
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSosEkzApp:
// Сведения о реализации этого класса: SosEkz.cpp
//

class CSosEkzApp : public CWinAppEx
{
public:
	CSosEkzApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSosEkzApp theApp;
