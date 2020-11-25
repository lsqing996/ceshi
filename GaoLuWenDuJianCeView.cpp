// GaoLuWenDuJianCeView.cpp : implementation of the CGaoLuWenDuJianCeView class
//

#include "stdafx.h"
#include "GaoLuWenDuJianCe.h"

#include "GaoLuWenDuJianCeDoc.h"
#include "GaoLuWenDuJianCeView.h"
#include "DlgWenDuInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeView

IMPLEMENT_DYNCREATE(CGaoLuWenDuJianCeView, CView)

BEGIN_MESSAGE_MAP(CGaoLuWenDuJianCeView, CView)
	//{{AFX_MSG_MAP(CGaoLuWenDuJianCeView)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_M_WenDuInfo, OnMWenDuInfo)
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeView construction/destruction

CGaoLuWenDuJianCeView::CGaoLuWenDuJianCeView()
{
	// TODO: add construction code here
	m_BJ_LBD = 0;
}

CGaoLuWenDuJianCeView::~CGaoLuWenDuJianCeView()
{
}

BOOL CGaoLuWenDuJianCeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeView drawing

void CGaoLuWenDuJianCeView::OnDraw(CDC* pDC)
{
	CGaoLuWenDuJianCeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC MemDC;
	int width,height;
	CRect rect;
	CBitmap MemBitMap; 
	GetWindowRect(&rect);
	width = rect.Width();
	height = rect.Height();
	MemDC.CreateCompatibleDC(pDC);
	MemBitMap.CreateCompatibleBitmap(pDC,width,height);
	CBitmap *pOldBitMap = MemDC.SelectObject(&MemBitMap);
	MemDC.FillSolidRect(0,0,width,height,RGB(255,255,255));
	MemDC.SetBkMode(TRANSPARENT);	
	
	m_GL.Draw(&MemDC);
	
	pDC->BitBlt(0,0,width,height,&MemDC,0,0,SRCCOPY);
	MemBitMap.DeleteObject();
	MemDC.DeleteDC();
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeView printing

BOOL CGaoLuWenDuJianCeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGaoLuWenDuJianCeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGaoLuWenDuJianCeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeView diagnostics

#ifdef _DEBUG
void CGaoLuWenDuJianCeView::AssertValid() const
{
	CView::AssertValid();
}

void CGaoLuWenDuJianCeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGaoLuWenDuJianCeDoc* CGaoLuWenDuJianCeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGaoLuWenDuJianCeDoc)));
	return (CGaoLuWenDuJianCeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaoLuWenDuJianCeView message handlers

BOOL CGaoLuWenDuJianCeView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	return CView::OnEraseBkgnd(pDC);
}

void CGaoLuWenDuJianCeView::OnMWenDuInfo() 
{
	// TODO: Add your command handler code here
	CDlgWenDuInfo dlg_WDInfo;
	dlg_WDInfo.DoModal();
}

BOOL CGaoLuWenDuJianCeView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if (zDelta > 0)
	{
		m_GL.m_kx *= 1.1;
		m_GL.m_ky *= 1.1;
	}
	if (zDelta < 0)
	{
		m_GL.m_kx *= 0.9;
		m_GL.m_ky *= 0.9;
	}
	Invalidate(TRUE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CGaoLuWenDuJianCeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_BJ_LBD = 1;
	m_TempYD = m_GL.m_YD;
	m_P_LBD = point;
	m_GL.m_bj = m_GL.PanDuan(point);
	Invalidate(TRUE);
	CView::OnLButtonDown(nFlags, point);
}

void CGaoLuWenDuJianCeView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
 	m_BJ_LBD = 0;
 	Invalidate(TRUE);
	CView::OnLButtonUp(nFlags, point);
}

void CGaoLuWenDuJianCeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_BJ_LBD)
	{
		m_GL.m_YD = m_TempYD + (point - m_P_LBD);
		Invalidate(TRUE);
	}	
	CView::OnMouseMove(nFlags, point);
}
