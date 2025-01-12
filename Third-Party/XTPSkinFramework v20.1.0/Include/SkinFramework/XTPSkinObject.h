// XTPSkinObject.h: interface for the CXTPSkinObject class.
//
// (c)1998-2021 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(_XTPSKINOBJECT_H__)
#	define _XTPSKINOBJECT_H__
//}}AFX_CODEJOCK_PRIVATE

#	if _MSC_VER > 1000
#		pragma once
#	endif // _MSC_VER > 1000

#	include "Common/Base/Diagnostic/XTPDisableNoisyWarnings.h"

class CXTPSkinManager;
class CXTPSkinManagerClass;
class CXTPSkinManagerMetrics;
class CXTPSkinManagerSchema;

//{{AFX_CODEJOCK_PRIVATE
// Internal enumerator
enum XTPSkinDefaultProc
{
	xtpSkinDefaultHookMessage,
	xtpSkinDefaultCallWindowProc,
	xtpSkinDefaultDefWindowProc,
	xtpSkinDefaultDefMDIChildProc,
	xtpSkinDefaultDefFrameProc,
	xtpSkinDefaultDefDlgProc
};

class _XTP_EXT_CLASS CXTPSkinObjectPaintDC : public CDC
{
	// Constructors
public:
	CXTPSkinObjectPaintDC(CWnd* pWnd);
	virtual ~CXTPSkinObjectPaintDC();

	// Attributes
protected:
	HWND m_hWnd;

public:
	PAINTSTRUCT m_ps;
};
//}}AFX_CODEJOCK_PRIVATE

//===========================================================================
// Summary:
//     CXTPSkinObject is a CWnd derived class. It represents the
//     base class for all skinable windows.
//===========================================================================
class _XTP_EXT_CLASS CXTPSkinObject
	: public CWnd
	, public CXTPSynchronized
{
	DECLARE_DYNAMIC(CXTPSkinObject);

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPSkinObject object.
	//-----------------------------------------------------------------------
	CXTPSkinObject();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPSkinObject object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPSkinObject();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Gets the parent CXTPSkinManager object.
	// Returns:
	//     A pointer to the parent CXTPSkinManager object.
	//-----------------------------------------------------------------------
	CXTPSkinManager* GetSkinManager() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Gets own class name.
	// Returns:
	//     Own class name.
	// See Also:
	//     GetSkinClass
	//-----------------------------------------------------------------------
	CString GetClassName() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Gets the CXTPSkinManagerClass object associated with own class name.
	// Returns:
	//     A pointer to the CXTPSkinManagerClass object associated with own class name.
	// See Also:
	//     GetClassName
	//-----------------------------------------------------------------------
	CXTPSkinManagerClass* GetSkinClass() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Gets the skin metrics.
	// Returns:
	//     A pointer to the CXTPSkinManagerMetrics class containing the skin metrics.
	//-----------------------------------------------------------------------
	CXTPSkinManagerMetrics* GetMetrics() const;

	CXTPSkinManagerSchema* GetSchema() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the specified system color.
	// Parameters:
	//     nIndex - Index of the system color to retrieve, as described in the
	//              GetSysColor function documentation from the Windows SDK.
	// Returns:
	//     The specified system color.
	//-----------------------------------------------------------------------
	COLORREF GetColor(int nIndex) const;

	BOOL IsSkinEnabled() const;

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when the skin is changed.
	// Parameters:
	//     bPrevState - TRUE if the previous skin was installed.
	//     bNewState  - TRUE if the current skin is installed.
	//-----------------------------------------------------------------------
	virtual void OnSkinChanged(BOOL bPrevState, BOOL bNewState);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when visual metrics are changed.
	//-----------------------------------------------------------------------
	virtual void RefreshMetrics();

	// ---------------------------------------------------------------------
	// Summary:
	//     This method is called when the hook is attached.
	// Parameters:
	//     lpcs  - Pointer to a LPCREATESTRUCT structure that contains
	//             information about the CWnd object being created.
	//     bAuto - TRUE to automatically skin the window when a new
	//             window is created or when the user manually skins
	//             the existing window.
	// ---------------------------------------------------------------------
	virtual void OnHookAttached(LPCREATESTRUCT lpcs, BOOL bAuto);

	// ---------------------------------------------------------------------
	// Summary:
	//     This method is called when the hook is detached.
	// Parameters:
	//     bAuto - TRUE to automatically skin the window when a new
	//             window is created or when the user manually skins
	//             the existing window.
	// ---------------------------------------------------------------------
	virtual void OnHookDetached(BOOL bAuto);

	BOOL IsDrawingEnabled(BOOL bForceUpdateStatus = FALSE) const;

	//{{AFX_CODEJOCK_PRIVATE
public:
	UINT GetHeadMessage();

protected:
	virtual BOOL CheckDrawingEnabled();
	virtual BOOL OnHookMessage(UINT nMessage, WPARAM& wParam, LPARAM& lParam, LRESULT& lResult);
	virtual BOOL OnHookDefWindowProc(UINT nMessage, WPARAM& wParam, LPARAM& lParam,
									 LRESULT& lResult);
	void AttachHook(HWND hWnd, LPCREATESTRUCT lpcs, BOOL bAuto);
	void UnattachHook(BOOL bAuto);
	virtual void OnFinalRelease();
	virtual WNDPROC* GetSuperWndProcAddr();
	virtual BOOL IsDefWindowProcAvail(int nMessage) const;
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreHookMessage(UINT nMessage);
#	ifdef _DEBUG
	virtual void AssertValid() const
	{
	}
#	endif
	void SetWindowProc();

	void OnBeginHook(UINT nMessage, XTPSkinDefaultProc defProc, PROC defProcAddr,
					 LPVOID defProcPrevWndFunc);
	void OnEndHook();
	LRESULT DoDefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);

	static CString AFX_CDECL GetWndClassTreePath(HWND hWnd, BOOL bPathOnly = FALSE);
	//}}AFX_CODEJOCK_PRIVATE

