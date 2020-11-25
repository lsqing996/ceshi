// GaoLuWenDuJianCeView.h : interface of the CGaoLuWenDuJianCeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAOLUWENDUJIANCEVIEW_H__BE5F8BF7_6881_4679_9E18_8CCB39D470FC__INCLUDED_)
#define AFX_GAOLUWENDUJIANCEVIEW_H__BE5F8BF7_6881_4679_9E18_8CCB39D470FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GaoLu.h"


class CGaoLuWenDuJianCeView : public CView
{
protected: // create from serialization only
	CGaoLuWenDuJianCeView();
	DECLARE_DYNCREATE(CGaoLuWenDuJianCeView)

// Attributes
public:
	CGaoLuWenDuJianCeDoc* GetDocument();

// Operations
public:
	CGaoLu m_GL;//高炉
	int m_BJ_LBD;//鼠标按下标记
	CPoint m_P_LBD;
	CPoint m_TempYD;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoLuWenDuJianCeView)
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
	virtual ~CGaoLuWenDuJianCeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGaoLuWenDuJianCeView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMWenDuInfo();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GaoLuWenDuJianCeView.cpp
inline CGaoLuWenDuJianCeDoc* CGaoLuWenDuJianCeView::GetDocument()
   { return (CGaoLuWenDuJianCeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOLUWENDUJIANCEVIEW_H__BE5F8BF7_6881_4679_9E18_8CCB39D470FC__INCLUDED_)
