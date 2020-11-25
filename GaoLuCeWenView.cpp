// GaoLuCeWenView.cpp : implementation of the CGaoLuCeWenView class
//

#include "stdafx.h"
#include "GaoLuCeWen.h"

#include "GaoLuCeWenDoc.h"
#include "GaoLuCeWenView.h"
#include "Dlg_GaoLuWenDuInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenView

IMPLEMENT_DYNCREATE(CGaoLuCeWenView, CView)

BEGIN_MESSAGE_MAP(CGaoLuCeWenView, CView)
	//{{AFX_MSG_MAP(CGaoLuCeWenView)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_M_GaoLuWenDu, OnMGaoLuWenDu)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenView construction/destruction

CGaoLuCeWenView::CGaoLuCeWenView()
{
	// TODO: add construction code here

}

CGaoLuCeWenView::~CGaoLuCeWenView()
{
}

BOOL CGaoLuCeWenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenView drawing

void CGaoLuCeWenView::OnDraw(CDC* pDC)
{
	CGaoLuCeWenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC MemDC;
	CRect rect;
	CBitmap MemBitMap;			//缓存的内存位图
	GetWindowRect(&rect);
	width = rect.Width();		//获得窗口的宽度
	height = rect.Height();		//获得窗口的高度
	MemDC.CreateCompatibleDC(pDC);		//建立兼容内存DC
	MemBitMap.CreateCompatibleBitmap(pDC,width,height);
	CBitmap *pOldBitMap = MemDC.SelectObject(&MemBitMap);   //把之前的内存位图保存下来，防止以后需要用  
	MemDC.FillSolidRect(0,0,width,height,RGB(255,255,255)); //设置背景颜色
	MemDC.SetBkMode(TRANSPARENT);


	m_GaoLu.Draw(&MemDC);



	pDC->BitBlt(0,0,width,height,&MemDC,0,0,SRCCOPY);
	MemBitMap.DeleteObject();
	MemDC.DeleteDC();
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenView printing

BOOL CGaoLuCeWenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGaoLuCeWenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGaoLuCeWenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenView diagnostics

#ifdef _DEBUG
void CGaoLuCeWenView::AssertValid() const
{
	CView::AssertValid();
}

void CGaoLuCeWenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGaoLuCeWenDoc* CGaoLuCeWenView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGaoLuCeWenDoc)));
	return (CGaoLuCeWenDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGaoLuCeWenView message handlers

BOOL CGaoLuCeWenView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;

	return CView::OnEraseBkgnd(pDC);
}

void CGaoLuCeWenView::OnMGaoLuWenDu() 
{
	// TODO: Add your command handler code here
	CDlg_GaoLuWenDuInfo dlg_GLWD;
	dlg_GLWD.DoModal();
	
}

void CGaoLuCeWenView::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	



	*pResult = 0;
}

void CGaoLuCeWenView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_GaoLu.ChuLiLBD(point))
		Invalidate(true);
	
	CView::OnLButtonDown(nFlags, point);
}