public:
	static const UINT m_nMsgQuerySkinState;
	static const UINT m_nMsgUpdateSkinState;
	static const UINT m_nMsgSkinChanged;

protected:
	WNDPROC m_pOldWndProc;		 // Old window window handler.
	CXTPSkinManager* m_pManager; // Parent CXTPSkinManager object.
	CString m_strClassName;		 // Own class name.
	BOOL m_bActiveX;			 // TRUE if ActiveX controls.
	BOOL m_bWindowsForms;		 // TRUE if .NET controls.
	BOOL m_bCustomDraw;
	BOOL m_bUnicode;
	CRITICAL_SECTION m_csDescriptors;

	BOOL m_bSystemWindowModule;
	BOOL m_bWindowProcAttached;
	BOOL m_bSetWindowProc;

	CXTPSkinManagerSchema* m_pSchema;

private:
	struct DEFWINDOW_DESCRIPTIOR
	{
		XTPSkinDefaultProc defProc;
		PROC defProcAddr;
		LPVOID lpPrev;
		UINT nMessage;
	};
	CList<DEFWINDOW_DESCRIPTIOR, DEFWINDOW_DESCRIPTIOR&> m_arrDescriptors;
	BOOL m_bDrawingEnabled;

protected:
	friend class CXTPSkinManager;
	friend class CXTPSkinManagerApiHookBase;
	friend class CXTPSkinObjectClassInfoActiveX;
};

//{{AFX_CODEJOCK_PRIVATE
class CXTPSkinObjectClassMap;

class _XTP_EXT_CLASS CXTPSkinObjectClassInfo
	: public CXTPCmdTarget
	, public CXTPSynchronized
{
public:
	CXTPSkinObjectClassInfo(CRuntimeClass* pClass);

public:
	virtual CXTPSkinObject* CreateObject(LPCTSTR lpszClassName, LPCREATESTRUCT lpcs);

public:
	void AddClass(LPCTSTR lpszClassName);
	void Remove();

protected:
	CRuntimeClass* m_pClass;
	CXTPSkinObjectClassMap* m_pMap;

	friend class CXTPSkinObjectClassMap;
};

class _XTP_EXT_CLASS CXTPSkinObjectClassInfoActiveX : public CXTPSkinObjectClassInfo
{
public:
	CXTPSkinObjectClassInfoActiveX(CRuntimeClass* pClass, BOOL bSysModule, BOOL bSetWindowProc)
		: CXTPSkinObjectClassInfo(pClass)
	{
		m_bSysModule	 = bSysModule;
		m_bSetWindowProc = bSetWindowProc;
	}

