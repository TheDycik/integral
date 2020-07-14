
// EkzSOSView.cpp: ���������� ������ CEkzSOSView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "SosEkz.h"
#include "SosEkzDoc.h"
#endif

#include "SosEkzDoc.h"
#include "SosEkzView.h"
#include "OhShit.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEkzSOSView

IMPLEMENT_DYNCREATE(CEkzSOSView, CView)

BEGIN_MESSAGE_MAP(CEkzSOSView, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEkzSOSView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// �������� ��� ����������� CEkzSOSView

CEkzSOSView::CEkzSOSView()
{
	// TODO: �������� ��� ��������

}

CEkzSOSView::~CEkzSOSView()
{
}

BOOL CEkzSOSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CEkzSOSView
double f(double x) {
	return sqrt(sin(x));
}

void CEkzSOSView::OnDraw(CDC* pDC)
{
	CSosEkzDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen *OldPen;

	CPen pen1(PS_SOLID, 2, RGB(0, 0, 0));

	OldPen = pDC->SelectObject(&pen1);
	
	CRect rect;
	GetClientRect(&rect);

	float lx = rect.Width();
	float ly = rect.Height();

	pDC->MoveTo(0, ly / 2);
	pDC->LineTo(lx, ly / 2);

	pDC->MoveTo(lx / 2, 0);
	pDC->LineTo(lx / 2, ly);

	pDC->MoveTo(lx / 2, ly / 2);

	double x;
	COLORREF color = (24, 210, 120);

		for (double i = -80; i <= 80; i += 0.001)
		{
			if (i <= 0)
			{
				x = ly / 2 + fabs(i * 50);
			}

			if (i > 0)
			{
				x = ly / 2 - fabs(i * 50);
			}

			double y = f(i) / 9* lx;

			pDC->SetPixel(ly + x, lx / 3 - y, color);
		}

		
	// TODO: �������� ����� ��� ��������� ��� ����������� ������
}


// ������ CEkzSOSView


void CEkzSOSView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEkzSOSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CEkzSOSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CEkzSOSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void CEkzSOSView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEkzSOSView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CEkzSOSView

#ifdef _DEBUG
void CEkzSOSView::AssertValid() const
{
	CView::AssertValid();
}

void CEkzSOSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSosEkzDoc* CEkzSOSView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSosEkzDoc)));
	return (CSosEkzDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CEkzSOSView
