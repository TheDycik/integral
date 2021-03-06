
// SosEkzView.cpp: реализация класса CSosEkzView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SosEkz.h"
#endif

#include "SosEkzDoc.h"
#include "SosEkzView.h"
#include <cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSosEkzView

IMPLEMENT_DYNCREATE(CSosEkzView, CFormView)

BEGIN_MESSAGE_MAP(CSosEkzView, CFormView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSosEkzView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CSosEkzView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSosEkzView::OnBnClickedButton2)
END_MESSAGE_MAP()

// Создание или уничтожение CSosEkzView

CSosEkzView::CSosEkzView()
	: CFormView(IDD_SOSEKZ_FORM)
	, mLeft(0)
	, mMiddle(0)
	, mRight(0)
	, mTrap(0)
	, mSimp(0)
	, a(0.6)
	, b(1.5)
	, step(10000)
	, rootHalf(0)
	, valueHalf(0)
	, rootTang(0)
	, valueTang(0)
{
	// TODO: добавьте код создания

}

CSosEkzView::~CSosEkzView()
{
}

void CSosEkzView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mLeft);
	DDX_Text(pDX, IDC_EDIT2, mMiddle);
	DDX_Text(pDX, IDC_EDIT3, mRight);
	DDX_Text(pDX, IDC_EDIT4, mTrap);
	DDX_Text(pDX, IDC_EDIT5, mSimp);
	DDX_Text(pDX, IDC_EDIT6, a);
	DDX_Text(pDX, IDC_EDIT7, b);
	DDX_Text(pDX, IDC_EDIT8, step);
	DDX_Text(pDX, IDC_EDIT9, rootHalf);
	DDX_Text(pDX, IDC_EDIT10, valueHalf);
	DDX_Text(pDX, IDC_EDIT11, rootTang);
	DDX_Text(pDX, IDC_EDIT12, valueTang);
}

BOOL CSosEkzView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSosEkzView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Печать CSosEkzView


void CSosEkzView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSosEkzView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSosEkzView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSosEkzView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CSosEkzView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте свой код печати
}

void CSosEkzView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSosEkzView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CSosEkzView

#ifdef _DEBUG
void CSosEkzView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSosEkzView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSosEkzDoc* CSosEkzView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSosEkzDoc)));
	return (CSosEkzDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSosEkzView

double func1(double x) {
	return sqrt(sin(x));
}
double CSosEkzView::metLeft(int step, double a, double b) {
	double S = 0, h = (b - a) / step, x;

	for (int i = 1; i < step - 1; i++) {
		x = a + i * h;
		S = S + func1(x) + h / 2;
	}

	S = S * h;

	return S;
}
double CSosEkzView::metMiddle(int step, double a, double b) {
	double S = 0, h = (b - a) / step, x;

	for (int i = 1; i < step - 1; i++) {
		x = a + (i * h);
		S = S + func1(x) + (h / 2);
	}

	S = S * h;

	return S;
}
double CSosEkzView::metRight(int step, double a, double b) {
	double S = 0, h = (b - a) / step, x;

	for (int i = 1; i < step - 1; i++) {
		x = a + i * h;
		S = S + func1(x);
	}

	S = S * h;

	return S;
}
double CSosEkzView::metTrap(int step, double a, double b) {
	double S = 0, x, h = (b - a) / step;

	for (int i = 1; i < step; i++)
	{
		x = a + (i * h);
		S = S + ((func1(x) + func1(x)) / 2) * h;
	}

	return S;
}
double CSosEkzView::metSimp(int step, double a, double b) {
	double S = 0, x, h = (b - a) / step, k;

	S = S + func1(a);
	for (int i = 1; i < step; i++)
	{
		x = a + i * h;
		if (i % 2 == 0)
		{
			k = 2;
		}
		else
		{
			k = 4;
		}
		S = S + k * func1(x);
	}
	x = a + step * h;
	S = S + func1(x);
	return (S * h) / 3;

}


void CSosEkzView::OnBnClickedButton1()
{
	UpdateData(true);

	mLeft = metLeft(step, a, b);
	mMiddle = metMiddle(step, a, b);
	mRight = metRight(step, a, b);
	mTrap = metTrap(step, a, b);
	mSimp = metSimp(step, a, b);

	UpdateData(false);
	// TODO: добавьте свой код обработчика уведомлений
}

double func2(double x) {
	return log(x) + pow((x + 1), 3);
}
double df(double x) {
	return 3 * pow((x + 1), 2) + (1 / x);
}
double ddf(double x) {
	return (6 * x) - (1 / x * x) + 6;
}


void CSosEkzView::OnBnClickedButton2()
{
	UpdateData(true);
	double sigma, A, B, A1, B1, x1, a, b, a1, b1, x2, x21, t;

	a = 0;
	a1 = 0;
	sigma = 0.0001;

	do {
		a = a + 0.1;
		b = a + 0.1;

		A = func2(a);
		B = func2(b);

	} while (A * B > 0);

	do
	{
		x1 = (a + b) / 2;

		if (func2(a)*func2(x1) < 0) {
			b = x1;
		}
		else {
			a = x1;
		}

	} while (b - a > sigma);



	do {
		a1 = a1 + 0.1;
		b1 = a1 + 0.2;

		A1 = func2(a1);
		B1 = func2(b1);

	} while (A1*B1 > 0);

	if (func2(a1)*ddf(a1) > 0) {
		x2 = a;
	}
	else {
		x2 = b;
	}

	do {
		t = x2;

		x21 = x2 - (func2(x2) / df(x2));
		x2 = x21;

	} while (abs(x21 - t) > sigma);


	rootHalf = x1;
	valueHalf = func2(x1);
	rootTang = x2;
	valueTang = func2(x2);

	UpdateData(false);

	// TODO: добавьте свой код обработчика уведомлений
}
