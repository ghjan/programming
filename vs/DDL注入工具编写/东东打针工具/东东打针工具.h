
// �������빤��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�������빤��App: 
// �йش����ʵ�֣������ �������빤��.cpp
//

class C�������빤��App : public CWinApp
{
public:
	C�������빤��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�������빤��App theApp;