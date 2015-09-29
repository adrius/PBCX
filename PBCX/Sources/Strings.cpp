#include "stdafx.h"
#include "PBCX.h"
#include <string>

PBCX_API wchar_t* WINAPI pbcxReplaceAll(const wchar_t* pstrSource, const wchar_t* pstrFind, const wchar_t* pstrReplacement)
{
	size_t nFindLength = wcslen(pstrFind);
	size_t nReplacements = 0;
	const wchar_t* pstrWalker = pstrSource;
	while (pstrWalker != NULL)
	{
		pstrWalker = wcsstr(pstrWalker, pstrFind);
		if (pstrWalker != NULL)
		{
			nReplacements++;
			pstrWalker += nFindLength;
		}
	}

	size_t nSourceLength = wcslen(pstrSource) + 1;

	if (nReplacements == 0)
	{
		wchar_t* pstrReturn = new wchar_t[nSourceLength];
		wcscpy(pstrReturn, pstrSource);
		return pstrReturn;
	}

	size_t nReplacementLength = wcslen(pstrReplacement);
	size_t nNewLength = nSourceLength + nReplacements * (nReplacementLength - nFindLength);
	wchar_t* pstrReturn = new wchar_t[nNewLength];
	wchar_t* pstrDestination = pstrReturn;

	pstrWalker = pstrSource;
	const wchar_t* pstrSourceStart = pstrSource;
	while (pstrWalker != NULL)
	{
		pstrWalker = wcsstr(pstrWalker, pstrFind);
		if (pstrWalker != NULL)
		{
			wmemcpy(pstrDestination, pstrSourceStart, pstrWalker - pstrSourceStart);
			pstrDestination += (pstrWalker - pstrSourceStart);

			pstrWalker += nFindLength;
			pstrSourceStart = pstrWalker;

			wmemcpy(pstrDestination, pstrReplacement, nReplacementLength);
			pstrDestination += nReplacementLength;
		}
		else
		{
			wmemcpy(pstrDestination, pstrSourceStart, nNewLength - (pstrDestination - pstrReturn));
		}
	}

	return pstrReturn;
}