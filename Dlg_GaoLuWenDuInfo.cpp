// Dlg_GaoLuWenDuInfo.cpp : implementation file
//

#include "stdafx.h"
#include "GaoLuCeWen.h"
#include "Dlg_GaoLuWenDuInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_GaoLuWenDuInfo dialog


CDlg_GaoLuWenDuInfo::CDlg_GaoLuWenDuInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_GaoLuWenDuInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_GaoLuWenDuInfo)
	//}}AFX_DATA_INIT
}


void CDlg_GaoLuWenDuInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_GaoLuWenDuInfo)
	DDX_Control(pDX, IDC_LIST1, m_ListCtr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_GaoLuWenDuInfo, CDialog)
	//{{AFX_MSG_MAP(CDlg_GaoLuWenDuInfo)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BTN_BaoCunDaoShuJvKu, OnBTNBaoCunDaoShuJvKu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_GaoLuWenDuInfo message handlers

BOOL CDlg_GaoLuWenDuInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	ReadWenDu();

	DWORD dwStyle = m_ListCtr.GetExtendedStyle();
	dwStyle |=  LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |  LVS_EX_ONECLICKACTIVATE;
	m_ListCtr.SetExtendedStyle(dwStyle);		//设置显示风格

	int i = 0,j,k,h,m = 0;
	m_ListCtr.InsertColumn(i++,"时刻",LVCFMT_CENTER,100);
	m_ListCtr.InsertColumn(i++,"所在层",LVCFMT_CENTER,100);
	CString strRDO;	
	for (h = 1; h <= 8; ++h)
	{
		strRDO.Format("%d号",h);
		m_ListCtr.InsertColumn(i++,strRDO,LVCFMT_CENTER,100);
	}
		
	CString strT,strCS,strWD;
	for (i = 0; i< 5; ++i )
	{
		for (j = 0; j < 4; ++j)
		{
			strT.Format("第%d分钟",i);
			m_ListCtr.InsertItem(m,strT);
			strCS.Format("%d",j + 1);			//层数
			m_ListCtr.SetItemText(m,1,strCS);
			for (k = 0; k < 8; ++k)
			{
				strWD.Format("%.2f",m_GLWD[i][j][k]);
				m_ListCtr.SetItemText(m,k + 2,strWD);	
			}
			++m;
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_GaoLuWenDuInfo::ReadWenDu()
{
	int i = 0,j,k;
	FILE *fp;
	fp = fopen("GaoLuWenDu.txt","r");
	if (fp == NULL)
	{
		CString str;
		str = "无法打开 GaoLuWenDu.txt 文件！";
		AfxMessageBox(str);
		exit(1);
	}
	else
	{
		for (i = 0; i < 5; ++i)
		{
			for (j = 0;j < 4; ++j)
			{
				for (k = 0; k < 8; ++k)
					fscanf(fp,"%lf",&m_GLWD[i][j][k]);
			}
		}
	}
	fclose(fp);
	
}

void CDlg_GaoLuWenDuInfo::OnBTNBaoCunDaoShuJvKu() 
{
	// TODO: Add your control notification handler code here
	int i,j,k;
	CString strSql,strRDO,strTime,strCS;
	strSql = "select * from GaoLuWenDu";
	m_ado.OnInitADOConn(".\\GaoLuWenDu.mdb");
	m_ado.GetRecordSet(strSql);
	for (i = 0; i< 5; ++i )
	{
		for (j = 0; j < 4; ++j)
		{
			strSql.Format("Insert Into GaoLuWenDu(STime,STier) Values\
				('第 %d 分钟','第%d层（高度%d米）')",i,j + 1,100 - (j + 1)*20);
			m_ado.ExecuteSQL(strSql);
		
			for (k = 0; k < 8; ++k)
			{
				strRDO.Format("SRDO%d",k + 1);
				strTime.Format("第 %d 分钟",i);

				strCS.Format("第%d层（高度%d米）",j + 1,100 - (j + 1)*20);
				strSql.Format("Update GaoLuWenDu Set " + strRDO + "= '%.2f' Where \
					(STime = '%s' and Stier = '%s')",m_GLWD[i][j][k],strTime,strCS);	
				m_ado.ExecuteSQL(strSql);
	
			}
		}
	}

}


void CDlg_GaoLuWenDuInfo::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}
