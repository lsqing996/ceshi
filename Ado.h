#ifndef _ADO_H_
#define _ADO_H_

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat_i386.tlb" no_namespace rename("EOF","adoEOF")\
	rename("LockTypeEnum","adoLockTypeEnum")\
	rename("FieldAttributeEnum","adoFieldAtttributeEnum")\
	rename("EditModeEnum","adoEditModeEnum")\
	rename("RecordStatusEnum","adoRecordStatusEnum")\
	rename("ParameterDirectionEnum","adoParameterDirectionEnum")\
rename("DataTypeEnum","adoDataTypeEnum")
//#import ".\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
class CAdo//:public CSingleton<CAdo>
{
public:
	static CAdo& getSingleton()
	{
		static CAdo mInstance;
		return mInstance;
	}
public:
	_RecordsetPtr m_pRecordset;
	_ConnectionPtr m_pConnection;
	
public:
	//���캯��
	CAdo();
	//��������
	virtual ~CAdo();
	
	//access���ݿ������
	void OnInitADOConn();
	void OnInitADOConn(CString sourcePath);
	
	//SqlServer ���ݿ������
	void OnInitADOConnSQLServer();
	
public:
	
	//��ѯ����ȡ��¼��
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(CString strSQL);
	
	//ִ��sql���
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	BOOL ExecuteSQL(CString strSQL);
	
	//��ĳһ���ֶζ�ȡ����
	CString GetCollect(CString strField);
	CString GetCollect(CString strField,_RecordsetPtr& recordSet);
	
	//�ͷ�����
	void ExitConnect();
	
	//��ʾ������Ϣ
	void ExpressErrInfo(_com_error e);
};

#endif	//_ADO_H_
