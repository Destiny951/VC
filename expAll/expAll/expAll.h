
// expAll.h : expAll Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CexpAllApp:
// �йش����ʵ�֣������ expAll.cpp
//

class CexpAllApp : public CWinApp
{
public:
	CexpAllApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CexpAllApp theApp;
