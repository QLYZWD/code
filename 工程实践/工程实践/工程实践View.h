
// 工程实践View.h: C工程实践View 类的接口
//

#pragma once


class C工程实践View : public CView
{
protected: // 仅从序列化创建
	C工程实践View() noexcept;
	DECLARE_DYNCREATE(C工程实践View)

// 特性
public:
	C工程实践Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C工程实践View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 工程实践View.cpp 中的调试版本
inline C工程实践Doc* C工程实践View::GetDocument() const
   { return reinterpret_cast<C工程实践Doc*>(m_pDocument); }
#endif

