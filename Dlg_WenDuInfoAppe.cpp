// Dlg_WenDuInfoAppe.cpp : implementation file
//

#include "stdafx.h"
#include "GaoLuWenDuJianCe.h"
#include "Dlg_WenDuInfoAppe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_WenDuInfoAppe dialog


CDlg_WenDuInfoAppe::CDlg_WenDuInfoAppe(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_WenDuInfoAppe::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_WenDuInfoAppe)
	m_RDO = _T("");
	m_T1 = _T("");
	m_T2 = _T("");
	m_T3 = _T("");
	m_T4 = _T("");
	m_T5 = _T("");
	m_T6 = _T("");
	m_T7 = _T("");
	m_T8 = _T("");
	//}}AFX_DATA_INIT
}


void CDlg_WenDuInfoAppe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_WenDuInfoAppe)
	DDX_Text(pDX, IDC_EDT_RDO, m_RDO);
	DDX_Text(pDX, IDC_EDT_WDT1, m_T1);
	DDX_Text(pDX, IDC_EDT_WDT2, m_T2);
	DDX_Text(pDX, IDC_EDT_WDT3, m_T3);
	DDX_Text(pDX, IDC_EDT_WDT4, m_T4);
	DDX_Text(pDX, IDC_EDT_WDT5, m_T5);
	DDX_Text(pDX, IDC_EDT_WDT6, m_T6);
	DDX_Text(pDX, IDC_EDT_WDT7, m_T7);
	DDX_Text(pDX, IDC_EDT_WDT8, m_T8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_WenDuInfoAppe, CDialog)
	//{{AFX_MSG_MAP(CDlg_WenDuInfoAppe)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_WenDuInfoAppe message handlers
