// IntegralDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "SosEkz.h"
#include "IntegralDlg.h"
#include "afxdialogex.h"


// Диалоговое окно IntegralDlg

IMPLEMENT_DYNAMIC(IntegralDlg, CDialogEx)

IntegralDlg::IntegralDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SOSEKZ_FORM, pParent)
{

}

IntegralDlg::~IntegralDlg()
{
}

void IntegralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IntegralDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений IntegralDlg
