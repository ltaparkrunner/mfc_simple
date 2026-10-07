
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Создание или уничтожение CmfcsimpleView

CmfcsimpleView::CmfcsimpleView() noexcept : m_bDrawing(false)
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

void CmfcsimpleView::OnDraw(CDC* pDC)
{
	CmfcsimpleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных

	// Настраиваем перо (черное, толщиной 2 пикселя)
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);

	// Проходим циклом по всем линиям в документе
	for (INT_PTR i = 0; i < pDoc->m_lines.GetCount(); ++i)
	{
		const SLine& line = pDoc->m_lines[i];
		if (line.m_points.GetCount() < 2) continue;

		// Перемещаем "перо" в стартовую точку линии
		pDC->MoveTo(line.m_points[0]);

		// Рисуем отрезки между всеми последующими точками линии
		for (INT_PTR j = 1; j < line.m_points.GetCount(); ++j)
		{
			pDC->LineTo(line.m_points[j]);
		}
	}

	pDC->SelectObject(pOldPen); // Возвращаем старое перо системе
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

void CmfcsimpleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	m_bDrawing = true;
	SetCapture();

	CmfcsimpleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Добавляем пустую структуру в массив документов
	INT_PTR newIdx = pDoc->m_lines.Add(SLine());

	// Получаем прямую ссылку на созданную линию и добавляем точку
	pDoc->m_lines[newIdx].m_points.Add(point);

	CView::OnLButtonDown(nFlags, point);
}

void CmfcsimpleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	if (m_bDrawing)
	{
		m_bDrawing = false;
		ReleaseCapture(); // Освобождаем мышь

		CmfcsimpleDoc* pDoc = GetDocument();
		if (pDoc) {
			pDoc->SetModifiedFlag(); // Помечаем, что документ изменен (для автосохранения)
			pDoc->UpdateAllViews(NULL); // Приказываем окну перерисоваться начисто
		}
	}

	CView::OnLButtonUp(nFlags, point);
}

void CmfcsimpleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	if (m_bDrawing)
	{
		CmfcsimpleDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);

		// Добавляем текущую координату мыши в последнюю линию
		INT_PTR lastIdx = pDoc->m_lines.GetUpperBound();
		pDoc->m_lines[lastIdx].m_points.Add(point);

		// Быстрая оптимизация: рисуем прямо сейчас поверх экрана, чтобы не было задержек
		CClientDC dc(this);
		INT_PTR ptIdx = pDoc->m_lines[lastIdx].m_points.GetUpperBound();
		CPoint ptFrom = pDoc->m_lines[lastIdx].m_points[ptIdx - 1];

		dc.MoveTo(ptFrom);
		dc.LineTo(point);
	}

	CView::OnMouseMove(nFlags, point);
}
