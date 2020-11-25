// GaoLuCeWenDoc.cpp : implementation of the CGaoLuCeWenDoc class
//

#include "stdafx.h"
#include "GaoLuCeWen.h"

#include "GaoLuCeWenDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenDoc

IMPLEMENT_DYNCREATE(CGaoLuCeWenDoc, CDocument)

BEGIN_MESSAGE_MAP(CGaoLuCeWenDoc, CDocument)
	//{{AFX_MSG_MAP(CGaoLuCeWenDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenDoc construction/destruction

CGaoLuCeWenDoc::CGaoLuCeWenDoc()
{
	// TODO: add one-time construction code here

}

CGaoLuCeWenDoc::~CGaoLuCeWenDoc()
{
}

BOOL CGaoLuCeWenDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenDoc serialization

void CGaoLuCeWenDoc::Serialize(CArchive& ar)
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
// CGaoLuCeWenDoc diagnostics

#ifdef _DEBUG
void CGaoLuCeWenDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGaoLuCeWenDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenDoc commands
