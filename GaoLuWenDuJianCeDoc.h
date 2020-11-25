// GaoLuWenDuJianCeDoc.h : interface of the CGaoLuWenDuJianCeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAOLUWENDUJIANCEDOC_H__39EB7B87_5008_4D5A_926E_CE8193ABD8D3__INCLUDED_)
#define AFX_GAOLUWENDUJIANCEDOC_H__39EB7B87_5008_4D5A_926E_CE8193ABD8D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGaoLuWenDuJianCeDoc : public CDocument
{
protected: // create from serialization only
	CGaoLuWenDuJianCeDoc();
	DECLARE_DYNCREATE(CGaoLuWenDuJianCeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoLuWenDuJianCeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGaoLuWenDuJianCeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGaoLuWenDuJianCeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOLUWENDUJIANCEDOC_H__39EB7B87_5008_4D5A_926E_CE8193ABD8D3__INCLUDED_)
