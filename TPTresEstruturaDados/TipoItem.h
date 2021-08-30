#pragma once
#include <string>
class TipoItem
{
	public:
		TipoItem();
		TipoItem(std::string dados);
		void SetDados(std::string valor);
		std::string GetDados();
		void Imprime();
	private:
		std::string dados;

		friend class Fila;
		friend class TipoCelula;
};
