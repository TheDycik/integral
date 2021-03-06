
// SosEkzView.h: интерфейс класса CSosEkzView
//

#pragma once


class CSosEkzView : public CFormView
{
protected: // создать только из сериализации
	CSosEkzView();
	DECLARE_DYNCREATE(CSosEkzView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SOSEKZ_FORM };
#endif

// Атрибуты
public:
	CSosEkzDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSosEkzView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	double mLeft;
	double mMiddle;
	double mRight;
	double mTrap;
	double mSimp;
	double a;
	double b;
	int step;
	double rootHalf;
	double valueHalf;
	double rootTang;
	double valueTang;
	double metLeft(int step, double a, double b);
	double metMiddle(int step, double a, double b);
	double metRight(int step, double a, double b);
	double metTrap(int step, double a, double b);
	double metSimp(int step, double a, double b);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // версия отладки в SosEkzView.cpp
inline CSosEkzDoc* CSosEkzView::GetDocument() const
   { return reinterpret_cast<CSosEkzDoc*>(m_pDocument); }
#endif

