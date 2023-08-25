#include "arqTexto.h"

namespace view
{

arqTexto::arqTexto():arquivo()
{
    //ctor
}

void arqTexto::lerArquivo()
{
    string line;
    string token;
    vector<string> base;
    vector<string> valores;
    int inicio, fim;
    ifstream myfile (getNome());
    size_t pos = 0;
    if (myfile.is_open()){

        //Inicialmente deve ser lido o cabeçalho com as informações de base.
        for (int i = 1; i<=21; i++){
            getline (myfile,line);
            inicio = 0;//The start of each word in the string
            for(int j = 0; j < 1; j++ )//looking for the second one (start counting from 0)
                inicio = line.find_first_of(sep1, inicio + 1 );
            fim = line.find_first_of( ',', inicio + 1 ); //Getting where our word ends:
            token = line.substr( inicio + 1, line.length() - fim - 1 );//Getting the desired word and printing:

            token.erase(0, token.find_first_not_of(" \t\n\r\f\v"));
            token.erase(token.find_last_not_of(" \t\n\r\f\v") + 1);

            base.push_back(token);
        }

        //Seções de cabeçalho.
        getline (myfile,line);
        getline (myfile,line);

        //Concluída a leitura do cabeçalho, deve ser lido todos os valores do arquivo.
        while (getline (myfile,line)){
            while ((pos = line.find(sep2)) != std::string::npos) {
                token = line.substr(0, pos);

                token.erase(0, token.find_first_not_of(" \t\n\r\f\v"));
                token.erase(token.find_last_not_of(" \t\n\r\f\v") + 1);

                valores.push_back(token);
                line.erase(0, pos + sep2.length());
            }
        }
        myfile.close();

        //Carregamentos dos valores...
        getDados()->setValorBem(base[0]);
        getDados()->setEntrada(base[1]);
        getDados()->setAporteFgts(base[2]);
        getDados()->setFonte(base[3]);
        getDados()->setValorCapExt(base[4]);
        getDados()->setTaxaJuros(base[5]);
        getDados()->setDistJuros(base[6]);
        getDados()->setDistJurosP1(base[7]);
        getDados()->setDistJurosP2(base[8]);
        getDados()->setDistJurosP3(base[9]);
        getDados()->setSistAmort(base[10]);
        getDados()->setPrazo(base[11]);
        getDados()->setTaxaServicos(base[12]);
        getDados()->setCustoContratacao(base[13]);
        getDados()->setCalcularAvef(base[14]);
        getDados()->setNomeIndEcon(base[15]);
        getDados()->setTaxaIndEcon(base[16]);
        getDados()->setTaxaOport(base[17]);
        getDados()->setCustoEvitado(base[18]);
        getDados()->setPeriodo(base[19]);
        getDados()->setAmostras(base[20]);

        //Carga dos dados do elemento de valores.
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

        for (int i = 0; i<valores.size(); i++){
            vDescricao.push_back(valores[i]);

            vValorU.push_back(valores[i+1]);
            vDistVU.push_back(valores[i+2]);
            vDistVUP1.push_back(valores[i+3]);
            vDistVUP2.push_back(valores[i+4]);
            vDistVUP3.push_back(valores[i+5]);

            vValorQ.push_back(valores[i+6]);
            vDistQ.push_back(valores[i+7]);
            vDistQP1.push_back(valores[i+8]);
            vDistQP2.push_back(valores[i+9]);
            vDistQP3.push_back(valores[i+10]);

            i +=10;
        }

        //Carregamentos dos valores...
        getDados()->setVDescricao(vDescricao);
        getDados()->setVValorU(vValorU);
        getDados()->setVDistVU(vDistVU);
        getDados()->setVDistVUP1(vDistVUP1);
        getDados()->setVDistVUP2(vDistVUP2);
        getDados()->setVDistVUP3(vDistVUP3);
        getDados()->setVValorQ(vValorQ);
        getDados()->setVDistQ(vDistQ);
        getDados()->setVDistQP1(vDistQP1);
        getDados()->setVDistQP2(vDistQP2);
        getDados()->setVDistQP3(vDistQP3);

    } else {
        getDados()->addMsg("Falha ao ler arquivo.");
        getDados()->setErro(true);
    }
}

void arqTexto::escreverArquivo()
{
    ofstream myfile;
    myfile.open (getNome()+ext);
    if (myfile.is_open()){
        //Escrevendo cabeçalho.
        myfile << "Valor do bem" << sep1 << getDados()->getValorBem() << "\n";
        myfile << "Entrada" << sep1 << getDados()->getEntrada() << "\n";
        myfile << "Aporte FGTS" << sep1 << getDados()->getAporteFgts() << "\n";
        myfile << "Fonte cap. ext." << sep1 << getDados()->getFonte() << "\n";
        myfile << "Valor cap. ext." << sep1 << getDados()->getValorCapExt() << "\n";
        myfile << "Taxa de juros cap. ext." << sep1 << getDados()->getTaxaJuros() << "\n";
        myfile << "Dist. de prob. taxa de juros cap. ext." << sep1 << getDados()->getDistJuros() << "\n";
        myfile << "Dist. de prob. taxa de juros cap. ext. P1" << sep1 << getDados()->getDistJurosP1() << "\n";
        myfile << "Dist. de prob. taxa de juros cap. ext. P2" << sep1 << getDados()->getDistJurosP2() << "\n";
        myfile << "Dist. de prob. taxa de juros cap. ext. P3" << sep1 << getDados()->getDistJurosP3() << "\n";
        myfile << "Sistema de amortização cap. ext." << sep1 << getDados()->getSistAmort() << "\n";
        myfile << "Prazo cap. ext." << sep1 << getDados()->getPrazo() << "\n";
        myfile << "Taxa de serviços cap. ext." << sep1 << getDados()->getTaxaServicos() << "\n";
        myfile << "Custo contratação cap. ext." << sep1 << getDados()->getCustoContratacao() << "\n";
        myfile << "Calcular Aval. Econ.-Fin." << sep1 << getDados()->isCalcularAvef() << "\n";
        myfile << "Nome índice econ." << sep1 << getDados()->getNomeIndEcon() << "\n";
        myfile << "Taxa índice econ." << sep1 << getDados()->getTaxaIndEcon() << "\n";
        myfile << "Taxa oportunidade" << sep1 << getDados()->getTaxaOport() << "\n";
        myfile << "Custo evitado mensal" << sep1 << getDados()->getCustoEvitado() << "\n";
        myfile << "Periodo de análise" << sep1 << getDados()->getPeriodo() << "\n";
        myfile << "Qntd. amostras" << sep1 << getDados()->getAmostras()<< "\n";

        //Escrevendo lista de valores.
        myfile << "Valores" << sep2 << "\n";
        myfile << "Descrição" << sep2 <<  "valor unitário" << sep2 <<  "dist. vu" << sep2 <<  "dvu p1" << sep2 <<  "dvu p2" << sep2 <<  "dvu p3" << sep2 <<  "qntd" << sep2 <<  "dist. q" << sep2 <<  "dq p1" << sep2 <<  "dq p2" << sep2 <<  "dq p3" << sep2 << "\n";
        for (int i = 0; i < getDados()->getVDescricao().size(); i++){
            myfile << getDados()->getVDescricao()[i] << sep2 << getDados()->getVValorU()[i] << sep2 << getDados()->getVDistVU()[i] << sep2 << getDados()->getVDistVUP1()[i] << sep2 << getDados()->getVDistVUP2()[i] << sep2 << getDados()->getVDistVUP3()[i] << sep2 << getDados()->getVValorQ()[i] << sep2<<  getDados()->getVDistQ()[i] << sep2 << getDados()->getVDistQP1()[i] << sep2 << getDados()->getVDistQP2()[i] << sep2 << getDados()->getVDistQP3()[i] << sep2 <<"\n";
        }

        //Fechando o arquivo.
        myfile.close();

    }else{
        getDados()->addMsg("Falha ao escrever no arquivo.");
        getDados()->setErro(true);
    }
}
}  // namespace view
