
// ֲ���ս��ʬMFCDlg.h : ͷ�ļ�
//

#pragma once


// Cֲ���ս��ʬMFCDlg �Ի���
class Cֲ���ս��ʬMFCDlg : public CDialogEx
{
// ����
public:
	Cֲ���ս��ʬMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	// ���
	CString bigPass;
	// С��
	CString smallPass;
	afx_msg void OnBnClickedButton10();

	afx_msg void OnBnClickedButton9();
	CString check;
};
