// DlgWenDuInfo.cpp : implementation file
//

#include "stdafx.h"
#include "GaoLuWenDuJianCe.h"
#include "DlgWenDuInfo.h"
#include "Dlg_WenDuInfoAppe.h"
#include "Dlg_WenDuInfoModi.h"
#include "Dlg_WenDuInfoDele.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgWenDuInfo dialog


CDlgWenDuInfo::CDlgWenDuInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgWenDuInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgWenDuInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgWenDuInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgWenDuInfo)
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgWenDuInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgWenDuInfo)
	ON_BN_CLICKED(IDC_BTN_Appe, OnBTNAppe)
	ON_BN_CLICKED(IDC_BTN_Modi, OnBTNModi)
	ON_BN_CLICKED(IDC_BTN_Dele, OnBTNDele)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickListWenDuInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgWenDuInfo message handlers

//重载对话框
BOOL CDlgWenDuInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strSql,strRDO,strWDT1,strWDT2,strWDT3,strWDT4,strWDT5,strWDT6,strWDT7,strWDT8;
    //strSql是查询语句的变量，后面的几个是数据库表中记录的字段名
	DWORD dwStyle; //定义列表框风格
	int i = 0;
	strSql = "select * from GLWD"; //查询语句，提取数据库中所有记录
	m_ado.OnInitADOConn(".\\GLWD.mdb"); //打开当前工程文件夹下的mdb，一个"."代表当前目录
	m_ado.GetRecordSet(strSql); //执行语句
	dwStyle = m_listCtrl.GetExtendedStyle(); //获取列表控件的风格
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES  | LVS_EX_ONECLICKACTIVATE; //加入你所需要的风格
	m_listCtrl.SetExtendedStyle(dwStyle); //设置显示风格
	m_listCtrl.InsertColumn(i++,"热电偶",LVCFMT_CENTER,100);

	CString lm;
	for (i=1;i<8;i++)
	{
		lm.Format("T%d时刻温度",i);
		m_listCtrl.InsertColumn(i,lm,LVCFMT_CENTER,100);
	}
// 	m_listCtrl.InsertColumn(i++,"T1时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T2时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T3时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T4时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T5时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T6时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T7时刻温度",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T8时刻温度",LVCFMT_CENTER,100); //设置字段名	
// 	i = 0;
	
	while (!m_ado.m_pRecordset->adoEOF) //通过内置的记录集调用，判断当前记录是否已经到了记录集的最后一个
	{ //若没有到记录集，我们进行循环
		strRDO = m_ado.GetCollect("RDO"); 
		//通过m_ado对象获取当前记录的字段值
		strWDT1 = m_ado.GetCollect("WDT1");
		strWDT2 = m_ado.GetCollect("WDT2");
		strWDT3 = m_ado.GetCollect("WDT3");
		strWDT4 = m_ado.GetCollect("WDT4");
		strWDT5 = m_ado.GetCollect("WDT5");
		strWDT6 = m_ado.GetCollect("WDT6");
		strWDT7 = m_ado.GetCollect("WDT7");
		strWDT8 = m_ado.GetCollect("WDT8");
		
		m_listCtrl.InsertItem(i,strRDO); //插入到列表控件中去
		m_listCtrl.SetItemText(i,1,strWDT1);
		m_listCtrl.SetItemText(i,2,strWDT2);
		m_listCtrl.SetItemText(i,3,strWDT3);
		m_listCtrl.SetItemText(i,4,strWDT4);
		m_listCtrl.SetItemText(i,5,strWDT5);
		m_listCtrl.SetItemText(i,6,strWDT6);
		m_listCtrl.SetItemText(i,7,strWDT7);
		m_listCtrl.SetItemText(i,8,strWDT8);
		
		m_ado.m_pRecordset->MoveNext(); //记录指针向下移动一个单位
		i++; //为下一次插入列表控件做准备
	}
	//i--;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE

}

void CDlgWenDuInfo::OnBTNAppe() 
{
	// TODO: Add your control notification handler code here
	int i;
	CDlg_WenDuInfoAppe dlg_Appe;
	if(IDOK == dlg_Appe.DoModal())
	{
		m_strRDO = dlg_Appe.m_RDO;
		m_strWDT1 = dlg_Appe.m_T1;
		m_strWDT2 = dlg_Appe.m_T2;
		m_strWDT3 = dlg_Appe.m_T3;
		m_strWDT4 = dlg_Appe.m_T4;
		m_strWDT5 = dlg_Appe.m_T5;
		m_strWDT6 = dlg_Appe.m_T6;
		m_strWDT7 = dlg_Appe.m_T7;
		m_strWDT8 = dlg_Appe.m_T8; //把"添加温度数据"对话框中的数据传过来，保存到温度信息对话框中
		
		//i = m_listCtrl.GetItemCount() - 3; //获取当前记录的数
		i = 4; //刚开始我们有4条记录
		
		//int pos; //添加的位置
		//pos = m_listCtrl.GetItemCount();
		m_listCtrl.InsertItem(i,m_strRDO);
		m_listCtrl.SetItemText(i,1,m_strWDT1);
		m_listCtrl.SetItemText(i,2,m_strWDT2);
		m_listCtrl.SetItemText(i,3,m_strWDT3);
		m_listCtrl.SetItemText(i,4,m_strWDT4);
		m_listCtrl.SetItemText(i,5,m_strWDT5);
		m_listCtrl.SetItemText(i,6,m_strWDT6);
		m_listCtrl.SetItemText(i,7,m_strWDT7);
		m_listCtrl.SetItemText(i,8,m_strWDT8); //把获取进来的数据插进去
		
		
		CString strSql = "delete from GLWD"; //清除数据库中的数据
		m_ado.ExecuteSQL(strSql);
		
		int recCount = m_listCtrl.GetItemCount(); //控件列表里面新增加的一条记录以后，它的记录总数
		
		for(i = 0; i < recCount; i++)
		{
			m_strRDO = m_listCtrl.GetItemText(i, 0);
			m_strWDT1 = m_listCtrl.GetItemText(i, 1);
			m_strWDT2 = m_listCtrl.GetItemText(i, 2);
			m_strWDT3 = m_listCtrl.GetItemText(i, 3);
			m_strWDT4 = m_listCtrl.GetItemText(i, 4);
			m_strWDT5 = m_listCtrl.GetItemText(i, 5);
			m_strWDT6 = m_listCtrl.GetItemText(i, 6);
			m_strWDT7 = m_listCtrl.GetItemText(i, 7);
			m_strWDT8 = m_listCtrl.GetItemText(i, 8); //获取当前控件列表里的信息
			strSql.Format("insert into GLWD (RDO,WDT1,WDT2,WDT3,WDT4,WDT5,WDT6,WDT7,WDT8) values('%s','%s','%s','%s','%s','%s',\
				'%s','%s','%s')",m_strRDO,m_strWDT1,m_strWDT2,m_strWDT3,m_strWDT4,m_strWDT5,m_strWDT6,m_strWDT7,m_strWDT8);
			m_ado.ExecuteSQL(strSql);
		}
			UpdateData(FALSE);
	}
}

