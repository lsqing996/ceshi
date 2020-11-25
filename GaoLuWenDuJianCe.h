// GaoLuWenDuJianCe.h : main header file for the GAOLUWENDUJIANCE application
//

#if !defined(AFX_GAOLUWENDUJIANCE_H__E16899FC_4AC1_4D13_8945_A3521ACAFFAD__INCLUDED_)
#define AFX_GAOLUWENDUJIANCE_H__E16899FC_4AC1_4D13_8945_A3521ACAFFAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeApp:
// See GaoLuWenDuJianCe.cpp for the implementation of this class
//

class CGaoLuWenDuJianCeApp : public CWinApp
{
public:
	CGaoLuWenDuJianCeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoLuWenDuJianCeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGaoLuWenDuJianCeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOLUWENDUJIANCE_H__E16899FC_4AC1_4D13_8945_A3521ACAFFAD__INCLUDED_)
