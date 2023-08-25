#include <iostream>
#include "include/view/viewCmd.h"
#include "include/view/viewFacade.h"
#include <random>
#include <stdlib.h>
#include <time.h>


using namespace std;

//Classe debugger dos pacotes de modelo e Controle;
int main()
{
    //simulação de leitura de dados da UI;
    view::viewCmd dados = view::viewCmd();
    view::viewFacade viewFacade = view::viewFacade();
    viewFacade.setDados(&dados);

    dados.setValorBem(350000);
    dados.setEntrada(50000);
    dados.setAporteFgts(50000);
    dados.setFonte("Hipoteca");
    dados.setValorCapExt(250000);
    dados.setTaxaJuros(5);
    dados.setDistJuros("Normal");
    dados.setDistJurosP1(5);
    dados.setDistJurosP2(2);
    dados.setDistJurosP3(0);
    dados.setSistAmort("SAC");
    dados.setPrazo(360);
    dados.setTaxaServicos(0.025);
    dados.setCustoContratacao(2000);
    dados.setAmostras(10000);
    dados.setCalcularAvef(true);
    dados.setNomeIndEcon("IPCA");
    dados.setTaxaIndEcon(6.5);
    dados.setTaxaOport(16);
    dados.setCustoEvitado(2100);
    //Carga dos dados do elemento de grid de valores.
    vector<string> vDescricao;
    vector<string> vValorQ;
	vector<string> vDistQ;
	vector<string> vDistQP1;
	vector<string> vDistQP2;
	vector<string> vDistQP3;
	vector<string> vValorU;
	vector<string> vDistVU;
	vector<string> vDistVUP1;
	vector<string> vDistVUP2;
	vector<string> vDistVUP3;
	//Valor 1
    vDescricao.push_back(string ("Reforma"));
    vValorQ.push_back(string ("1"));
    vDistQ.push_back(string ("PERT"));
    vDistQP1.push_back(string ("0"));
    vDistQP2.push_back(string ("1"));
    vDistQP3.push_back(string ("2"));
    vValorU.push_back(string ("5000"));
    vDistVU.push_back(string ("Normal"));
    vDistVUP1.push_back(string ("5000"));
    vDistVUP2.push_back(string ("1000"));
    vDistVUP3.push_back(string ("0"));
	//Valor 2
    vDescricao.push_back(string ("Móveis"));
    vValorQ.push_back(string ("5"));
    vDistQ.push_back(string ("PERT"));
    vDistQP1.push_back(string ("0"));
    vDistQP2.push_back(string ("1"));
    vDistQP3.push_back(string ("2"));
    vValorU.push_back(string ("5000"));
    vDistVU.push_back(string ("Normal"));
    vDistVUP1.push_back(string ("5000"));
    vDistVUP2.push_back(string ("1000"));
    vDistVUP3.push_back(string ("0"));
    	//Valor 3
    vDescricao.push_back(string ("Eletro"));
    vValorQ.push_back(string ("5"));
    vDistQ.push_back(string ("PERT"));
    vDistQP1.push_back(string ("0"));
    vDistQP2.push_back(string ("1"));
    vDistQP3.push_back(string ("2"));
    vValorU.push_back(string ("10000"));
    vDistVU.push_back(string ("Normal"));
    vDistVUP1.push_back(string ("10000"));
    vDistVUP2.push_back(string ("1000"));
    vDistVUP3.push_back(string ("0"));
    	//Valor 4
    vDescricao.push_back(string ("Materiais"));
    vValorQ.push_back(string ("10"));
    vDistQ.push_back(string ("PERT"));
    vDistQP1.push_back(string ("0"));
    vDistQP2.push_back(string ("1"));
    vDistQP3.push_back(string ("4"));
    vValorU.push_back(string ("4000"));
    vDistVU.push_back(string ("Normal"));
    vDistVUP1.push_back(string ("4000"));
    vDistVUP2.push_back(string ("500"));
    vDistVUP3.push_back(string ("0"));
    	//Valor 5
    vDescricao.push_back(string ("Decoraçao"));
    vValorQ.push_back(string ("10"));
    vDistQ.push_back(string ("Normal"));
    vDistQP1.push_back(string ("10"));
    vDistQP2.push_back(string ("2"));
    vDistQP3.push_back(string ("0"));
    vValorU.push_back(string ("5000"));
    vDistVU.push_back(string ("Normal"));
    vDistVUP1.push_back(string ("15000"));
    vDistVUP2.push_back(string ("2000"));
    vDistVUP3.push_back(string ("0"));

    //Carregamentos dos valores...
    dados.setVDescricao(vDescricao);
    dados.setVValorU(vValorU);
    dados.setVDistVU(vDistVU);
    dados.setVDistVUP1(vDistVUP1);
    dados.setVDistVUP2(vDistVUP2);
    dados.setVDistVUP3(vDistVUP3);
    dados.setVValorQ(vValorQ);
    dados.setVDistQ(vDistQ);
    dados.setVDistQP1(vDistQP1);
    dados.setVDistQP2(vDistQP2);
    dados.setVDistQP3(vDistQP3);

//    //Leitura dos dados e processamento.
//    viewFacade.executar();
//    if (dados.isErro()){
//        cout << dados.getMsg();
//    }else{
//        dados.exibirResSmc();
//        dados.exibirResAvef();
//    }

//    dados.setExportFormat("TXT");
//    viewFacade.exportar();
//    if (dados.isErro()){
//        cout << dados.getMsg();
//     }else{
//        cout << "Exportação concluída!";
//    }

    dados.setImportEnd("C:\\dev\\projetoFinalWxDebugger\\20190507 010235.csv");
    dados.setExportFormat("csv");
    viewFacade.importar();
    if (dados.isErro()){
        cout << dados.getMsg();
    }else{
        viewFacade.executar();
        if (dados.isErro()){
            cout << dados.getMsg();
        }else{
            dados.exibirResSmc();
            dados.exibirResAvef();
        }
    }
}
