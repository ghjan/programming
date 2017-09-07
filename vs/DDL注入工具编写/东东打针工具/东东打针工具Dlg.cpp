
// �������빤��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�������빤��.h"
#include "�������빤��Dlg.h"
#include "afxdialogex.h"

#include <TlHelp32.h>
#include <AtlConv.h>

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


// C�������빤��Dlg �Ի���



C�������빤��Dlg::C�������빤��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�������빤��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�������빤��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, mEditBrowse);
	DDX_Control(pDX, IDC_LIST1, mPropListBox);
}

BEGIN_MESSAGE_MAP(C�������빤��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &C�������빤��Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &C�������빤��Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &C�������빤��Dlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// C�������빤��Dlg ��Ϣ�������

BOOL C�������빤��Dlg::OnInitDialog()
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	C�������빤��Dlg::OnBnClickedOk();
	mEditBrowse.EnableFileBrowseButton(NULL, _T("Dll Files (*.dll)|*.dll|All Files (*.*)|*.*||"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�������빤��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�������빤��Dlg::OnPaint()
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
HCURSOR C�������빤��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�������빤��Dlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void C�������빤��Dlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	//AfxMessageBox(L"������");//L""����unicode��
	//AfxMessageBox(TEXT("text"));//TEXT��ʾ�Զ��������

	//�������ListBox
	mPropListBox.ResetContent();

	//�������̿���
	HANDLE hProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hProcessSnapshot)//INVALID_HANDLE_VALUE == -1
	{
		AfxMessageBox(TEXT("Error while create snapshot"));//TEXT��ʾ�Զ��������
		return;
	}

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);//���ô�С

	Process32First(hProcessSnapshot, &pe);//��ȡ��һ��������Ϣ������pe�ṹ����
	//AfxMessageBox(pe.szExeFile);//��һ����ϵͳ�Ŀս��̣�����Ҫ
	TCHAR szProcessString[MAX_PATH];
	TCHAR *szBit;
	int i = 0;
	SYSTEM_INFO si;
	GetNativeSystemInfo(&si);
	while (Process32Next(hProcessSnapshot, &pe))
	{
		//�жϽ�����32λ����64λ
		//�ӽ���id��ȡ���̾��
		if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);//��ȡ����Ȩ��,��ȡ���̾��
			if (NULL == hProcess)
			{
				continue;//��Щ���̴򲻿���ϵͳ���̴򲻿���ֱ������
			}
			//�п�����64λ����
			BOOL bWow64;
			if (!IsWow64Process(hProcess, &bWow64))
			{
				AfxMessageBox(L"�жϽ���bitʧ��");
				return;
			}
			CloseHandle(hProcess);
			if (bWow64)//�����64λ��ģ���32λ
			{
				//32
				szBit = TEXT("32λ");
			}
			else
			{
				//64
				szBit = TEXT("64λ");
			}
		}
		else if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
		{
			//32λ
			szBit = TEXT("32λ");
		}
		else
		{
			//����
			szBit = TEXT("unKnow");
		}
		_stprintf_s(szProcessString, TEXT("��%s��->%s  PID:%d"), szBit, pe.szExeFile, pe.th32ProcessID);
		//�����н��̼��뵽ListBox
		int iListIndex = mPropListBox.AddString(szProcessString);
		//��������iD����ӽ����ַ�����һ��   //��������id������������һ��Ҫ��������id
		mPropListBox.SetItemData(iListIndex, pe.th32ProcessID);

	}
	CloseHandle(hProcessSnapshot);
}

