#pragma once


// Диалоговое окно IntegralDlg

class IntegralDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IntegralDlg)

public:
	IntegralDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~IntegralDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOSEKZ_FORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
