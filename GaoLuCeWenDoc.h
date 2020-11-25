// GaoLuCeWenDoc.h : interface of the CGaoLuCeWenDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAOLUCEWENDOC_H__1299F32E_4933_4D9E_B0AA_F10D7D6461BE__INCLUDED_)
#define AFX_GAOLUCEWENDOC_H__1299F32E_4933_4D9E_B0AA_F10D7D6461BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGaoLuCeWenDoc : public CDocument
{
protected: // create from serialization only
	CGaoLuCeWenDoc();
	DECLARE_DYNCREATE(CGaoLuCeWenDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoLuCeWenDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGaoLuCeWenDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGaoLuCeWenDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOLUCEWENDOC_H__1299F32E_4933_4D9E_B0AA_F10D7D6461BE__INCLUDED_)
