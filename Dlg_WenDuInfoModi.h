#if !defined(AFX_DLG_WENDUINFOMODI_H__4F6FCD31_A118_4763_AFEF_1A5F1FFB4146__INCLUDED_)
#define AFX_DLG_WENDUINFOMODI_H__4F6FCD31_A118_4763_AFEF_1A5F1FFB4146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_WenDuInfoModi.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_WenDuInfoModi dialog

class CDlg_WenDuInfoModi : public CDialog
{
// Construction
public:
	CDlg_WenDuInfoModi(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_WenDuInfoModi)
	enum { IDD = IDD_DlgModi };
	CString	m_RDO;
	CString	m_T1;
	CString	m_T2;
	CString	m_T3;
	CString	m_T4;
	CString	m_T5;
	CString	m_T6;
	CString	m_T7;
	CString	m_T8;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_WenDuInfoModi)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_WenDuInfoModi)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_WENDUINFOMODI_H__4F6FCD31_A118_4763_AFEF_1A5F1FFB4146__INCLUDED_)
