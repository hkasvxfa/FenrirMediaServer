﻿#include "pch.h"
#include "MediaServerInitMFC.h"
#include "MediaServerDialog.h"
#include "CriticalDebug.h"
#include <string>
#include <ctime>
using namespace std;

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

extern void InitOpenSSL();

extern int APP_STYLE_SIZE;
extern const char* APP_STYLE_DATA;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MediaServerDialog dlgS;

void MediaServer::LoadFont()
{
	HRSRC hResBin = FindResourceW(NULL, MAKEINTRESOURCEW(IDR_UFONT1), L"UFONT");
	if (!hResBin)
	{
		(win_message().timeout(5).message_type(MSG_TYPE::TYPE_ERROR) << L"Сбой в секции ресурсов (Font)").show();
		return;
	}
	HGLOBAL mem_blockInst = LoadResource(NULL, hResBin);
	if (!mem_blockInst) {
		(win_message().timeout(5).message_type(MSG_TYPE::TYPE_ERROR) << L"Сбой в секции ресурсов (Font)").show();
		return;
	}
	void* pointerInst = LockResource(mem_blockInst);
	int Size = SizeofResource(NULL, hResBin);
	DWORD CountUU = 0;
	if(AddFontMemResourceEx(pointerInst, Size, 0, &CountUU) == NULL)
	{
		(win_message().timeout(5).message_type(MSG_TYPE::TYPE_ERROR) << L"Повреждён Шрифт").show();
		return;
	}
	FreeResource(mem_blockInst);
	XTPSkinMgr()->SetDefaultThemeFont(L"Montserrat Alternates Light");
}

void MediaServer::CreateDialogMFC()
{
	m_pMainWnd = &dlgS;
	dlgS.DoModal();
}

void MediaServer::LoadStyle()
{
	if (XTPSkinMgr()->SkinLoadMemory(APP_STYLE_DATA, APP_STYLE_SIZE) == FALSE)
	{
		(win_message().timeout(5).message_type(MSG_TYPE::TYPE_ERROR) << L"Стиль повреждён!").show();
		return;
	}
}

std::wstring ExtractAppPath()
{
	const wchar_t* FnS = L"\\/";
	TCHAR szFileName[MAX_PATH];
	GetModuleFileNameW(0, szFileName, MAX_PATH);

	std::wstring fname = szFileName;
	size_t pos = fname.find_last_of(FnS);
	return (std::wstring::npos == pos)
		? fname
		: fname.substr(0, pos);
}

BEGIN_MESSAGE_MAP(MediaServer, CWinApp)

END_MESSAGE_MAP()

MediaServer theApp;

BOOL MediaServer::InitInstance()
{
	BOOL bRet = CWinApp::InitInstance();
	srand((unsigned int)time(0));

	SetCurrentDirectoryW(ExtractAppPath().c_str());
	LoadFont();
	LoadStyle();
	INIT_CRITICAL_DEBUGGER(false);
	InitOpenSSL();
	CreateDialogMFC();

	return bRet;
}