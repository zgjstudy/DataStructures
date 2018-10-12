/*
*
*	���ݽṹ��һ��ʵ���
*	List�������
*	10.12 �Źڽ�
*
*/

#pragma once

template <typename T>
class List
{
private:
	void operator = (const List&) {}
	List(const List&) {}

public:
	virtual ~List() {}	//������

	virtual init() = 0;	//��ʼ��

	virtual void insert(const T& item) = 0;	//��curr֮�����

	virtual void append(const T& item) = 0;	//β����

	virtual T remove() = 0;	//�Ƴ�curr

	virtual void moveToStart() = 0;	//currָ����Ԫ��

	virtual void moveToEnd() = 0;	//currָ��βԪ��

	virtual void pred() = 0;	//currָ��ǰ���ڵ�

	virtual void succ() = 0;	//currָ���̽ڵ�

	virtual int length() const = 0;	//����list����

	virtual int currPos() const = 0;	//currԪ�ص����

	virtual void moveToPos(int pos) = 0;	//�ƶ���pos��Ԫ��

	virtual const T& getValue() const = 0;	//���ص�ǰԪ��
};