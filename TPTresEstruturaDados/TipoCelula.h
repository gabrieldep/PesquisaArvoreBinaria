#pragma once
#include "TipoItem.h"
class TipoCelula :
	public TipoItem
{
public:
	TipoCelula();
	TipoCelula(TipoItem item);
private:
	TipoItem item;
	TipoCelula* prox;

	friend class Fila;
};