#if !defined(AFX_DLG_WENDUINFOAPPE_H__8A59430E_6A92_4A46_A63A_854A63DF0362__INCLUDED_)
#define AFX_DLG_WENDUINFOAPPE_H__8A59430E_6A92_4A46_A63A_854A63DF0362__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_WenDuInfoAppe.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_WenDuInfoAppe dialog

class CDlg_WenDuInfoAppe : public CDialog
{
// Construction
public:
	CDlg_WenDuInfoAppe(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_WenDuInfoAppe)
	enum { IDD = IDD_DlgAppe };
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
	//{{AFX_VIRTUAL(CDlg_WenDuInfoAppe)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_WenDuInfoAppe)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_WENDUINFOAPPE_H__8A59430E_6A92_4A46_A63A_854A63DF0362__INCLUDED_)
