#include "TipoCelula.h"
#include <cstddef>

/// <summary>
/// Construtor sem valor inicial.
/// </summary>
TipoCelula::TipoCelula() {
	this->SetDados("-1");
	prox = NULL;
}
