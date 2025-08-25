// DebuggingTool_SpinSensorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DebuggingTool_SpinSensor.h"
#include "DebuggingTool_SpinSensorDlg.h"
#include "afxdialogex.h"
//#include "BitmapCtrl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
#pragma region CAboutDlg

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

#pragma endregion CAboutDlg

// CDebuggingToolSpinSensorDlg 대화 상자



CDebuggingToolSpinSensorDlg::CDebuggingToolSpinSensorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEBUGGINGTOOL_SPINSENSOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDebuggingToolSpinSensorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDebuggingToolSpinSensorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_FILE1, &CDebuggingToolSpinSensorDlg::OnBtnClickedFile1)
	ON_BN_CLICKED(IDC_BUTTON_FILE2, &CDebuggingToolSpinSensorDlg::OnBtnClickedFile2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDebuggingToolSpinSensorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDebuggingToolSpinSensorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDebuggingToolSpinSensorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDebuggingToolSpinSensorDlg::OnBnClickedButton4)

END_MESSAGE_MAP()


// CDebuggingToolSpinSensorDlg 메시지 처리기

BOOL CDebuggingToolSpinSensorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < MAX_FILES; i++)
	{
		//m_arrImages[i];
		m_strFilePath[i] = "";
		m_strFileName[i] = "";
		m_bLoad[i] = false;
	}

	CRect rect;
	GetDlgItem(IDC_STATIC_PIC)->GetClientRect(&rect);
	m_i32FrameX = rect.Width();
	m_i32FrameY = rect.Height();

	m_ImgIndex = -1;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDebuggingToolSpinSensorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDebuggingToolSpinSensorDlg::OnPaint()
{
	CPaintDC dc(this); // Device context for painting

	TRACE("OnPaint: m_ImgIndex = %d\n", m_ImgIndex);



	//단일이미지
	/*if (m_bLoad[m_ImgIndex])
	{
		int x = (m_i32FrameX * 0.5) - (m_arrWideMat[m_ImgIndex].GetWidth() * 0.5);
		int y = (m_i32FrameY * 0.5) - (m_arrWideMat[m_ImgIndex].GetHeight() * 0.5);
		m_arrWideMat[m_ImgIndex].Draw(dc.GetSafeHdc(), x, y);
	}*/

	//번갈아서
	if (m_ImgIndex >= 0)
	{
		if (m_bLoad[0] && m_bLoad[1])
		{
			int x = (m_i32FrameX * 0.5) - (m_arrImages[m_ImgIndex].GetWidth() * 0.5);
			int y = (m_i32FrameY * 0.5) - (m_arrImages[m_ImgIndex].GetHeight() * 0.5);
			m_arrImages[m_ImgIndex].Draw(dc.GetSafeHdc(), x, y);
		}
	}

	// 기본 OnPaint 처리
	CDialogEx::OnPaint();
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDebuggingToolSpinSensorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDebuggingToolSpinSensorDlg::OnDestroy()
{
	m_ImgIndex = -1;

	KillTimer(1);

	for (int i = 0; i < MAX_FILES; i++)
	{
		m_arrWideMat[i].release();
		m_arrImages[i].Destroy();
		m_strFilePath[i] = "";
		m_strFileName[i] = "";
		m_bLoad[i] = false;
	}

	CDialogEx::OnDestroy();
}

void CDebuggingToolSpinSensorDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		m_ImgIndex = 1 - m_ImgIndex; // 0 <-> 1 전환
		Invalidate(); // 다시 그리기 요청
	}
	TRACE("OnTimer called. m_ImgIndex = %d\n", m_ImgIndex);


	CDialogEx::OnTimer(nIDEvent);
}

void CDebuggingToolSpinSensorDlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}

