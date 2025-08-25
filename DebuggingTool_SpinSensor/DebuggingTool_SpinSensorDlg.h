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
	void LoadMat(int idx);
	void LoadImages(int idx);
	void MakeWideImageFromSingle(int idx);
	void PasteImageAt(CImage& dstImg, const CImage& srcImg, int dstX, int dstY);
	void PasteImage(const CImage& srcImg, int idx, int cnt);
	void PasteMat(const cv::Mat& srcImg, int idx);

	void CreateBitmapInfo(int w, int h, int bpp); // Bitmap 정보를 생성하는 함수.
	void DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat);
	BITMAPINFO* m_pBitmapInfo; // Bitmap 정보를 담고 있는 구조체.

	cv::Mat m_arrWideMat[2];
	CImage m_arrWideImages[2];
	CImage m_arrImages[2];
	CString m_strFilePath[2];
	CString m_strFileName[2];
	bool m_bLoad[2];

	int m_ImgIndex = 0; // 0 또는 1
	bool m_bShowAlternating = false; // false: 멈춤, true: 실행 중

	int m_i32FrameX;
	int m_i32FrameY;
	//int m_i32ImageX;
	//int m_i32ImageY;

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
