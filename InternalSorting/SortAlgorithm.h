/*
*
*	数据结构第三次实验课
*	各种排序算法的实现
*	11.9 张冠杰
*
*/

#pragma once
#define THRESHOLD 10

template <typename T>
auto Max(T& a, T& b)
{
	return a < b ? b : a;
}

template <typename T>
auto Min(T& a, T& b)
{
	return a < b ? a : b;
}

template <typename T>
inline void swap(T* data, int s, int e)
{
	data[e] ^= data[s] ^= data[e] ^= data[s];
}

template <typename T>
struct DefaultComp
{
	static bool prior(const T& a, const T& b)
	{
		return a <= b;
	}

	static void swap(T& a, T& b)
	{
		a ^= b ^= a ^= b;
	}
};

template <typename T, typename Comp = DefaultComp<T> >
void insertionSort(T* data, int s, int e)
{
	for (int i = s; i < e; ++i)
		for (int j = i; j > s && !Comp::prior(data[j - 1], data[j]); --j)
				swap<T>(data, j - 1, j);
}

template <typename T, typename Comp = DefaultComp<T> >
void selectionSort(T* data, int s, int e)
{
	int mark;
	for (int i = s; i < e; ++i)
	{
		mark = i;
		for (int j = i; j < e; ++j)
		{
			if (!Comp::prior(data[mark], data[j]))
				mark = j;
		}
		if (mark != i)
			swap<T>(data, mark, i);
	}
}

template <typename T, typename Comp = DefaultComp<T> >
void bubbleSort(T* data, int s, int e)
{
	for (int i = e - 1; i >= s; --i)
		for (int j = i; j < e - 1; ++j)
			if (!Comp::prior(data[j], data[j + 1]))
				swap<T>(data, j, j + 1);
}

template <typename T, typename Comp = DefaultComp<T> >
void insertionSortForShell(T* data, int n, int incr)
{
	for (int i = incr; i < n; i += incr)
	{
		for (int j = i; j >= incr && Comp::prior(data[j], data[j-incr]); j-=incr)
			swap<T>(data, j - incr, j);
	}
}

template <typename T, typename Comp = DefaultComp<T> >
void shellSort(T* data, int n)
{
	int incr;
	for (incr = 1; incr <= n; incr = incr * 3 + 1);
	for (int i = incr / 3; i > 2; i /= 3)
		for (int j = 0; j < i; ++j)
			insertionSortForShell<T, Comp>(&data[j], n - j, i);
	insertionSortForShell<T, Comp>(data, n, 1);
}

template <typename T, typename Comp = DefaultComp<T> >
void mergeSortWithoutOptimize(T* data, T* t, int s, int e)
{
	if (e - s < 2)
	{
		return;
	}
	int m = s + (e - s) / 2;
	mergeSortWithoutOptimize(data, t, s, m);
	mergeSortWithoutOptimize(data, t, m, e);

	int p1 = s, p2 = m, pt = s;
	while (p1 < m && p2 < e)
	{
		if (Comp::prior(data[p1], data[p2]))
			t[pt++] = data[p1++];
		else
			t[pt++] = data[p2++];
	}
	while (p1 < m)
		t[pt++] = data[p1++];
	while (p2 < e)
		t[pt++] = data[p2++];
	for (int i = s; i < e; ++i)
		data[i] = t[i];
}

template <typename T, typename Comp = DefaultComp<T> >
void mergeSort(T* data, T* t, int s, int e)
{
	if (e - s < THRESHOLD)
	{
		insertionSort<T, Comp>(data, s, e);
		return;
	}
	int m = s + (e - s) / 2;
	mergeSort(data, t, s, m);
	mergeSort(data, t, m, e);

	int p1 = s, p2 = m, pt = s;
	while (p1 < m && p2 < e)
	{
		if (Comp::prior(data[p1], data[p2]))
			t[pt++] = data[p1++];
		else
			t[pt++] = data[p2++];
	}
	while (p1 < m)
		t[pt++] = data[p1++];
	while (p2 < e)
		t[pt++] = data[p2++];
	for (int i = s; i < e; ++i)
		data[i] = t[i];
}

template <typename T, typename Comp = DefaultComp<T> >
inline int partitionRand(T* data, int s, int e)
{
	swap<T>(data, s, s + rand() % (e - s));
	T pivot = data[s];
	int mi = s;
	for (int k = s + 1; k < e; k++) //自左向右扫描
		if (Comp::prior(data[k], pivot)) //若当前元素data[k]小于pivot，则
			swap<T>(data, ++mi, k); //将data[k]交换至原mi之后，使L子序列向右扩展
	swap<T>(data, s, mi); //候选轴点归位
	return mi; //返回轴点的秩
}

template <typename T, typename Comp = DefaultComp<T> >
void quickSortWithoutOptimize(T* data, int s, int e)
{
	if (e - s < 2)
		return;
	int k = partitionRand<T, Comp>(data, s, e);
	quickSortWithoutOptimize(data, s, k);
	quickSortWithoutOptimize(data, k + 1, e);
}

template <typename T, typename Comp = DefaultComp<T> >
void quickSort(T* data, int s, int e)
{
	if (e - s < THRESHOLD)
	{
		insertionSort<T, Comp>(data, s, e);
		return;
	}
	int k = partitionRand<T, Comp>(data, s, e);
	quickSort(data, s, k);
	quickSort(data, k + 1, e);
}

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
	inline int lighter(int i, int j) { return !Comp::prior(_heap[i], _heap[j]) ? i : j; }

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
			if (!Comp::prior(_heap[j], _heap[i]))	//如果i,j顺序正确，上滤完成
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

template <typename T, typename Comp = DefaultComp<T> >
void heapSort(T* data, int n)
{
	int t = n - 1;
	heap<T, Comp> H(data, n, n+10);
	for (int i = 0; i < n; ++i)
	{
		data[t--] = H.remove();
	}
}

template <typename T>
void radixSort(T A[], T B[], int n, int k, int r, int cnt[])
{
	int j;

	for (int i = 0, rtoi = 1; i < k; i++, rtoi *= r)
	{
		for (j = 0; j < r; j++)
			cnt[j] = 0;

		for (j = 0; j < n; j++)
			cnt[int(A[j] / rtoi) % r]++;

		for (j = 1; j < r; j++)
			cnt[j] = cnt[j - 1] + cnt[j];

		for (j = n - 1; j >= 0; j--)
			B[--cnt[int(A[j] / rtoi) % r]] = A[j];

		for (j = 0; j < n; j++)
			A[j] = B[j];
	}
}

