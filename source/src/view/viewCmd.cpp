#include "../../include/view/viewCmd.h"

namespace view
{

viewCmd::viewCmd():view()
{
}

void viewCmd::lerDados()
{
}

void viewCmd::exibirResSmc()
{
    std::stringstream s;
    s << "Valor mais provável máx.: " << valorMaisProvMax << "\n";
	s << "Valor mais provável mín.: " << valorMaisProvMin << "\n";
	cout << s.str();
}

void viewCmd::exibirResAvef()
{

    std::stringstream s;
    s << "TIR: " << tir << "\n";
    s << "VPL: " << vpl << "\n";
    s << "Payback Simples: " << paybackSimples << "\n";
    s << "Payback Descontado: " << paybackDescontado << "\n";
    s << "Razão custo-benefício: " << razaoCB << "\n";
	cout << s.str();
}

void viewCmd::exibirDados()
{
    std::stringstream s;
    s << "Erro?" << erro << "\n";
	s << "Valor do bem:" << valorBem << "\n";
	s << "Entrada:" << entrada << "\n";
	s << "Fonte cap. ext.:" <<fonte << "\n";
	s << "Valor cap. ext.:" << valorCapExt << "\n";
	s << "Taxa de juros cap. ext.:" << taxaJuros << "\n";
	s << "Dist. de prob. taxa de juros cap. ext.:" << distJuros << "\n";
	s << "Dist. de prob. taxa de juros cap. ext. P1:" << distJurosP1 << "\n";
	s << "Dist. de prob. taxa de juros cap. ext. P2:" << distJurosP2 << "\n";
	s << "Dist. de prob. taxa de juros cap. ext. P3:" << distJurosP3 << "\n";
	s << "Sistema de amortização cap. ext.:" << sistAmort << "\n";
	s << "Prazo cap. ext.:" << prazo << "\n";
	s << "Taxa de serviços cap. ext.:" << taxaServicos << "\n";
	s << "Custo contratação cap. ext.:" << custoContratacao << "\n";
	s << "Calcular Aval. Econ.-Fin.?" << calcularAvef << "\n";
	s << "Nome índice econ.:" << nomeIndEcon << "\n";
	s << "Taxa índice econ.:" << taxaIndEcon << "\n";
	s << "Taxa oportunidade:" << taxaOport << "\n";
	s << "Custo evitado mensal:" << custoEvitado << "\n";
	s << "Qntd. amostrase:" << amostras << "\n";
	s << "Valores: " << "\n";

	for (int i = 0; i < vDescricao.size(); i++){
        s << vDescricao[i] << " | " << vValorU[i] << " | " << vDistVU[i] << " | " << vDistVUP1[i] << " | " << vDistVUP2[i] << " | " << vDistVUP3[i] << " | " <<  vDistQ[i] << " | " << vDistQP1[i] << " | " << vDistQP2[i] << " | " << vDistQP3[i] << "\n";
	}

    cout << s.str();
}
}  // namespace view
