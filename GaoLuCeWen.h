// GaoLuCeWen.h : main header file for the GAOLUCEWEN application
//

#if !defined(AFX_GAOLUCEWEN_H__12B8D507_AA9D_44A4_9088_E61464DF1500__INCLUDED_)
#define AFX_GAOLUCEWEN_H__12B8D507_AA9D_44A4_9088_E61464DF1500__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenApp:
// See GaoLuCeWen.cpp for the implementation of this class
//

class CGaoLuCeWenApp : public CWinApp
{
public:
	CGaoLuCeWenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoLuCeWenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGaoLuCeWenApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOLUCEWEN_H__12B8D507_AA9D_44A4_9088_E61464DF1500__INCLUDED_)
