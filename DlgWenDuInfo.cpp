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

//���ضԻ���
BOOL CDlgWenDuInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strSql,strRDO,strWDT1,strWDT2,strWDT3,strWDT4,strWDT5,strWDT6,strWDT7,strWDT8;
    //strSql�ǲ�ѯ���ı���������ļ��������ݿ���м�¼���ֶ���
	DWORD dwStyle; //�����б����
	int i = 0;
	strSql = "select * from GLWD"; //��ѯ��䣬��ȡ���ݿ������м�¼
	m_ado.OnInitADOConn(".\\GLWD.mdb"); //�򿪵�ǰ�����ļ����µ�mdb��һ��"."����ǰĿ¼
	m_ado.GetRecordSet(strSql); //ִ�����
	dwStyle = m_listCtrl.GetExtendedStyle(); //��ȡ�б�ؼ��ķ��
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES  | LVS_EX_ONECLICKACTIVATE; //����������Ҫ�ķ��
	m_listCtrl.SetExtendedStyle(dwStyle); //������ʾ���
	m_listCtrl.InsertColumn(i++,"�ȵ�ż",LVCFMT_CENTER,100);

	CString lm;
	for (i=1;i<8;i++)
	{
		lm.Format("T%dʱ���¶�",i);
		m_listCtrl.InsertColumn(i,lm,LVCFMT_CENTER,100);
	}
// 	m_listCtrl.InsertColumn(i++,"T1ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T2ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T3ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T4ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T5ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T6ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T7ʱ���¶�",LVCFMT_CENTER,100);
// 	m_listCtrl.InsertColumn(i++,"T8ʱ���¶�",LVCFMT_CENTER,100); //�����ֶ���	
// 	i = 0;
	
	while (!m_ado.m_pRecordset->adoEOF) //ͨ�����õļ�¼�����ã��жϵ�ǰ��¼�Ƿ��Ѿ����˼�¼�������һ��
	{ //��û�е���¼�������ǽ���ѭ��
		strRDO = m_ado.GetCollect("RDO"); 
		//ͨ��m_ado�����ȡ��ǰ��¼���ֶ�ֵ
		strWDT1 = m_ado.GetCollect("WDT1");
		strWDT2 = m_ado.GetCollect("WDT2");
		strWDT3 = m_ado.GetCollect("WDT3");
		strWDT4 = m_ado.GetCollect("WDT4");
		strWDT5 = m_ado.GetCollect("WDT5");
		strWDT6 = m_ado.GetCollect("WDT6");
		strWDT7 = m_ado.GetCollect("WDT7");
		strWDT8 = m_ado.GetCollect("WDT8");
		
		m_listCtrl.InsertItem(i,strRDO); //���뵽�б�ؼ���ȥ
		m_listCtrl.SetItemText(i,1,strWDT1);
		m_listCtrl.SetItemText(i,2,strWDT2);
		m_listCtrl.SetItemText(i,3,strWDT3);
		m_listCtrl.SetItemText(i,4,strWDT4);
		m_listCtrl.SetItemText(i,5,strWDT5);
		m_listCtrl.SetItemText(i,6,strWDT6);
		m_listCtrl.SetItemText(i,7,strWDT7);
		m_listCtrl.SetItemText(i,8,strWDT8);
		
		m_ado.m_pRecordset->MoveNext(); //��¼ָ�������ƶ�һ����λ
		i++; //Ϊ��һ�β����б�ؼ���׼��
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
		m_strWDT8 = dlg_Appe.m_T8; //��"����¶�����"�Ի����е����ݴ����������浽�¶���Ϣ�Ի�����
		
		//i = m_listCtrl.GetItemCount() - 3; //��ȡ��ǰ��¼����
		i = 4; //�տ�ʼ������4����¼
		
		//int pos; //��ӵ�λ��
		//pos = m_listCtrl.GetItemCount();
		m_listCtrl.InsertItem(i,m_strRDO);
		m_listCtrl.SetItemText(i,1,m_strWDT1);
		m_listCtrl.SetItemText(i,2,m_strWDT2);
		m_listCtrl.SetItemText(i,3,m_strWDT3);
		m_listCtrl.SetItemText(i,4,m_strWDT4);
		m_listCtrl.SetItemText(i,5,m_strWDT5);
		m_listCtrl.SetItemText(i,6,m_strWDT6);
		m_listCtrl.SetItemText(i,7,m_strWDT7);
		m_listCtrl.SetItemText(i,8,m_strWDT8); //�ѻ�ȡ���������ݲ��ȥ
		
		
		CString strSql = "delete from GLWD"; //������ݿ��е�����
		m_ado.ExecuteSQL(strSql);
		
		int recCount = m_listCtrl.GetItemCount(); //�ؼ��б����������ӵ�һ����¼�Ժ����ļ�¼����
		
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
			m_strWDT8 = m_listCtrl.GetItemText(i, 8); //��ȡ��ǰ�ؼ��б������Ϣ
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
	
	if (dlg_Modi.DoModal() == IDOK) //���޸ĺ������д�ص���ǰ��ʾ����
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
		//���ݵ�ǰ"�޸��¶�����"�Ի�������¶Ƚ����޸ģ�ͨ���ȵ�ż��λ�����ݿ������ͬ�ļ�¼���������и���
		m_ado.ExecuteSQL(strSql);
	}
}

void CDlgWenDuInfo::OnBTNDele() 
{
	// TODO: Add your control notification handler code here
	int pos;
	pos = m_listCtrl.GetSelectionMark(); //��ȡ��ǰ�����ѡ�е���
	m_listCtrl.DeleteItem(pos);
	CString strSql;
	strSql.Format("delete from GLWD where RDO = '%s'",m_strRDO);
	m_ado.ExecuteSQL(strSql);

}

void CDlgWenDuInfo::OnClickListWenDuInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int pos;
	pos = m_listCtrl.GetSelectionMark(); //��ȡ��ǰ�����ѡ�е���
	m_strRDO = m_listCtrl.GetItemText(pos,0); //�����Ǳ�ѡ�е�������¼�������Ϣ������ʾ�Ի���ĳ�Ա������ȥ
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
