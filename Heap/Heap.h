/*
*
*	数据结构第二次实验课
*	Heap类
*	10.26 张冠杰
*
*/

#pragma once

// 如果i应该在j之前，则Comp::prior(i, j)返回true.
template <typename T, typename Comp> class heap
{
private:
	T* _heap;
	int _maxSize;
	int _size;			//当前最大下标

protected:
	// 父节点
	inline int parent(int i) { return (i - 1) >> 1; }

	// 左孩子
	inline int LChild(int i) { return 1 + (i << 1); }

	// 右孩子
	inline int RChild(int i) { return (i + 1) << 1; }

	// 最后一个内部节点
	inline int lastInternal() { return parent(_size - 1); }

	// 是否在堆内
	inline bool inHeap(int i) { return i >= 0 && i < _size; }

	// 是否为叶子节点
	inline bool isLeaf(int i) { return i < _size && i >= _size / 2; }

	// 父节点是否存在
	inline bool hasParent(int i) { return i > 0; }

	// 左孩子是否存在
	inline bool hasLChild(int i) { return inHeap(LChild(i)); }

	// 右孩子是否存在
	inline bool hasRChild(int i) { return inHeap(RChild(i)); }

	// 取更适合靠近堆顶者（等时前者优先）
	inline int lighter(int i, int j) { return Comp::prior(_heap[i], _heap[j]) ? i : j; }

	// 返回父子中的最大者，i作为原始的父节点，相等时父节点优先
	inline int trueParent(int i)
	{
		return hasRChild(i) ? lighter(lighter(i, LChild(i)), RChild(i)) :
			(hasLChild(i) ? lighter(i, LChild(i)) : i);
	}
	
	// 下滤
	int siftDown(int i)
	{
		int j;
		while (i != (j = trueParent(i)))	//只要i非j
		{
			Comp::swap(_heap[i], _heap[j]);	//否则交换
			i = j;
		}
		return i;
	}

	// 上滤
	int siftUp(int i)
	{
		while (hasParent(i))	//尚未到达堆顶
		{
			int j = parent(i);	//将i之父记为j
			if (Comp::prior(_heap[j], _heap[i]))	//如果i,j顺序正确，上滤完成
				break;
			Comp::swap(_heap[i], _heap[j]);	//否则交换父子位置
			i = j;
		}
		return i;	//返回上滤抵达的位置
	}

	// 批量建堆
	void buildHeap()
	{
		for (int i = lastInternal(); i >= 0; --i)
		{
			siftDown(i);
		}
	}

public:
	heap()
		:_size(0), _maxSize(100)
	{
		_heap = new T[_maxSize];
	}

	heap(T* h, int size, int max = 100)
		:_size(size), _maxSize(max)
	{
		_heap = new T[_maxSize];
		for (int i = 0; i < size; ++i)
		{
			_heap[i] = h[i];
		}
		buildHeap();
	}

	~heap()
	{
		delete[]_heap;
	}

	heap<T, Comp> & insert(T e)
	{
		if (_size + 1 > _maxSize)
			exit(-1);
		_heap[_size++] = e;
		siftUp(_size - 1);	//上滤

		return *this;
	}

	T remove()
	{
		T max = _heap[0];
		_heap[0] = _heap[--_size];
		siftDown(0);
		return max;
	}

	int size() { return _size; }
};