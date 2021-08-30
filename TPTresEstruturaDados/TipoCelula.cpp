#include "TipoCelula.h"
#include <cstddef>

/// <summary>
/// Construtor sem valor inicial.
/// </summary>
TipoCelula::TipoCelula() {
	this->item.SetDados("-1");
	prox = NULL;
}

TipoCelula::TipoCelula(TipoItem item)
{
	this->item = item;
	prox = NULL;
}
