#include "Ado.h"
#if !defined(AFX_DLGWENDUINFO_H__546EDAD4_E90F_4F4B_AF7B_1285937D1108__INCLUDED_)
#define AFX_DLGWENDUINFO_H__546EDAD4_E90F_4F4B_AF7B_1285937D1108__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgWenDuInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgWenDuInfo dialog

class CDlgWenDuInfo : public CDialog
{
// Construction
public:
	CDlgWenDuInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgWenDuInfo)
	enum { IDD = IDD_DlgWenDuInfo };
	CListCtrl	m_listCtrl;
	//}}AFX_DATA
	CAdo m_ado; //定义CAdo类的对象
	int i; //标记当前数据列表的最大行的数值
	CString m_strRDO,m_strWDT1,m_strWDT2,m_strWDT3,m_strWDT4,m_strWDT5,m_strWDT6,m_strWDT7,m_strWDT8;
	int selPos; //当前数据列表被选中的行
	//自己定义的数据不能放在上面的AFX_DATA中，否则系统解析会出错
	
	CString m_RDO,m_T1,m_T2,m_T3,m_T4,m_T5,m_T6,m_T7,m_T8;
	
	int m_listSelPos; //获取当前被选中的位置

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgWenDuInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgWenDuInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnBTNAppe();
	afx_msg void OnBTNModi();
	afx_msg void OnBTNDele();
	afx_msg void OnClickListWenDuInfo(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWENDUINFO_H__546EDAD4_E90F_4F4B_AF7B_1285937D1108__INCLUDED_)
