
// ֲ���ս��ʬMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cֲ���ս��ʬMFCApp: 
// �йش����ʵ�֣������ ֲ���ս��ʬMFC.cpp
//

class Cֲ���ս��ʬMFCApp : public CWinApp
{
public:
	Cֲ���ս��ʬMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cֲ���ս��ʬMFCApp theApp;