void CDebuggingToolSpinSensorDlg::DisplayImage(int IDC_PICTURE_TARGET, cv::Mat targetMat)
{
	CClientDC dc(GetDlgItem(IDC_PICTURE_TARGET));

	CRect rect;
	GetDlgItem(IDC_PICTURE_TARGET)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, targetMat.cols, targetMat.rows, targetMat.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);

	if (&targetMat)
	{
		CWnd* pWnd_ImageTraget = GetDlgItem(IDC_PICTURE_TARGET);
		CClientDC dcImageTraget(pWnd_ImageTraget);
		RECT rcImageTraget;
		pWnd_ImageTraget->GetClientRect(&rcImageTraget);

		BITMAPINFO bitmapInfo;
		memset(&bitmapInfo, 0, sizeof(bitmapInfo));
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		bitmapInfo.bmiHeader.biWidth = targetMat.cols;
		bitmapInfo.bmiHeader.biHeight = -targetMat.rows;

		cv::Mat tempImage;
		if (targetMat.channels() == 1)
		{
			Mat temp = cv::Mat::zeros(targetMat.cols, targetMat.rows, CV_8UC1);
			targetMat.copyTo(temp);
			cv::cvtColor(temp, tempImage, cv::COLOR_GRAY2BGR);
		}
		else if (targetMat.channels() == 3)
		{
			targetMat.copyTo(tempImage);
		}

		bitmapInfo.bmiHeader.biBitCount = tempImage.depth() * tempImage.channels();

		dcImageTraget.SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(dcImageTraget.GetSafeHdc(), rcImageTraget.left, rcImageTraget.top, rcImageTraget.right, rcImageTraget.bottom, 0, 0, targetMat.cols, targetMat.rows, tempImage.data, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);

		//cvReleaseImage(&tempImage);
	}
}

void CDebuggingToolSpinSensorDlg::PasteMat(const cv::Mat& srcImg, int idx)
{
	/*CT2CA pszString(m_strFilePath[idx]);
	std::string strPath(pszString);
	cv::Mat tmpSrc = imread(string(pszString));*/
	int x = srcImg.cols;
	int y = srcImg.rows;

	for (int i = 0; i < IMG_NUM; ++i)
	{
		cv::Mat roi = m_arrWideMat[idx](cv::Rect((x* i), 0, srcImg.cols, srcImg.rows));
		srcImg.copyTo(roi);
	}
}

void CDebuggingToolSpinSensorDlg::PasteImage(const CImage& srcImg, int idx, int cnt)
{
	int srcW = srcImg.GetWidth();
	int srcH = srcImg.GetHeight();

	int startX = (cnt * srcW);

	for (int y = 0; y < srcH; ++y)
	{
		for (int x = 0; x < srcW; ++x)
		{
			COLORREF color = srcImg.GetPixel(x, y);
			m_arrWideImages[idx].SetPixel(startX + x, y, color);
		}
	}
}

void CDebuggingToolSpinSensorDlg::PasteImageAt(CImage& dstImg, const CImage& srcImg, int dstX, int dstY)
{
	int srcW = srcImg.GetWidth();
	int srcH = srcImg.GetHeight();

	for (int y = 0; y < srcH; ++y)
	{
		for (int x = 0; x < srcW; ++x)
		{
			COLORREF color = srcImg.GetPixel(x, y);
			dstImg.SetPixel(dstX + x, dstY + y, color);
		}
	}
	///////////////////////////

	int idx = 0;

	{
		CT2CA pszString(m_strFilePath[idx]);
		std::string strPath(pszString);
		cv::Mat tmpSrc = imread(string(pszString));

		int srcX = tmpSrc.cols;
		int srcY = tmpSrc.rows;
		m_arrWideMat[idx] = cv::Mat::zeros(srcY, srcX * IMG_NUM, CV_8UC1);
		for (int i = 0; i < IMG_NUM; ++i)
		{
			cv::Mat roi = m_arrWideMat[idx](cv::Rect((srcX* i), 0, srcX, srcY));
			tmpSrc.copyTo(roi);
		}
	}

	m_ImgIndex = 0;
	m_bLoad[m_ImgIndex] = true;
	Invalidate();
}

void CDebuggingToolSpinSensorDlg::MakeWideImageFromSingle(int idx)
{
	if (m_arrImages[idx].IsNull())
	{
		AfxMessageBox(_T("이미지를 먼저 로드하세요."));
		return;
	}

	const int count = 5;
	int srcW = m_arrImages[idx].GetWidth();
	int srcH = m_arrImages[idx].GetHeight();

	CImage mergedImg;
	mergedImg.Create(srcW * count, srcH, 24); // 24bit RGB 이미지

	CDC* pDestDC = CDC::FromHandle(mergedImg.GetDC());
	CDC srcDC;
	srcDC.CreateCompatibleDC(pDestDC);
	CBitmap* pOldBmp = srcDC.SelectObject(CBitmap::FromHandle(m_arrImages[idx]));

	for (int i = 0; i < count; ++i)
	{
		pDestDC->BitBlt(i * srcW, 0, srcW, srcH, &srcDC, 0, 0, SRCCOPY);
	}

	srcDC.SelectObject(pOldBmp);
	mergedImg.ReleaseDC();

	// 예: m_arrImages[2]에 결과 저장
	m_arrImages[2].Destroy(); // 기존 있던 거 지우고
	m_arrImages[2].Attach(mergedImg.Detach());

	// 시각적으로 확인
	m_ImgIndex = 2;
	Invalidate();
}

