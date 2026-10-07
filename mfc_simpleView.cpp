
// mfc_simpleView.cpp: реализация класса CmfcsimpleView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "mfc_simple.h"
#endif

#include "mfc_simpleDoc.h"
#include "mfc_simpleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcsimpleView

IMPLEMENT_DYNCREATE(CmfcsimpleView, CView)

BEGIN_MESSAGE_MAP(CmfcsimpleView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CmfcsimpleView

CmfcsimpleView::CmfcsimpleView() noexcept
{
	// TODO: добавьте код создания

}

CmfcsimpleView::~CmfcsimpleView()
{
}

BOOL CmfcsimpleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CmfcsimpleView

void CmfcsimpleView::OnDraw(CDC* /*pDC*/)
{
	CmfcsimpleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CmfcsimpleView

BOOL CmfcsimpleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CmfcsimpleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CmfcsimpleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CmfcsimpleView

#ifdef _DEBUG
void CmfcsimpleView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcsimpleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcsimpleDoc* CmfcsimpleView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcsimpleDoc)));
	return (CmfcsimpleDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CmfcsimpleView
