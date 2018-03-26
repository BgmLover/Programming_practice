#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
void Permutation(char *Pstr)
{
	if (Pstr == nullptr)
		return;
	Permutation(Pstr, Pstr);

}
void Permutation(char* pStr, char*pBegin)
{
	if (pBegin == nullptr)
		printf("%s", pStr);
	else
	{
		for (char* pCh = pBegin; pCh != '\0'; ++pCh)
		{
			swap(*pCh, *pBegin);
			Permutation(pStr, pBegin + 1);
			swap(*pCh, *pBegin);
		}
	}
}