void CDebuggingToolSpinSensorDlg::LoadMat(int idx)
{
	CT2CA tmpPath(m_strFilePath[idx]);
	std::string strPath(tmpPath);
	cv::Mat tmpSrc = imread(strPath);

	m_arrWideMat[idx].release();
	m_arrWideMat[idx] = cv::Mat::zeros(tmpSrc.rows, tmpSrc.cols * IMG_NUM, CV_8UC1);
	PasteMat(tmpSrc, idx);
}

void CDebuggingToolSpinSensorDlg::LoadImages(int idx)
{
	static TCHAR BASED_CODE szFilter[] = _T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("jpg"), NULL, OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST, szFilter, this);
	if (IDOK == dlg.DoModal())
	{
		m_strFilePath[idx] = dlg.GetPathName();
		m_strFileName[idx] = dlg.GetFileName();

		SetDlgItemText((IDC_TEXT1 + idx), m_strFileName[idx]);
		m_arrImages[idx].Destroy(); // 기존 이미지 해제
		if (FAILED(m_arrImages[idx].Load(m_strFilePath[idx])))// 이미지 로드
		{
			m_bLoad[idx] = false;
			AfxMessageBox(_T("이미지 로드 실패"));
			return;
		}
		m_bLoad[idx] = true;


		// OnPaint 호출 트리거
		//Invalidate();
	}
}


void CDebuggingToolSpinSensorDlg::OnBtnClickedFile1()
{
	const int idx = 0;
	LoadImages(idx);

	const int count = 5;
	for (int i = 0; i < count; ++i)
	{
		PasteImage(m_arrImages[idx], idx, i);
	}


	//static TCHAR BASED_CODE szFilter[] = _T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All Files (*.*)|*.*||");
	//CFileDialog dlg(TRUE, _T("jpg"), NULL, OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST, szFilter, this);
	//if (IDOK == dlg.DoModal())
	//{
	//	m_strFilePath[idx] = dlg.GetPathName();
	//	m_strFileName[idx] = dlg.GetFileName();

	//	SetDlgItemText((IDC_TEXT1 + idx), m_strFileName[idx]);
	//	m_arrImages[idx].Destroy(); // 기존 이미지 해제
	//	if (FAILED(m_arrImages[idx].Load(m_strFilePath[idx])))// 이미지 로드
	//	{
	//		m_bLoad[idx] = false;
	//		AfxMessageBox(_T("이미지 로드 실패"));
	//		return;
	//	}
	//	m_bLoad[idx] = true;
	//	m_i32FrameX = m_arrImages[m_ImgIndex].GetWidth();
	//	m_i32FrameY = m_arrImages[m_ImgIndex].GetHeight();
	//}
}

void CDebuggingToolSpinSensorDlg::OnBtnClickedFile2()
{
	const int idx = 1;
	LoadImages(idx);

	/*const int count = 5;
	for (int i = 0; i < count; ++i)
	{
		PasteImage(m_arrImages[idx], idx, i);
	}*/

	PasteImage(m_arrImages[idx], idx, 2);
}


void CDebuggingToolSpinSensorDlg::OnBnClickedButton1()
{
	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON1);
	if (m_bShowAlternating)
	{
		// 현재 동작 중이면 멈춤
		KillTimer(1);
		m_bShowAlternating = false;
		pBtn->SetWindowText(_T("재생"));
		m_ImgIndex = -1;

		Invalidate();
	}
	else
	{
		// 멈춰있으면 다시 시작
		m_ImgIndex = 0;//무조건 0부터
		if ((m_strFilePath[m_ImgIndex] != "") && (m_strFilePath[m_ImgIndex] != ""))
		{
			SetTimer(1, TIMERSEC, NULL); // 1초 간격으로 번갈아 보여줌
			m_bShowAlternating = true;
			pBtn->SetWindowText(_T("멈춤"));

			Invalidate();
		}
		else
		{
			AfxMessageBox(_T("이미지를 2개 선택하세요."));
		}
	}
}


void CDebuggingToolSpinSensorDlg::OnBnClickedButton2()
{
	CRect rect;
	GetClientRect(&rect);
	int x = rect.Width();
	int y = rect.Height();
}


void CDebuggingToolSpinSensorDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDebuggingToolSpinSensorDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}