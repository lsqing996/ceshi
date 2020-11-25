// GaoLuCeWenView.h : interface of the CGaoLuCeWenView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAOLUCEWENVIEW_H__D60844CB_1EE6_4EAB_8A96_5CFEB006DEAC__INCLUDED_)
#define AFX_GAOLUCEWENVIEW_H__D60844CB_1EE6_4EAB_8A96_5CFEB006DEAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GaoLu.h"


class CGaoLuCeWenView : public CView
{
protected: // create from serialization only
	CGaoLuCeWenView();
	DECLARE_DYNCREATE(CGaoLuCeWenView)

// Attributes
public:
	CGaoLuCeWenDoc* GetDocument();

// Operations
public:
	int height;
	int width;
	GaoLu m_GaoLu;



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoLuCeWenView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGaoLuCeWenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGaoLuCeWenView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMGaoLuWenDu();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GaoLuCeWenView.cpp
inline CGaoLuCeWenDoc* CGaoLuCeWenView::GetDocument()
   { return (CGaoLuCeWenDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOLUCEWENVIEW_H__D60844CB_1EE6_4EAB_8A96_5CFEB006DEAC__INCLUDED_)
