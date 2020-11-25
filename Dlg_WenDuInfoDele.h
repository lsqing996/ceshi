#if !defined(AFX_DLG_WENDUINFODELE_H__8CE75F7C_886E_4EF7_B16A_4FC3DB4A8379__INCLUDED_)
#define AFX_DLG_WENDUINFODELE_H__8CE75F7C_886E_4EF7_B16A_4FC3DB4A8379__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_WenDuInfoDele.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_WenDuInfoDele dialog

class CDlg_WenDuInfoDele : public CDialog
{
// Construction
public:
	CDlg_WenDuInfoDele(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_WenDuInfoDele)
	enum { IDD = IDD_DlgDele };
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
	//{{AFX_VIRTUAL(CDlg_WenDuInfoDele)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_WenDuInfoDele)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_WENDUINFODELE_H__8CE75F7C_886E_4EF7_B16A_4FC3DB4A8379__INCLUDED_)
