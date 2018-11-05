/*
*
*	数据结构
*	dictionary ADT类
*	10.6
*
*/


#pragma once

template <typename key, typename E>
class Dictionary
{
private:
	void operator =(const Dictionary&) {}
	Dictionary(const Dictionary&) {}

public:
	Dictionary() {}
	virtual ~Dictionary() {}

	virtual void clear() = 0;

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	virtual void insert(const key& k, const E& e) = 0;

	// Remove and return a record.
	// k: The key of the record to be removed.
	// Return: A maching record. If multiple records match
	// "k", remove an arbitrary one. Return NULL if no record
	// with key "k" exists.
	virtual E remove(const key& k) = 0;

	// Remove and return an arbitrary record from dictionary.
	// Return: The record removed, or NULL if none exists.
	virtual E removeAny() = 0;

	// Return: A record matching "k" (NULL if none exists).
	// If multiple records match, return an arbitrary one.
	// k: The key of the record to find
	virtual E find(const key& k) const = 0;

	// Return the number of records in the dictionary.
	virtual int size() const = 0;
};