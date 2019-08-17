
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once

#include "inputNameDlg.h"
#include "TW_ListBox.h"

typedef struct FileItemInformation
{
	unsigned int attr;
	unsigned int h_size;
	unsigned int l_size;
	wchar_t * p_name;
	unsigned short name_len;
} FII;

class TW_FileListBox : public TW_ListBox
{
public:
	virtual void DrawUserItem(CDC *ap_dc, RECT *ap_rect, int a_index, void * ap_data, unsigned char a_select_flag, unsigned char a_focus_flag)
	{
		FII * p = (FII*)ap_data;
		
		if (p->attr & FILE_ATTRIBUTE_DIRECTORY) {
			ap_dc->SetTextColor(RGB(255, 255, 128));
			ap_dc->TextOut(ap_rect->left + 5, ap_rect->top + 3, p->p_name, p->name_len);
		}
		else {
			ap_dc->SetTextColor(RGB(128, 200, 200));
			ap_dc->TextOut(ap_rect->left + 5, ap_rect->top + 3, p->p_name, p->name_len);
			CString str;
			str.Format(L"%d", p->l_size);
			ap_rect->right -= 5;
			ap_dc->DrawText(str, ap_rect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
		}
		
	}
};

// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//CListBox m_left_list;
	//CListBox m_right_list;
	TW_FileListBox m_left_list;
	TW_FileListBox m_right_list;
	void DirToList(CListBox* ap_list_box, CString a_path);
	afx_msg void OnLbnDblclkLeftList();
	afx_msg void OnLbnDblclkRightList();
	void ChangeDir(CListBox * ap_list_box, int a_path_ctrl_id);
	afx_msg void OnBnClickedRCreateDirBtn();
	afx_msg void OnLbnSelchangeLeftList();
	afx_msg void OnBnClickedLToRCopyBtn();
	afx_msg void OnBnClickedOpenDirBtn();
	afx_msg void OnBnClickedRDleBtn();
	void ResetFII(CListBox* ap_list_box);
	afx_msg void OnDestroy();
};
