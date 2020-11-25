#if !defined(AFX_DLG_GAOLUWENDUINFO_H__D2325008_1034_4069_9F8C_9B9FF0D0A596__INCLUDED_)
#define AFX_DLG_GAOLUWENDUINFO_H__D2325008_1034_4069_9F8C_9B9FF0D0A596__INCLUDED_
#include "Ado.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_GaoLuWenDuInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_GaoLuWenDuInfo dialog

class CDlg_GaoLuWenDuInfo : public CDialog
{
// Construction
public:
	void ReadWenDu();
	double m_GLWD[5][4][8];
	int m_nT;
	CAdo m_ado;
	CDlg_GaoLuWenDuInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_GaoLuWenDuInfo)
	enum { IDD = IDD_Dlg_GaoLuWenDuInfo };
	CListCtrl	m_ListCtr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_GaoLuWenDuInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_GaoLuWenDuInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBTNBaoCunDaoShuJvKu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_GAOLUWENDUINFO_H__D2325008_1034_4069_9F8C_9B9FF0D0A596__INCLUDED_)
