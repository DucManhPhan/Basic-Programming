// Basic-Trie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Basic-Trie.h"

#define CHARACTER_FIRST 'a'

Trie::Trie() : m_pRoot(nullptr)
{
	// nothing to do
}

void Trie::insert(const std::string& str)
{
	if (str.empty())
	{
		return;
	}

	if (!m_pRoot)
	{
		m_pRoot = new TrieNode();
	}

	TrieNode* pNode = m_pRoot;
	int length = str.size();
	for (int i = 0; i < length; ++i)
	{
		int index = int(str[i] - CHARACTER_FIRST);
		if (pNode->getChildren()[index])
		{
			pNode = pNode->getChildren()[index];
		}
		else
		{
			pNode->getChildren()[index] = new TrieNode(str[i]);
		}
	}
}


bool Trie::search(const std::string& str)
{
	return false;
}


bool Trie::startsWidth(const std::string& prefix)
{
	return false;
}


bool Trie::del(const std::string& str)
{
	return false;
}