	virtual CXTPSkinObject* CreateObject(LPCTSTR lpszClassName, LPCREATESTRUCT lpcs)
	{
		CXTPSkinObject* pObject = CXTPSkinObjectClassInfo::CreateObject(lpszClassName, lpcs);
		if (pObject)
		{
			pObject->m_bActiveX = TRUE;
			if (m_bSysModule)
				pObject->m_bSystemWindowModule = TRUE;
			if (m_bSetWindowProc)
				pObject->m_bSetWindowProc = TRUE;
		}
		return pObject;
	}
	BOOL m_bSysModule;
	BOOL m_bSetWindowProc;
};

//}}AFX_CODEJOCK_PRIVATE

//===========================================================================
// Summary:
//     CXTPSkinObjectClassMap is a standalone class that helps map windows controls
//     to skin framework classes.
// Remarks:
//     CXTPSkinManager uses this class to find what skin framework class needs
//     to apply to a new window in order to skin it properly. For example,
//     if a new window were to be created with the class name of "BUTTON",
//     then CXTPSkinObjectClassMap::Lookup would retrieve the runtime class
//     of CXTPSkinObjectButton to apply it to the new window and skin it.
// See Also:
//     CXTPSkinManager, CXTPSkinObject, CXTPSkinManager::GetClassMap
//===========================================================================
class _XTP_EXT_CLASS CXTPSkinObjectClassMap : public CXTPSynchronized
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPSkinObjectClassMap object.
	//-----------------------------------------------------------------------
	CXTPSkinObjectClassMap();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPSkinObjectClassMap object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPSkinObjectClassMap();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called by the framework to add all standard window classes.
	// Remarks:
	//     CXTPSkinManager calls this method to add standard window classes such as
	//     "BUTTON", "LISTBOX", and "SCROLLBAR".
	//-----------------------------------------------------------------------
	void AddStandardClasses();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Maps a window class name to a skin framework class.
	// Parameters:
	//     lpszClassName - Window class name.
	//     pInfo         - Pointer to the skin framework class.
	// Example:
	//     <code>pClassMap->AddClass(_T("ListBox"), new
	//     CXTPSkinObjectClassInfo(RUNTIME_CLASS(CXTPSkinObjectListBox)));</code>
	// See Also:
	//     AddSynonymClass,  AddStandardClasses
	//-----------------------------------------------------------------------
	CXTPSkinObjectClassInfo* AddClass(LPCTSTR lpszClassName, CXTPSkinObjectClassInfo* pInfo);

	//-----------------------------------------------------------------------
	// Summary:
	//     Maps a window class name to another window class name.
	// Parameters:
	//     lpszClassNameSynonym - New window class name.
	//     lpszClassName        - Standard window class name.
	// Example:
	//     <code>pClassMap->AddSynonymClass(_T("SysDateTimePick32"), _T("Edit"));</code>
	// See Also:
	//     AddClass
	//-----------------------------------------------------------------------
	void AddSynonymClass(LPCTSTR lpszClassNameSynonym, LPCTSTR lpszClassName);

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes a window class.
	// Parameters:
	//     lpszClassName - Window class name to remove.
	// See Also:
	//     AddClass
	//-----------------------------------------------------------------------
	void RemoveClass(LPCTSTR lpszClassName);

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes a skin framework class.
	// Parameters:
	//     pInfo - Pointer to the skin framework class.
	// See Also:
	//     AddClass
	//-----------------------------------------------------------------------
	void RemoveClass(CXTPSkinObjectClassInfo* pInfo);

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes all classes.
	// See Also:
	//     AddClass
	//-----------------------------------------------------------------------
	void RemoveAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     Searches for a Skin Object Class Information object by a specified name.
	// Parameters:
	//     lpszClassName - Name of the class to lookup.
	// Returns:
	//     A pointer to the CXTPSkinObjectClassInfo object if found, otherwise NULL.
	//-----------------------------------------------------------------------
	CXTPSkinObjectClassInfo* Lookup(LPCTSTR lpszClassName);

protected:
	CMapStringToPtr m_mapInfo; // General map.
};

AFX_INLINE CXTPSkinManager* CXTPSkinObject::GetSkinManager() const
{
	return m_pManager;
}
AFX_INLINE CString CXTPSkinObject::GetClassName() const
{
	return m_strClassName;
}

#	include "Common/Base/Diagnostic/XTPEnableNoisyWarnings.h"
#endif // !defined(_XTPSKINOBJECT_H__)