void CDlgWenDuInfo::OnBTNModi() 
{
	// TODO: Add your control notification handler code here
	CDlg_WenDuInfoModi dlg_Modi;
	dlg_Modi.m_RDO = m_strRDO;
	dlg_Modi.m_T1 = m_strWDT1;
	dlg_Modi.m_T2 = m_strWDT2;
	dlg_Modi.m_T3 = m_strWDT3;
	dlg_Modi.m_T4 = m_strWDT4;
	dlg_Modi.m_T5 = m_strWDT5;
	dlg_Modi.m_T6 = m_strWDT6;
	dlg_Modi.m_T7 = m_strWDT7;
	dlg_Modi.m_T8 = m_strWDT8;
	
	if (dlg_Modi.DoModal() == IDOK) //把修改后的数据写回到当前显示窗口
	{
		m_strRDO = dlg_Modi.m_RDO;
		m_strWDT1 = dlg_Modi.m_T1;
		m_strWDT2 = dlg_Modi.m_T2;
		m_strWDT3 = dlg_Modi.m_T3;
		m_strWDT4 = dlg_Modi.m_T4;
		m_strWDT5 = dlg_Modi.m_T5;
		m_strWDT6 = dlg_Modi.m_T6;
		m_strWDT7 = dlg_Modi.m_T7;
		m_strWDT8 = dlg_Modi.m_T8;
		
		m_listCtrl.SetItemText(selPos,0,m_strRDO);
		m_listCtrl.SetItemText(selPos,1,m_strWDT1);
		m_listCtrl.SetItemText(selPos,2,m_strWDT2);
		m_listCtrl.SetItemText(selPos,3,m_strWDT3);
		m_listCtrl.SetItemText(selPos,4,m_strWDT4);
		m_listCtrl.SetItemText(selPos,5,m_strWDT5);
		m_listCtrl.SetItemText(selPos,6,m_strWDT6);
		m_listCtrl.SetItemText(selPos,7,m_strWDT7);
		m_listCtrl.SetItemText(selPos,8,m_strWDT8);
		
		CString strSql;
		strSql.Format("update GLWD set WDT1 = '%s',WDT2 = '%s',WDT3 = '%s',WDT4 = '%s',WDT5 = '%s',WDT6 = '%s',WDT7 = '%s',WDT8 = '%s'\
			where RDO = '%s'",m_strWDT1,m_strWDT2,m_strWDT3,m_strWDT4,m_strWDT5,m_strWDT6,m_strWDT7,m_strWDT8,m_strRDO);
		//根据当前"修改温度数据"对话框里的温度进行修改，通过热电偶定位到数据库表中相同的记录，对它进行更新
		m_ado.ExecuteSQL(strSql);
	}
}

void CDlgWenDuInfo::OnBTNDele() 
{
	// TODO: Add your control notification handler code here
	int pos;
	pos = m_listCtrl.GetSelectionMark(); //获取当前被鼠标选中的行
	m_listCtrl.DeleteItem(pos);
	CString strSql;
	strSql.Format("delete from GLWD where RDO = '%s'",m_strRDO);
	m_ado.ExecuteSQL(strSql);

}

void CDlgWenDuInfo::OnClickListWenDuInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos;
	pos = m_listCtrl.GetSelectionMark(); //获取当前被鼠标选中的行
	m_strRDO = m_listCtrl.GetItemText(pos,0); //把我们被选中的这条记录的相关信息读到显示对话框的成员变量中去
	m_strWDT1 = m_listCtrl.GetItemText(pos,1);
	m_strWDT2 = m_listCtrl.GetItemText(pos,2);
	m_strWDT3 = m_listCtrl.GetItemText(pos,3);
	m_strWDT4 = m_listCtrl.GetItemText(pos,4);
	m_strWDT5 = m_listCtrl.GetItemText(pos,5);
	m_strWDT6 = m_listCtrl.GetItemText(pos,6);
	m_strWDT7 = m_listCtrl.GetItemText(pos,7);
	m_strWDT8 = m_listCtrl.GetItemText(pos,8);
	//UpdateData(TRUE);
	selPos = pos;

	*pResult = 0;
}