//��OpenProcess - ���ڴ�Ҫ������Ŀ����̡�
//��VirtualAllocEx / VirtualFreeEx - ������Ŀ������з��� / �ͷ��ڴ�ռ䡣
//��WriteProcessMemory - ������Ŀ�������д��Ҫ���ص�DLL���ơ�
//��CreateRemoteThread - Զ�̼���DLL�ĺ������ݣ����ڿ���Ŀ����̵���API������
//��LoadLibrary - Ŀ�����ͨ�����ô˺��������ز���DLL��
BOOL RemoteLoadLibrary(HANDLE hProcess, LPCSTR lpLibFileName)
{
	if ((CString)lpLibFileName == "")
	{
		AfxMessageBox(TEXT("�����Ƿ����DLL�ļ�"));
		return FALSE;
	}
	// ��Ŀ����̵�ַ�ռ�д��DLL����
	DWORD dwSize;// , dwWritten;
	SIZE_T dwWritten;
	dwSize = lstrlenA(lpLibFileName) + 1;
	//�ڶԷ������������ռ�
	PCHAR pMem = (PCHAR)VirtualAllocEx(hProcess, NULL, dwSize, MEM_COMMIT, PAGE_READWRITE);
	if (NULL == pMem)
	{
		return FALSE;
	}
	//��Է���������дDLL��ַ�ַ���	
	if (WriteProcessMemory(hProcess, pMem, (LPVOID)lpLibFileName, dwSize, &dwWritten))
	{
		// Ҫд���ֽ�����ʵ��д���ֽ�������ȣ�����ʧ��
		if (dwWritten != dwSize)
		{
			VirtualFreeEx(hProcess, pMem, dwSize, MEM_DECOMMIT);//�ͷſռ�
			CloseHandle(hProcess);
			// ʧ�ܴ���
			return FALSE;
		}
		//ͨ�����
	}
	else
	{
		CloseHandle(hProcess);
		// ʧ�ܴ���
		return FALSE;
	}
	/// ʹĿ����̵���LoadLibrary������DLL
	DWORD dwID;
	//LPVOID pFunc = LoadLibraryA;
	//HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pFunc, pMem, 0, &dwID);
	//if (hThread == NULL)
	//{
	//	//AfxMessageBox(TEXT("ע��ʧ��"));
	//	return FALSE;
	//}
	HMODULE  hModule = LoadLibrary(TEXT("kernel32.dll"));
	LPTHREAD_START_ROUTINE pfThread = (LPTHREAD_START_ROUTINE)GetProcAddress(hModule, "LoadLibraryA");//GetModuleHandle(_T("Kernel32"))��һ���ɲ���Ҳ����������
	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, pfThread, pMem, 0, &dwID);

	//��Զ�̴������߳������м��ص�DLL�еĺ���LoadLibraryA("������inject.dll");
	//HMODULE  hModule2 = pfThread - LoadLibraryA + ExitCode;
	//LPTHREAD_START_ROUTINE pfnStartAddr = (PTHREAD_START_ROUTINE)GetProcAddress(, "go");//GetModuleHandle(TEXT("ע�����.dll"))
	//if (pfnStartAddr == NULL)
	//{
	//	MessageBox(NULL, L"��ȡ����go�ĵ�ַʧ��", L"Error", MB_OK);
	//	return FALSE;
	//}
	//HANDLE hThread2;
	//if ((hThread2 = CreateRemoteThread(hProcess, NULL, 0, pfnStartAddr, pMem, 0, &dwID)) == NULL)
	//{
	//	MessageBox(NULL, L"����Զ���߳�PrintMsgʧ��", L"Error", MB_OK);
	//	return FALSE;
	//}
	//WaitForSingleObject(hThread2, INFINITE);
	//FreeLibrary(hModule2);

	// �ȴ�LoadLibrary�������
	WaitForSingleObject(hThread, INFINITE);

	DWORD ExitCode;
	GetExitCodeThread(hThread, &ExitCode);//ExitCodeȡ�õ�HMODULE��Ŀ����̣�Զ�̣���ģ���ַ
	CloseHandle(hThread);
	// �ͷ�Ŀ�����������Ŀռ�
	VirtualFreeEx(hProcess, pMem, dwSize, MEM_DECOMMIT);
	return ExitCode;
}
BOOL RemoteLoadLibrary2(HANDLE hProcess, LPCSTR lpLibFileName)
{
	PCHAR lpRemoteLibFileName = (PCHAR)VirtualAllocEx(hProcess, NULL, lstrlenA(lpLibFileName) + 1, MEM_COMMIT, PAGE_READWRITE);
	if (lpRemoteLibFileName == NULL)
	{
		return FALSE;
	}
	WriteProcessMemory(hProcess, lpRemoteLibFileName, (void *)lpLibFileName, lstrlenA(lpLibFileName) + 1, NULL);
	PTHREAD_START_ROUTINE pfnStartAddr = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(_T("Kernel32")), "LoadLibraryA");
	HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, pfnStartAddr, lpRemoteLibFileName, 0, NULL);
	if (hRemoteThread == NULL)
	{
		return FALSE;
	}
	WaitForSingleObject(hRemoteThread, INFINITE);
	DWORD ExitCode;
	GetExitCodeThread(hRemoteThread, &ExitCode);
	CloseHandle(hRemoteThread);
	VirtualFreeEx(hProcess, lpRemoteLibFileName, 0, MEM_RELEASE);

	return ExitCode;
}

void C�������빤��Dlg::OnBnClickedOk2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	USES_CONVERSION;//�������Ϳ�����W2A��

	CString strDLLPathName;
	mEditBrowse.GetWindowText(strDLLPathName);

	//��ȡѡ�еĽ���id,���򿪽���
	int iSelectIndex = mPropListBox.GetCurSel();
	DWORD pid = mPropListBox.GetItemData(iSelectIndex);
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | SYNCHRONIZE | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, pid);
	if (INVALID_HANDLE_VALUE == hProcess || NULL == hProcess)
	{
		AfxMessageBox(_T("�򿪽���ʧ��!"));
		return;
	}
	//Ȼ��ͨ��PID��ȡ���̾��
	if (RemoteLoadLibrary(hProcess, W2A(strDLLPathName)))//������ﲻ��W2A��һֱע�벻�ɹ���������Ƶ��û���ã�Ҳ�ɹ���
	{
		MessageBoxA(0, "�ɹ�ע��", "��ϲ", 0);
	}
	else
	{
		AfxMessageBox(_T("ע��ʧ��"));
	}

}

