
// EkzSOSView.h: интерфейс класса CEkzSOSView
//

#pragma once
#include "afxwin.h"
#include "SosEkzDoc.h"



class CEkzSOSView : public CView
{
protected: // создать только из сериализации
	CEkzSOSView();
	DECLARE_DYNCREATE(CEkzSOSView)

	// Атрибуты
public:
	CSosEkzDoc * GetDocument() const;

	// Операции
public:

	// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Реализация
public:
	virtual ~CEkzSOSView();
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
};

#ifndef _DEBUG  // версия отладки в EkzSOSView.cpp
inline CEkzSOSDoc* CEkzSOSView::GetDocument() const
{
	return reinterpret_cast<CEkzSOSDoc*>(m_pDocument);
}
#endif

