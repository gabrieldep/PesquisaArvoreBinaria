#pragma once
#include "TipoNo.h"
#include "TipoItemArvore.h"
class ArvoreBinaria
{
	public:
		ArvoreBinaria();
		~ArvoreBinaria();

		void Insere(TipoItemArvore tipoItem);
		void Caminha(int tipo);
		void Imprime();
		void Limpa();

	private:
		void InsereRecursivo(TipoNo* &p, TipoItemArvore item);
		void ApagaRecursivo(TipoNo* p);
		void PorNivel();
		void PreOrdem(TipoNo* p);
		void InOrdem(TipoNo* p);
		void PosOrdem(TipoNo* p);

		TipoNo* raiz;
};

