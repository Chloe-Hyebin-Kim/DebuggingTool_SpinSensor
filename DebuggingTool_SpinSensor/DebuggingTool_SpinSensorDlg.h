// DebuggingTool_SpinSensorDlg.h: 헤더 파일
//

#pragma once


// CDebuggingToolSpinSensorDlg 대화 상자
class CDebuggingToolSpinSensorDlg : public CDialogEx
{
	/*** Construction ***/
public:
	CDebuggingToolSpinSensorDlg(CWnd* pParent = nullptr);	// Standard constructor

/*** Dialog Data ***/
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEBUGGINGTOOL_SPINSENSOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


/*** Implementation ***/
protected:
	HICON m_hIcon;

	/*** Generated message map functions ***/
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:

private:
	void CreateBitmapInfo(int w, int h, int bpp); // Bitmap 정보를 생성하는 함수.
	void DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat);

	BITMAPINFO* m_pBitmapInfo; // Bitmap 정보를 담고 있는 구조체.

	CString m_strFilePath1;
	CString m_strFilePath2;
	CString m_strFileName1;
	CString m_strFileName2;

	Mat m_matImage1; // 이미지 정보를 담고 있는 객체.
	Mat m_matImage2; // 이미지 정보를 담고 있는 객체.
	CImage m_image1;
	CImage m_image2;

	CImage m_Images[2];
	int m_i32ImageIdx = 0; // 0 또는 1
	bool m_bShowAlternating = false; // false: 멈춤, true: 실행 중

	int m_i32PicFrameX;
	int m_i32PicFrameY;

protected:
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnBtnClickedFile1();
	afx_msg void OnBtnClickedFile2();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
