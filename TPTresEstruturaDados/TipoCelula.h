#pragma once
#include "TipoItem.h"
class TipoCelula :
	public TipoItem
{
	public:
		TipoCelula();
	private:
		TipoCelula* prox;

		friend class Fila;
};