#include "../../include/view/view.h"

using namespace std;

namespace view
{

view::view()
{
    clean();
}

//Testa se uma valor inserido é um número decimal válido.
bool view::testarDouble(string  ss)
{
    string ds1 = "0";
    string ds2 = "0.000000";

    double dd = 0;
    double sd = atof(ss.c_str());
    if (((((ds1==ss)||ds2==ss))&&(dd==sd))||((sd>0)||(sd<0))){
        return true;
    }else{
        setErro(true);
        return false;
    }
}
bool view::testarInt(string ss)
{
    string is = "0";
    int ii = 0;
    int si = atoi(ss.c_str());
    if (((is==ss)&&(ii==si))||((si>0)||(si<0))){
        return true;
    }else{
        setErro(true);
        return false;
    }
}

//Gerencia o campo de mensagem da classe. Permite adicionar nova mensagem, limpar todas as mensagens e consultar mensagens gravadas.
void view::addMsg (string m)
{
    msg += " - " + m + "\n";
}
void view::cleanMsg(){
    msg = "";
    setErro(false);
}

void view::clean(){

    cleanMsg();

    valorBem = 0;
    entrada = 0;
    aporteFgts = 0;
    fonte = "";
    valorCapExt = 0;
    taxaJuros = 0;
    distJuros = "";
    distJurosP1 = 0;
    distJurosP2 = 0;
    distJurosP3 = 0;
    sistAmort = "";
    prazo = 0;
    taxaServicos = 0;
    custoContratacao = 0;
    calcularAvef = false;
    nomeIndEcon = "";
    taxaIndEcon = 0;
    taxaOport = 0;
    custoEvitado = 0;
    amostras = 0;
    valorMaisProvMin = 0;
    valorMaisProvMax = 0;
    importEnd = "";
    exportFormat = "";
    tir = 0;
    paybackSimples = 0;
    paybackDescontado = 0;
    vpl = 0;
    razaoCB = 0;
	vDescricao.clear();
	vValorU.clear();
	vDistVU.clear();
	vDistVUP1.clear();
	vDistVUP2.clear();
	vDistVUP3.clear();
    vValorQ.clear();
	vDistQ.clear();
	vDistQP1.clear();
	vDistQP2.clear();
	vDistQP3.clear();
}

string view::getMsg()
{
	return msg;
}
void view::setErro (bool e){
    erro = e;
}
bool view::isErro (){
    return erro;
}

//Gerencia get/set campo valor do bem.
void view::setValorBem(double vb)
{
    valorBem = vb;
}
void view::setValorBem(string vs)
{
    if (testarDouble(vs)){
        setValorBem(atof(vs.c_str()));
    }else{
        addMsg("O campo 'valor do bem' não é um número válido ou está vazio.");
    }
}
double view::getValorBem()
{
	return valorBem;
}

//Gerencia get/set campo entrada.
void view::setEntrada(double e)
{
    entrada = e;
}
void view::setEntrada(string vs)
{
    if (testarDouble(vs)){
        setEntrada(atof(vs.c_str()));
    }else{
        addMsg("O campo 'entrada' não é um número válido ou está vazio.");
    }
}
double view::getEntrada()
{
	return entrada;
}

//Gerencia get/set campo aporte FGTS.
void view::setAporteFgts(double a)
{
    aporteFgts = a;
}
void view::setAporteFgts(string vs)
{
    if (testarDouble(vs)){
        setAporteFgts(atof(vs.c_str()));
    }else{
        addMsg("O campo 'aporte FGTS' não é um número válido ou está vazio.");
    }
}
double view::getAporteFgts()
{
	return aporteFgts;
}

//Gerencia o campo nome da fonte de capital externo. Este campo é hard-coded no combo box da UI. Elementos possíveis: financiamento, hipoteca e empréstimo.
//Não existe validação de formatos diferentes deste campo uma vez que o mesmo é hard-coded. É testado apenas se o campo está vazio.
void view::setFonte(string f)
{
    if (f!=""){
        fonte = f;
    }else{
        addMsg("O campo 'fonte capital externo' não foi preenchido.");
        setErro(true);
    }
}
string view::getFonte()
{
	return view::fonte;
}

//Gerencia o campo de valor aportado com o capital externo.
void view::setValorCapExt(double v)
{
    valorCapExt = v;
}
void view::setValorCapExt(string vs)
{
    if (testarDouble(vs)){
        setValorCapExt(atof(vs.c_str()));
    }else{
        addMsg("O campo 'valor aportado' não é um número válido ou está vazio.");
    }
}
double view::getValorCapExt()
{
	return valorCapExt;
}

//Gerencia o campo de taxa de juros do capital externo.
void view::setTaxaJuros(double t)
{
    taxaJuros = t;
}
void view::setTaxaJuros(string vs)
{
    if (testarDouble(vs)){
        setTaxaJuros(atof(vs.c_str()));
    }else{
        addMsg("O campo 'taxa de juros' não é um número válido ou está vazio.");
    }
}
double view::getTaxaJuros()
{
	return taxaJuros;
}
//Gerencia o campo de distribuição de probabilidade da taxa de juros. Este campo é hard-coded no combo box da UI. Elementos possíveis: Normal, Uniforme e não aplicável..
//Não existe validação de formatos diferentes deste campo uma vez que o mesmo é hard-coded. É testado apenas se o campo está vazio.
void view::setDistJuros(string f)
{
    if (f!=""){
        distJuros = f;
    }else{
        addMsg("O campo 'distribuição juros capital externo' não foi preenchido.");
        setErro(true);
    }
}
string view::getDistJuros()
{
	return distJuros;
}

//Gerencia os campos de parâmetros da distribuição de probabilidades dos juros do capital externo.
void view::setDistJurosP1(double v)
{
    distJurosP1 = v;
}
void view::setDistJurosP1(string vs)
{
    if (testarDouble(vs)){
        setDistJurosP1(atof(vs.c_str()));
    }else{
        addMsg("O campo 'parâmetro 1' da taxa de juros do capital externo não é um número válido ou está vazio.");
    }
}
double view::getDistJurosP1()
{
	return distJurosP1;
}
void view::setDistJurosP2(double v)
{
    distJurosP2 = v;
}
void view::setDistJurosP2(string vs)
{
    if (testarDouble(vs)){
        setDistJurosP2(atof(vs.c_str()));
    }else{
        addMsg("O campo 'parâmetro 2' da taxa de juros do capital externo não é um número válido ou está vazio.");
    }
}
double view::getDistJurosP2()
{
	return distJurosP2;
}
void view::setDistJurosP3(double v)
{
    distJurosP3 = v;
}
void view::setDistJurosP3(string vs)
{
    if (testarDouble(vs)){
        setDistJurosP3(atof(vs.c_str()));
    }else{
        addMsg("O campo 'parâmetro 3' da taxa de juros do capital externo não é um número válido ou está vazio.");
    }
}
double view::getDistJurosP3()
{
	return distJurosP3;
}

//Gerencia o campo de sistema de amortização do capital externo.Este campo é hard-coded no combo box da UI. Elementos possíveis: Normal, Uniforme e não aplicável..
//Não existe validação de formatos diferentes deste campo uma vez que o mesmo é hard-coded. É testado apenas se o campo está vazio.
void view::setSistAmort(string f)
{
    if (f!=""){
        sistAmort = f;
    }else{
        addMsg("O campo 'sistema de amortização do capital externo' não foi preenchido.");
        setErro(true);
    }
}
string view::getSistAmort()
{
	return sistAmort;
}

//Gerencia o campo de prazo do capital externo.
void view::setPrazo(int p)
{
    prazo = p;
}
void view::setPrazo(string vs)
{
    if (testarInt(vs)){
        setPrazo(atoi(vs.c_str()));
    }else{
        addMsg("O campo 'prazo' do capital externo não é um número válido ou está vazio.");
    }
}
int view::getPrazo()
{
	return prazo;
}

//Gerencia o campo periodo de análise.
void view::setPeriodo(int p)
{
    periodo = p;
}
void view::setPeriodo(string vs)
{
    if (testarInt(vs)){
        setPeriodo(atoi(vs.c_str()));
    }else{
        addMsg("O campo periodo' da Aval. Econ. Fin. não é um número válido ou está vazio.");
    }
}
int view::getPeriodo()
{
	return periodo;
}

//Gerencia o campo de taxa de serviços do capital externo.
void view::setTaxaServicos(double v)
{
    taxaServicos = v;
}
void view::setTaxaServicos(string vs)
{
    if (testarDouble(vs)){
        setTaxaServicos(atof(vs.c_str()));
    }else{
        addMsg("O campo 'taxa de serviços' do capital externo não é um número válido ou está vazio.");
    }
}
double view::getTaxaServicos()
{
	return taxaServicos;
}

//Gerencia o campo de custo de contrataçao do capital externo.
void view::setCustoContratacao(double v)
{
    custoContratacao = v;
}
void view::setCustoContratacao(string vs)
{
    if (testarDouble(vs)){
        setCustoContratacao(atof(vs.c_str()));
    }else{
        addMsg("O campo 'custo de contratação' do capital externo não é um número válido ou está vazio.");
    }
}
double view::getCustoContratacao()
{
	return custoContratacao;
}

//Gerencia o campo que determina se a AVEF deve ser calculada ou não.
void view::setCalcularAvef(bool c)
{
    calcularAvef = c;
}
void view::setCalcularAvef(string c)
{
    bool r = false;
    if ((c=="Sim")||(c=="1")){
        r = true;
    }
    setCalcularAvef(r);
}
bool view::isCalcularAvef()
{
	return calcularAvef;
}

int view::getCalcularAvef()
{
	if (calcularAvef){
        return 1;
	}else{
        return 0;
	}
}

//Gerencia os parâmetros da AVEF.
void view::setNomeIndEcon(string n)
{
    nomeIndEcon = n;
}
string view::getNomeIndEcon()
{
	return nomeIndEcon;
}

void view::setTaxaIndEcon(double t)
{
    taxaIndEcon = t;
}
void view::setTaxaIndEcon(string vs)
{
    if (testarDouble(vs)){
        setTaxaIndEcon(atof(vs.c_str()));
    }else{
        addMsg("O campo 'taxa do índice econômico' da aval. eco.-fin. não é um número válido ou está vazio.");
    }
}
double view::getTaxaIndEcon()
{
	return taxaIndEcon;
}

void view::setTaxaOport(double t)
{
    taxaOport = t;
}
void view::setTaxaOport(string vs)
{
    if (testarDouble(vs)){
        setTaxaOport(atof(vs.c_str()));
    }else{
        addMsg("O campo 'taxa de oportunidade' da aval. eco.-fin. não é um número válido ou está vazio.");
    }
}
double view::getTaxaOport()
{
	return taxaOport;
}

void view::setCustoEvitado(double c)
{
    custoEvitado = c;
}
void view::setCustoEvitado(string vs)
{
    if (testarDouble(vs)){
        setCustoEvitado(atof(vs.c_str()));
    }else{
        addMsg("O campo 'custo evitado' da aval. eco.-fin. não é um número válido ou está vazio.");
    }
}
double view::getCustoEvitado()
{
	return custoEvitado;
}

void view::setAmostras(int a)
{
    amostras = a;
}
void view::setAmostras(string vs)
{
    if (testarDouble(vs)){
        setAmostras(atof(vs.c_str()));
    }else{
        addMsg("O campo 'amostras' da simulação de Monte Carlo não é um número válido ou está vazio.");
    }
}
int view::getAmostras()
{
	return amostras;
}

void view::setVDescricao(vector<string> v)
{
    vDescricao.clear();
    for (int i=0; i<v.size(); i++)
        vDescricao.push_back(v[i]);
}
vector<string> view::getVDescricao()
{
    return vDescricao;
}

void view::setVValorQ(vector<string> v)
{
    vValorQ.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vValorQ.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'valor de quantidade' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVValorQ(vector<double> v)
{
    vValorQ.clear();
    for (int i=0; i<v.size(); i++)
        vValorQ.push_back(v[i]);
}
vector<double> view::getVValorQ()
{
    return vValorQ;
}
void view::setVDistQ(vector<string> v)
{
    vDistQ.clear();
    for (int i=0; i<v.size(); i++){
        if (v[i]!=""){
            vDistQ.push_back(v[i]);
        }else{
            std::stringstream s;
            s << "O campo 'distribuição da quantidade' na linha " << i <<  " da tabela de valores está vazio.";
            addMsg(s.str());
            setErro(true);
        }
    }
}
vector<string> view::getVDistQ()
{
    return vDistQ;
}

void view::setVDistQP1(vector<string> v)
{
    vDistQP1.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vDistQP1.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'parâmetro 1 da distribuição de quantidade' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVDistQP1(vector<double> v)
{
    vDistQP1.clear();
    for (int i=0; i<v.size(); i++)
        vDistQP1.push_back(v[i]);
}
vector<double> view::getVDistQP1()
{
    return vDistQP1;
}

void view::setVDistQP2(vector<string> v)
{
    vDistQP2.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vDistQP2.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'parâmetro 2 da distribuição de quantidade' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVDistQP2(vector<double> v)
{
    vDistQP2.clear();
    for (int i=0; i<v.size(); i++)
        vDistQP2.push_back(v[i]);
}
vector<double> view::getVDistQP2()
{
    return vDistQP2;
}
void view::setVDistQP3(vector<string> v)
{
    vDistQP3.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vDistQP3.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'parâmetro 3 da distribuição de quantidade' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVDistQP3(vector<double> v)
{
    vDistQP2.clear();
    for (int i=0; i<v.size(); i++)
        vDistQP2.push_back(v[i]);
}
vector<double> view::getVDistQP3()
{
    return vDistQP3;
}

void view::setVValorU(vector<string> v)
{
    vValorU.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vValorU.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'valor unitário' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVValorU(vector<double> v)
{
    vValorU.clear();
    for (int i=0; i<v.size(); i++)
        vValorU.push_back(v[i]);
}
vector<double> view::getVValorU()
{
    return vValorU;
}
void view::setVDistVU(vector<string> v)
{
    vDistVU.clear();
    for (int i=0; i<v.size(); i++){
        if (v[i]!=""){
            vDistVU.push_back(v[i]);
        }else{
            std::stringstream s;
            s << "O campo 'distribuição do valor unitário' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
            setErro(true);
        }
    }
}
vector<string> view::getVDistVU()
{
    return vDistVU;
}

void view::setVDistVUP1(vector<string> v)
{
    vDistVUP1.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vDistVUP1.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'parâmetro 1 distribuição valor unitário' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVDistVUP1(vector<double> v)
{
    vDistVUP1.clear();
    for (int i=0; i<v.size(); i++)
        vDistVUP1.push_back(v[i]);
}
vector<double> view::getVDistVUP1()
{
    return vDistVUP1;
}

void view::setVDistVUP2(vector<string> v)
{
    vDistVUP2.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vDistVUP2.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'parâmetro 2 distribuição valor unitário' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVDistVUP2(vector<double> v)
{
    vDistVUP2.clear();
    for (int i=0; i<v.size(); i++)
        vDistVUP2.push_back(v[i]);
}
vector<double> view::getVDistVUP2()
{
    return vDistVUP2;
}
void view::setVDistVUP3(vector<string> v)
{
    vDistVUP3.clear();
    for (int i=0; i<v.size(); i++){
        if (testarDouble(v[i])){
            vDistVUP3.push_back(atof(v[i].c_str()));
        }else{
            std::stringstream s;
            s << "O campo 'parâmetro 3 distribuição valor unitário' na linha " << i <<  " da tabela de valores não é um número válido ou está vazio.";
            addMsg(s.str());
        }
    }
}
void view::setVDistVUP3(vector<double> v)
{
    vDistVUP3.clear();
    for (int i=0; i<v.size(); i++)
        vDistVUP3.push_back(v[i]);
}
vector<double> view::getVDistVUP3()
{
    return vDistVUP3;
}

double view::getValorMaisProvMax()
{
    return valorMaisProvMax;
}
void view::setValorMaisProvMax(double d)
{
    valorMaisProvMax = d;
}
double view::getValorMaisProvMMin()
{
    return valorMaisProvMin;
}
void view::setValorMaisProvMin(double d)
{
    valorMaisProvMin = d;
}

void view::setExportFormat(string e)
{
    exportFormat = e;
}

string view::getExportFormat()
{
	return exportFormat;
}

void view::setImportEnd(string i)
{
    importEnd = i;
}

string view::getImportEnd()
{
	return importEnd;
}

void view::setTir(double t)
{
    tir = t;
}

double view::getTir()
{
	return tir;
}

void view::setPaybackSimples(double p)
{
    paybackSimples = p;
}

double view::getPaybackSimples()
{
	return paybackSimples;
}

void view::setPaybackDescontado(double p)
{
    paybackDescontado = p;
}

double view::getPaybackDescontado()
{
	return paybackDescontado;
}

void view::setVpl(double v)
{
    vpl = v;
}

double view::getVpl()
{
	return vpl;
}

void view::setRazaoCB(double r)
{
    razaoCB = r;
}

double view::getRazaoCB()
{
	return razaoCB;
}

}  // namespace view
