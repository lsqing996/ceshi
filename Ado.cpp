#include "stdafx.h"
#include "Ado.h"
#include <string>

CAdo::CAdo()
{
}

CAdo::~CAdo()
{
}

void CAdo::OnInitADOConn()
{
	/// �Ե��̵߳ķ�ʽ����com����
	::CoInitialize(NULL);

	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");	// ����Connection����
		char pBuf[MAX_PATH];	// ���·���ı���
		CString DBpath,strConnect;

		//DBpath = "./db.mdb";
		DBpath = "./DB_CSMT.mdb";
		strConnect.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None"),DBpath);
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);	// �������ݿ�
	}
	catch(_com_error e)
	{
		//AfxMessageBox(_T("OnInitADOConn()"));
		ExpressErrInfo(e);
	}
}

void CAdo::OnInitADOConn(CString sourcePath)
{
	/// �Ե��̵߳ķ�ʽ����com����
	::CoInitialize(NULL);

	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");	// ����Connection����
		char pBuf[MAX_PATH];	// ���·���ı���
		CString strConnect;

		strConnect.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None"),sourcePath);
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);	// �������ݿ�
	}
	catch(_com_error e)
	{
		ExpressErrInfo(e);
	}
}

void CAdo::OnInitADOConnSQLServer()
{
	::CoInitialize(NULL);
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		CString strConnect;

		strConnect.Format(_T("Provider=SQLOLEDB;Data Sourse=Sql Server;Initial Catalog=master;User ID=sa;Password=sa"));
		m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);


	}
	catch(_com_error e)
	{
		ExpressErrInfo(e);
	}
}


_RecordsetPtr& CAdo::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		if (NULL == m_pConnection)
		{
			OnInitADOConn();
		}
		m_pRecordset.CreateInstance(__uuidof(Recordset));

		if (adStateOpen == m_pRecordset->State)
		{
			AfxMessageBox(_T("��¼����"));
			m_pRecordset->Close();
		}
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
	}

	catch(_com_error e)
	{
		ExpressErrInfo(e);
	}

	return m_pRecordset;
}



_RecordsetPtr& CAdo::GetRecordSet(CString strSQL)
{
	_bstr_t bstrSQL = (_bstr_t)strSQL;
	try
	{
		if(m_pConnection == NULL)
			OnInitADOConn();

		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(m_pRecordset->State == adStateOpen)
		{
			//AfxMessageBox(L"��¼����");
			m_pRecordset->Close();
			//m_pRecordset=NULL;
		}
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		//m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		variant_t m_dirno;
	}
	catch(_com_error e)
	{
		ExpressErrInfo(e);
	}

	return m_pRecordset;
}



BOOL CAdo::ExecuteSQL(_bstr_t bstrSQL)
{
	_variant_t RecordsAffected;
	try
	{
		if (NULL == m_pConnection)
		{
			OnInitADOConn();
		}
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);

		return TRUE;
	}
	catch(_com_error e)
	{
		ExpressErrInfo(e);
	}

	return FALSE;
}

BOOL CAdo::ExecuteSQL(CString strSQL)
{
	_bstr_t bstrSQL;
	_variant_t RecordsAffected;

	bstrSQL = (_bstr_t)strSQL;

	try
	{
		if(m_pConnection==NULL)
			OnInitADOConn();
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		ExpressErrInfo(e);
		return false;
	}
}


CString CAdo::GetCollect(CString strField)
{
	CString strValue;

	_variant_t variValue,variField;
	variField = (_variant_t)strField;

	variValue = m_pRecordset->GetCollect(variField);

	if( variValue.vt != VT_NULL)
	{
		strValue = (char *) _bstr_t  (variValue);
	}
	return strValue;
}

CString CAdo::GetCollect(CString strField,_RecordsetPtr& recordSet)
{
	CString strValue;

	_variant_t variValue,variField;
	variField = (_variant_t)strField;

	variValue = recordSet->GetCollect(variField);

	if( variValue.vt != VT_NULL)
	{
		strValue = (char *) _bstr_t(variValue);
	}
	return strValue;
}


//�ͷ�����
void CAdo::ExitConnect()
{
	try
	{
		if(m_pRecordset!=NULL && m_pRecordset->State != NULL)
		{
			m_pRecordset->Close();
			m_pRecordset = NULL;
		}

 		if( m_pConnection->State == adStateOpen)
		{
			m_pConnection->Close();
			m_pConnection = NULL;
		}
		::CoUninitialize();
	}
	catch(_com_error e)
	{
		ExpressErrInfo(e);
	} 
}

//��ʾ���ݿ������Ϣ
void CAdo::ExpressErrInfo(_com_error e)
{
	CString ErrorStr;  
	_bstr_t bstrSource(e.Source());  
	_bstr_t bstrDescription(e.Description());  
	ErrorStr.Format( "ADO Error Code meaning = %s Source = %s Description = %s",  
		e.ErrorMessage(), (LPCTSTR)bstrSource, (LPCTSTR)bstrDescription );  
	//�ڵ��Դ����д�ӡ������Ϣ,��Release���п���DBGView�鿴������Ϣ  

	AfxMessageBox(ErrorStr, MB_OK | MB_ICONERROR);  
}
