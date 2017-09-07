
// ֲ���ս��ʬMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ֲ���ս��ʬMFC.h"
#include "ֲ���ս��ʬMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cֲ���ս��ʬMFCDlg �Ի���



Cֲ���ս��ʬMFCDlg::Cֲ���ս��ʬMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cֲ���ս��ʬMFCDlg::IDD, pParent)
	, bigPass(_T(""))
	, smallPass(_T(""))
	, check(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cֲ���ս��ʬMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, bigPass);
	DDV_MaxChars(pDX, bigPass, 1);
	DDX_Text(pDX, IDC_EDIT2, smallPass);
	DDV_MaxChars(pDX, smallPass, 2);
	DDX_Text(pDX, IDC_STATIC1, check);
}

BEGIN_MESSAGE_MAP(Cֲ���ս��ʬMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton8)

	ON_BN_CLICKED(IDC_BUTTON10, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton10)

	ON_BN_CLICKED(IDC_BUTTON9, &Cֲ���ս��ʬMFCDlg::OnBnClickedButton9)
END_MESSAGE_MAP()



// Cֲ���ս��ʬMFCDlg ��Ϣ�������
BOOL IsSunUnLimite = false;
BOOL IsMoneyUnLimite = false;
BOOL IsCDUnLimite = false;
BOOL IsPause = true;
BOOL initWaigua(HANDLE *h);
void modifySun();
void modifyMoney();
void modifyCD();
void modifyPause();
void pauseYes(unsigned char *pCode, unsigned char code[]);
void pauseNo(unsigned char *pCode, unsigned char code[]);
void modifyPass(int pass);
unsigned char *pCode = (unsigned char*)0x00472B50;//��ͣ��ַ
unsigned char OldOpCode[3];

DWORD WINAPI waiguaThread(LPVOID lpThreadParameter)
{
	while (1)
	{
		if (IsSunUnLimite)
		{
			modifySun();
		}
		if (IsMoneyUnLimite)
		{
			modifyMoney();
		}
		if (IsCDUnLimite)
		{
			modifyCD();
		}
	}
}

BOOL Cֲ���ս��ʬMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	/* �����߳� �����޸����� */
	CreateThread(0, 0, waiguaThread, 0, 0, 0);
	check = "�����Ƿ�׽����Ϸ";
	UpdateData(false);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cֲ���ս��ʬMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cֲ���ս��ʬMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cֲ���ս��ʬMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IsSunUnLimite = TRUE;
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IsSunUnLimite = FALSE;
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IsMoneyUnLimite = true;
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IsMoneyUnLimite = false;
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IsCDUnLimite = true;
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	IsCDUnLimite = false;
}


void Cֲ���ս��ʬMFCDlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	pauseNo(pCode, OldOpCode);
	
}


void Cֲ���ս��ʬMFCDlg::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	unsigned char newOpCode[] = "\xC2\x04\x00";
	pauseYes(pCode, newOpCode);
}

void Cֲ���ս��ʬMFCDlg::OnBnClickedButton10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	long lBigPass = wcstol(bigPass, NULL, 10);
	long lSmallPass = wcstol(smallPass, NULL, 10);
	if (lBigPass < 1 || lBigPass > 6 || lSmallPass < 1 || lSmallPass > 10)
	{
		AfxMessageBox(TEXT("�ؿ����ϸ�"));
	}
	int pass = (lBigPass - 1) * 10 + lSmallPass;
	modifyPass(pass);
}


void Cֲ���ս��ʬMFCDlg::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	HANDLE hProcess;
	if (initWaigua(&hProcess))
	{
		ReadProcessMemory(hProcess, pCode, OldOpCode, 3, NULL);

		check = "����Ĵ󵨵�Ű��ʬ";
		UpdateData(false);
	}
	else
	{
		check = "δ��⵽��Ϸ";
		UpdateData(false);
	}
}
