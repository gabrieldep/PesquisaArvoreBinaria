#pragma once
#include <string>
class TipoItemArvore
{
	public:
		TipoItemArvore();
		TipoItemArvore(std::string dados, std::string nome);
		void SetDados(std::string valor);
		void SetNome(std::string valor);
		std::string GetDados();
		std::string GetNome();
		void Imprime();
	private:
		std::string dados;
		std::string nome;

		friend class Fila;
		friend class TipoCelula;
};

