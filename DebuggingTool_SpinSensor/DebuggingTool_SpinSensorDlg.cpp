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
	m_strFilePath1 = "";
	m_strFilePath2 = "";
	m_strFileName1 = "";
	m_strFileName2 = "";

	CRect rect;
	GetDlgItem(IDC_STATIC_PIC)->GetClientRect(&rect);
	m_i32PicFrameX = rect.Width();
	m_i32PicFrameY = rect.Height();

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

	if (!m_strFilePath1.IsEmpty() && m_image1.GetWidth() > 0)
	{
		int x = (m_i32PicFrameX * 0.5) - (m_image1.GetWidth() * 0.5);
		int y = (m_i32PicFrameY * 0.5) - (m_image1.GetHeight() * 0.5);
		m_image1.Draw(dc.GetSafeHdc(), x, y); //그릴 위치 변수로 지정
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
	KillTimer(1);

	m_Images[0].Destroy();
	m_Images[1].Destroy();

	/*for (int i = 0; i < MAX_FILES; i++)
	{
		m_Images[i].Destroy();
	}*/

	CDialogEx::OnDestroy();
}

void CDebuggingToolSpinSensorDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		m_i32ImageIdx = 1 - m_i32ImageIdx; // 0 <-> 1 전환
		Invalidate(); // 다시 그리기 요청
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CDebuggingToolSpinSensorDlg::OnBtnClickedFile1()
{
	static TCHAR BASED_CODE szFilter[] = _T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("jpg"), NULL, OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST, szFilter, this);
	if (IDOK == dlg.DoModal())
	{
		m_strFilePath1 = dlg.GetPathName();
		m_strFileName1 = dlg.GetFileName();
		SetDlgItemText(IDC_TEXT1, m_strFileName1);

		m_Images[0].Destroy(); // 기존 이미지 해제
		if (FAILED(m_image1.Load(m_strFilePath1)))// 이미지 로드
		{
			AfxMessageBox(_T("이미지1 로드 실패"));
			return;
		}

		// OnPaint 호출 트리거
		//Invalidate();
	}

	//HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, m_strFileName1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
	//SetBitmap(hBitmap);

	/*

	BROWSEINFO BrInfo;
	TCHAR szBuffer[512];                                      // 경로저장 버퍼

	::ZeroMemory(&BrInfo, sizeof(BROWSEINFO));
	::ZeroMemory(szBuffer, 512);

	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.lpszTitle = _T("폴더를 선택하세요.");
	BrInfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pItemIdList = ::SHBrowseForFolder(&BrInfo);
	::SHGetPathFromIDList(pItemIdList, szBuffer);				// 파일경로 읽어오기

	m_strFilePath1.Format(_T("%s"), szBuffer);
	//AfxMessageBox(m_strFilePath1);

	SetDlgItemText(IDC_EDIT1, m_strFilePath1);
	 */
}

void CDebuggingToolSpinSensorDlg::OnBtnClickedFile2()
{
	static TCHAR BASED_CODE szFilter[] = _T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("jpg"), NULL, OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST, szFilter, this);
	if (IDOK == dlg.DoModal())
	{
		m_strFilePath2 = dlg.GetPathName();
		m_strFileName2 = dlg.GetFileName();
		SetDlgItemText(IDC_TEXT2, m_strFileName2);

		m_Images[1].Destroy(); // 기존 이미지 해제
		if (FAILED(m_Images[1].Load(m_strFilePath2)))// 이미지 로드
		{
			AfxMessageBox(_T("이미지2 로드 실패"));
			return;
		}

		// OnPaint 호출 트리거
		//Invalidate();
	}

	/*  CFileDialog dlg(TRUE, _T("jpg"), NULL,
		OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST,
		_T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All Files (*.*)|*.*||"),
		this);

	const int MAX_FILES = 2;
	const int BUFFER_SIZE = MAX_FILES * (MAX_PATH + 1) + 1;
	CString fileBuffer;
	fileBuffer.GetBufferSetLength(BUFFER_SIZE);
	dlg.m_ofn.lpstrFile = fileBuffer.GetBuffer();
	dlg.m_ofn.nMaxFile = BUFFER_SIZE;

	if (dlg.DoModal() == IDOK)
	{
		POSITION pos = dlg.GetStartPosition();
		int i = 0;
		while (pos && i < 2)
		{
			CString path = dlg.GetNextPathName(pos);
			m_images[i].Destroy(); // 기존 이미지 해제
			if (FAILED(m_images[i].Load(path)))
			{
				AfxMessageBox(_T("이미지 로드 실패"));
				return;
			}
			++i;
		}

		if (i == 2)
		{
			m_loaded = true;
			SetTimer(1, 1000, NULL); // 1초 간격으로 번갈아 보여줌
			Invalidate(); // 첫 이미지 출력
		}
		else
		{
			AfxMessageBox(_T("이미지를 2개 선택하세요."));
		}
	} */
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

// 디스플레이 함수
void CDebuggingToolSpinSensorDlg::DisplayImage(int IDC_PICTURE_TARGET, cv::Mat targetMat)
{
	CClientDC dc(GetDlgItem(IDC_PICTURE_TARGET));

	CRect rect;
	GetDlgItem(IDC_PICTURE_TARGET)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, targetMat.cols, targetMat.rows, targetMat.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);

	/*IplImage* targetIplImage = new IplImage(&targetMat);
	if (targetIplImage != nullptr)
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
		bitmapInfo.bmiHeader.biWidth = targetIplImage->width;
		bitmapInfo.bmiHeader.biHeight = -targetIplImage->height;

		IplImage* tempImage = nullptr;

		if (targetIplImage->nChannels == 1)
		{
			tempImage = cvCreateImage(cvSize(targetIplImage->width, targetIplImage->height), IPL_DEPTH_8U, 3);
			cvCvtColor(targetIplImage, tempImage, CV_GRAY2BGR);
		}
		else if (targetIplImage->nChannels == 3)
		{
			tempImage = cvCloneImage(targetIplImage);
		}

		bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;

		dcImageTraget.SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(dcImageTraget.GetSafeHdc(), rcImageTraget.left, rcImageTraget.top, rcImageTraget.right, rcImageTraget.bottom, 0, 0, tempImage->width, tempImage->height, tempImage->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);

		cvReleaseImage(&tempImage);
	}*/
}


void CDebuggingToolSpinSensorDlg::OnBnClickedButton1()
{
	//CT2CA pszString(m_strFilePath1);
	//std::string strPath(pszString);
	//Mat src = imread(string(pszString));
	//DisplayImage(IDC_STATIC_PIC, src);


	if ((m_strFilePath1 != "") && (m_strFilePath2 != ""))
	{
		SetTimer(1, 1000, NULL); // 1초 간격으로 번갈아 보여줌
		Invalidate(); // 첫 이미지 출력
	}
	else
	{
		AfxMessageBox(_T("이미지를 2개 선택하세요."));
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