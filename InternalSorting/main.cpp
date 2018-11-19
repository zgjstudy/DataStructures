//��ֹջ�������ջ��100��
#pragma comment(linker,"/STACK:102400000,102400000")

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <thread>
#include <algorithm>
#include <iomanip>
#include "SortAlgorithm.h"
#include "TIME.h"
using namespace std;

int numOfSort = 11;			//number of sort algorithms
const double limit = 50;	//��ĳ������ʱ��ﵽ���ֵ���ڽ������Ĳ�����������������
const double delta = 1.5;	//�ݴ�ֵ
const int dataSize = 100000;	//������ ʮ������
enum SORT_TYPE				//Define the sorting algorithm execution order
{	
	MERGE_SORT = 0,
	MERGE_SORT_WITHOUT_OPTIMIZE,
	RADIX_SORT,
	SORT_STL,
	QUICK_SORT,
	QUICK_SORT_WITHOUT_OPTIMIZE,
	HEAP_SORT,
	SHELL_SORT,
	INSERTION_SORT,
	BUBBLE_SORT,
	SHELECTION_SORT,
};	//��˳��Ϊ���Եõ��������ٶ�����

//��ʼ��������
void init(ofstream& fs);

//���������,�����������Сֵ
void loadRandNum(int* a, int num, int min, int max, ifstream& fs);

//���������,�������������Сֵ,�������˼���Ч��
void loadRandNumEx(int* a, int num, ifstream& fs);

//��������
void copyArray(int* a, int* b, int n);

//���Ը�������
void testhelp(int* num, int n, ofstream& fs, bool);

int main()
{
	cout << "Begin." << endl;
	ifstream ifs("randnum.txt");
	ofstream ofs("output.csv");
	if (!ifs.is_open())
	{
		cerr << "Can't find File!";
		exit(-1);
	}

	int *num100k = new int[dataSize + 5];

	cout << "Loading rand numbers...";
	
	loadRandNumEx(num100k, dataSize, ifs);
	ifs.close();
	cout << "Done!" << endl << endl;

	init(ofs);

	//����������
	for (int i = 100; i <= dataSize; i += 100)
	{
		if (numOfSort == 0)
			break;
		cout << "Sorting " << i << " numbers for " << numOfSort << " sort algorithms...";
		if(i <= 10000)	//ȷ�����������㷨���ٲ�������������ģΪ10000
			testhelp(num100k, i, ofs, 0);
		else
			testhelp(num100k, i, ofs, 1);
		cout << "Done." << endl;
	}

	cout << "Test finished." << endl;
	ofs.close();
	delete[]num100k;

	system("pause");
	return 0;
}

void testhelp(int* num, int n, ofstream& fs, bool cutable = 1)
{
	int* tnum = new int[n];
	int* ttnum = new int[n];
	Timestamp timer; //��ʱ��
	fs << n << ",";
	double time;
	//�������õ�˳����������㷨
	for (int i = 0, t = numOfSort; i < numOfSort; ++i)
	{
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT_WITHOUT_OPTIMIZE:	//δ�Ż��Ĺ鲢����
			copyArray(num, tnum, n);		//��������
			timer.update();					//ˢ�¼�ʱ��
			mergeSortWithoutOptimize(tnum, ttnum, 0, n);	//����
			time = timer.getElapsedTimeInMilliSec();	//��ʱ
			fs << time;	//��ӡʱ��
			//if (cutable && time > limit && time < limit + delta)	//����ʱ��رմ��㷨, delta������ֹ���
			//	numOfSort = 0;
			break;
		case MERGE_SORT:	//����ͬ��
			copyArray(num, tnum, n);
			timer.update();
			mergeSort(tnum, ttnum, 0, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			//if (cutable && time > limit && time < limit + delta)
			//	numOfSort = 1;
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			copyArray(num, tnum, n);
			timer.update();
			quickSortWithoutOptimize(tnum, 0, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			//if (cutable && time > limit && time < limit + delta)
			//	numOfSort = 5;
			break;
		case QUICK_SORT:
			copyArray(num, tnum, n);
			timer.update();
			quickSort(tnum, 0, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			//if (cutable && time > limit && time < limit + delta)
			//	numOfSort = 4;
			break;
		case SORT_STL:
			copyArray(num, tnum, n);
			timer.update();
			sort(tnum, tnum + n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			//if (cutable && time > limit && time < limit + delta)
			//	numOfSort = 3;
			break;
		case HEAP_SORT:
			copyArray(num, tnum, n);
			timer.update();
			heapSort(tnum, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			if (cutable && time > limit && time < limit + delta)
				numOfSort = 6;
			break;
		case RADIX_SORT:
		{
			int* cnt = new int[n];
			copyArray(num, tnum, n);
			timer.update();
			radixSort(tnum, ttnum, n, 10, 10, cnt);
			time = timer.getElapsedTimeInMilliSec();
			delete[] cnt;
			fs << time;
			//if (cutable && time > limit && time < limit + delta)
			//	numOfSort = 2;
		}
		break;
		case SHELL_SORT:
			copyArray(num, tnum, n);
			timer.update();
			shellSort(tnum, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			if (cutable && time > limit && time < limit + delta)
				numOfSort = 7;
			break;
		case INSERTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			insertionSort(tnum, 0, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			if (cutable && time > limit)
				numOfSort = 8;
			break;
		case BUBBLE_SORT:
			copyArray(num, tnum, n);
			timer.update();
			bubbleSort(tnum, 0, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			if (cutable && time > limit)
				numOfSort = 9;
			break;
		case SHELECTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			selectionSort(tnum, 0, n);
			time = timer.getElapsedTimeInMilliSec();
			fs << time;
			if (cutable && time > limit)
				numOfSort = 10;
			break;
		default:
			break;
		}
		if (i < t - 1)
			fs << ",";
	}
	fs << endl;
	delete[] tnum;
	delete[] ttnum;
}

void init(ofstream& fs)
{
	fs << "Sort algorithm time record(Millisecond):" << endl;
	fs << setw(9) << "Data size" << ",";
	for (int i = 0; i < numOfSort; ++i)
	{
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT_WITHOUT_OPTIMIZE:
			fs << "mergeSortNotOpt";
			break;
		case MERGE_SORT:
			fs << "mergeSort";
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			fs << "quickStNotOpt";
			break;
		case QUICK_SORT:
			fs << "quickSort";
			break;
		case SORT_STL:
			fs << "sort(STL)";
			break;
		case HEAP_SORT:
			fs << "heapSort";
			break;
		case RADIX_SORT:
			fs << "radixSort";
			break;
		case SHELL_SORT:
			fs << "shellSort";
			break;
		case INSERTION_SORT:
			fs << "insertionSort";
			break;
		case BUBBLE_SORT:
			fs << "bubbleSort";
			break;
		case SHELECTION_SORT:
			fs << "selectionSort";
			break;
		default:
			break;
		}
		if (i < numOfSort - 1)
			fs << ",";
	}
	fs << endl;
}

void loadRandNum(int* a, int num, int min, int max, ifstream& fs)
{
	double temp;
	for (int i = 0; i < num; ++i)
	{
		fs >> temp;
		a[i] = int(temp * INT_MAX) % (max - min) + min;
	}
}

void loadRandNumEx(int* a, int num, ifstream& fs)
{
	double temp;
	for (int i = 0; i < num; ++i)
	{
		fs >> temp;
		a[i] = temp * 100000000;
	}
}

void copyArray(int* a, int* b, int n)
{
	for (int i = 0; i < n; ++i)
	{
		b[i] = a[i];
	}
}