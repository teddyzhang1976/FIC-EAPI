
// FIC-EAPI-GUITest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

//include eapi.h here
#include "FIC-EAPI.h"

// CFICEAPIGUITestApp: 
// �йش����ʵ�֣������ FIC-EAPI-GUITest.cpp
//

class CFICEAPIGUITestApp : public CWinApp
{
public:
	CFICEAPIGUITestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFICEAPIGUITestApp theApp;