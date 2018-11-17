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
		TrieNode*& pTmpNode = pNode->getChildren()[index];

		// make the new trie node if not exist
		if (!pTmpNode)
		{
			pTmpNode = new TrieNode(str[i]);
		}

		// next character in trie
		pNode = pTmpNode;

		// check the final character in string
		if (i == length - 1)
		{
			pNode->setIsLeafNode(true);
		}
	}
}


bool Trie::search(const std::string& str)
{
	if (!m_pRoot && str == "")
	{
		return false;
	}

	int nLength = str.length();
	TrieNode* pNode = m_pRoot;
	bool bIsEndOfWord = false;

	for (int i = 0; i < nLength; ++i)
	{
		int nIndex = (int)(str[i] - CHARACTER_FIRST);
		TrieNode* pTmpNode = pNode->getChildren()[nIndex];
		if (pTmpNode)
		{
			if (pTmpNode->getIsLeafNode())
			{
				bIsEndOfWord = true;
				break;
			}

			pNode = pTmpNode;
		}
		else
		{
			return false;
		}
	}

	if (!bIsEndOfWord)
	{
		return false;
	}

	return true;
}


bool Trie::startsWith(const std::string& prefix)
{
	if (!m_pRoot && prefix == "")
	{
		return false;
	}

	int nLength = prefix.length();
	TrieNode* pNode = m_pRoot;

	for (int i = 0; i < nLength; ++i)
	{
		int nIndex = (int)(prefix[i] - CHARACTER_FIRST);
		TrieNode* pTmpNode = pNode->getChildren()[nIndex];
		if (pTmpNode)
		{			
			pNode = pTmpNode;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}


bool Trie::del(const std::string& str)
{
	return false;
}