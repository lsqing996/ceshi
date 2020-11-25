// GaoLuWenDuJianCeDoc.cpp : implementation of the CGaoLuWenDuJianCeDoc class
//

#include "stdafx.h"
#include "GaoLuWenDuJianCe.h"

#include "GaoLuWenDuJianCeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeDoc

IMPLEMENT_DYNCREATE(CGaoLuWenDuJianCeDoc, CDocument)

BEGIN_MESSAGE_MAP(CGaoLuWenDuJianCeDoc, CDocument)
	//{{AFX_MSG_MAP(CGaoLuWenDuJianCeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeDoc construction/destruction

CGaoLuWenDuJianCeDoc::CGaoLuWenDuJianCeDoc()
{
	// TODO: add one-time construction code here

}

CGaoLuWenDuJianCeDoc::~CGaoLuWenDuJianCeDoc()
{
}

BOOL CGaoLuWenDuJianCeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeDoc serialization

void CGaoLuWenDuJianCeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeDoc diagnostics

#ifdef _DEBUG
void CGaoLuWenDuJianCeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGaoLuWenDuJianCeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeDoc commands
