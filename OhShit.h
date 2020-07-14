
// EkzSOSView.h: ��������� ������ CEkzSOSView
//

#pragma once
#include "afxwin.h"
#include "SosEkzDoc.h"



class CEkzSOSView : public CView
{
protected: // ������� ������ �� ������������
	CEkzSOSView();
	DECLARE_DYNCREATE(CEkzSOSView)

	// ��������
public:
	CSosEkzDoc * GetDocument() const;

	// ��������
public:

	// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// ����������
public:
	virtual ~CEkzSOSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ������ ������� � EkzSOSView.cpp
inline CEkzSOSDoc* CEkzSOSView::GetDocument() const
{
	return reinterpret_cast<CEkzSOSDoc*>(m_pDocument);
}
#endif

