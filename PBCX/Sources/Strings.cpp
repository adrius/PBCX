#include "stdafx.h"
#include "PBCX.h"
#include <string>

PBCX_API wchar_t* WINAPI ReplaceAll(const wchar_t* pstrSource, const wchar_t* pstrFind, const wchar_t* pstrReplacement)
{
	size_t nFindLength = wcslen(pstrFind);
	size_t nReplacements = 0;
	const wchar_t* pstrWalker = pstrSource;

	// contagem das ocorrencias
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

	// nenhuma ocorrencia retorna o proprio source
	if (nReplacements == 0)
	{
		wchar_t* pstrReturn = new wchar_t[nSourceLength];
		wcscpy(pstrReturn, pstrSource);
		return pstrReturn;
	}

	// alocacao de memoria
	size_t nReplacementLength = wcslen(pstrReplacement);
	size_t nNewLength = nSourceLength + nReplacements * (nReplacementLength - nFindLength);
	wchar_t* pstrReturn = new wchar_t[nNewLength];
	wchar_t* pstrOutputBuffer = pstrReturn;
	const wchar_t* pstrSourceStart = pstrSource;

	// posiciona o Walker no inicio do Source
	pstrWalker = pstrSource;

	// percorre a string fazendo os replaces
	while (pstrWalker != NULL)
	{
		// posiciona o Walker na primeira ocorrencia de Find
		pstrWalker = wcsstr(pstrWalker, pstrFind);
		if (pstrWalker != NULL)
		{
			// copia para o OutputBuffer os bytes entre SourceStart atual e o proximo Find
			wmemcpy(pstrOutputBuffer, pstrSourceStart, pstrWalker - pstrSourceStart);
			// reposiciona o OutputBuffer
			pstrOutputBuffer += (pstrWalker - pstrSourceStart);
			// reposiciona o Walker
			pstrWalker += nFindLength;
			// reposiciona o SourceStart
			pstrSourceStart = pstrWalker;
			// copia para o OutpuBuffer os bytes do Replacement
			wmemcpy(pstrOutputBuffer, pstrReplacement, nReplacementLength);
			// reposiciona o OutputBuffer
			pstrOutputBuffer += nReplacementLength;
		}
		else
		{
			// finalmente copia o restante dos bytes
			wmemcpy(pstrOutputBuffer, pstrSourceStart, nNewLength - (pstrOutputBuffer - pstrReturn));
		}
	}

	return pstrReturn;
}