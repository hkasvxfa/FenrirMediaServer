// XTPScrollBarThemeWindowsUx.h: interface for the CXTPScrollBarCtrl class.
//
// This file is a part of the XTREME CONTROLS MFC class library.
// (c)1998-2013 Codejock Software, All Rights Reserved.
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
#if !defined(__XTPSCROLLBARTHEMEWINDOWSUX_H__)
#define __XTPSCROLLBARTHEMEWINDOWSUX_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class _XTP_EXT_CLASS CXTPScrollBarThemeWindowsUx : public CXTPScrollBarThemeWindowsClassic
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPScrollBarThemeWindowsUx object
	//-----------------------------------------------------------------------
	CXTPScrollBarThemeWindowsUx();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPScrollBarThemeWindowsUx object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPScrollBarThemeWindowsUx();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw scrollbar of the gallery
	// Parameters:
	//     pDC - Pointer to device context
	//     pScrollBar - ScrollBar to draw
	//-----------------------------------------------------------------------
	virtual void DrawScrollBar(CDC *pDC, CXTPScrollBase *pScrollBar);

	//-------------------------------------------------------------------------
	// Summary:
	//     Recalculates gallery metrics
	//-------------------------------------------------------------------------
	virtual void RefreshMetrics();

protected:
	CXTPWinThemeWrapper *m_themeScrollBar; // Scrollbar theme.
};

#endif /*__XTPSCROLLBARTHEMEWINDOWSUX_H__*/
