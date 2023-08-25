#ifndef VIEW_VIEW_H
#define VIEW_VIEW_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <sstream>

using namespace std;

namespace view
{
class view
{
protected:

    string msg;
    int periodo;
    bool erro;
	double valorBem;
	double entrada;
	double aporteFgts;
	string fonte;
	double valorCapExt;
	double taxaJuros;
	string distJuros;
	double distJurosP1;
	double distJurosP2;
	double distJurosP3;
	string sistAmort;
	int prazo;
	double taxaServicos;
	double custoContratacao;
	bool calcularAvef;
    string nomeIndEcon;
	double taxaIndEcon;
	double taxaOport;
	double custoEvitado;
	int amostras;
	double valorMaisProvMin;
	double valorMaisProvMax;

	vector<string> vDescricao;
	vector<double> vValorU;
	vector<string> vDistVU;
	vector<double> vDistVUP1;
	vector<double> vDistVUP2;
	vector<double> vDistVUP3;
    vector<double> vValorQ;
	vector<string> vDistQ;
	vector<double> vDistQP1;
	vector<double> vDistQP2;
	vector<double> vDistQP3;

	string importEnd;
	string exportFormat;

	double tir;
	double paybackSimples;
	double paybackDescontado;
	double vpl;
	double razaoCB;

	bool testarDouble(string s);
	bool testarInt(string s);

public:
    view();
    virtual void lerDados()=0;
	virtual void exibirDados()=0;
	virtual void exibirResSmc()=0;
	virtual void exibirResAvef()=0;

    void addMsg (string m);
    void cleanMsg();
	string getMsg();
	void clean();

	void setErro (bool e);
	bool isErro ();

	void setValorBem(string vb);
	void setValorBem(double vb);
	double getValorBem();

	void setEntrada(double e);
    void setEntrada(string e);
	double getEntrada();

	void setAporteFgts(double aporteFgts);
    void setAporteFgts(string e);
	double getAporteFgts();

    void setFonte(string fonte);
	string getFonte();

	void setValorCapExt(double v);
	void setValorCapExt(string v);
	double getValorCapExt();

	void setTaxaJuros(double t);
    void setTaxaJuros(string t);
	double getTaxaJuros();

	void setDistJuros(string distJuros);
	string getDistJuros();

	void setDistJurosP1(double v1);
	void setDistJurosP1(string t);
	double getDistJurosP1();
	void setDistJurosP2(double v2);
	void setDistJurosP2(string t);
	double getDistJurosP2();
	void setDistJurosP3(double v3);
	void setDistJurosP3(string t);
	double getDistJurosP3();

	void setSistAmort(string sistAmort);
	string getSistAmort();

	void setPrazo(int p);
    void setPrazo(string t);
	int getPrazo();

    void setPeriodo(int p);
    void setPeriodo(string t);
	int getPeriodo();

	void setTaxaServicos(double t);
    void setTaxaServicos(string t);
	double getTaxaServicos();

	void setCustoContratacao(double c);
    void setCustoContratacao(string t);
	double getCustoContratacao();

    void setCalcularAvef(bool c);
    void setCalcularAvef(string c);
	bool isCalcularAvef();
	int getCalcularAvef();

    void setNomeIndEcon(string n);
	string getNomeIndEcon();

    void setTaxaIndEcon(double t);
    void setTaxaIndEcon(string t);
	double getTaxaIndEcon();

	void setTaxaOport(double t);
	void setTaxaOport(string t);
	double getTaxaOport();

	void setCustoEvitado(double c);
	void setCustoEvitado(string c);
	double getCustoEvitado();

	void setAmostras(int a);
	void setAmostras(string a);
	int getAmostras();

	void setVDescricao(vector<string> v);
	vector<string> getVDescricao();
	void setVValorU(vector<double> v);
	void setVValorU(vector<string> v);
	vector<double> getVValorU();
	void setVDistVU(vector<string> v);
	vector<string> getVDistVU();
	void setVDistVUP1(vector<double> v);
	void setVDistVUP1(vector<string> v);
	vector<double> getVDistVUP1();
	void setVDistVUP2(vector<double> v);
	void setVDistVUP2(vector<string> v);
	vector<double> getVDistVUP2();
	void setVDistVUP3(vector<double> v);
	void setVDistVUP3(vector<string> v);
	vector<double> getVDistVUP3();
    void setVValorQ(vector<double> v);
    void setVValorQ(vector<string> v);
	vector<double> getVValorQ();
	void setVDistQ(vector<string> v);
	vector<string> getVDistQ();
	void setVDistQP1(vector<double> v);
	void setVDistQP1(vector<string> v);
	vector<double> getVDistQP1();
	void setVDistQP2(vector<double> v);
	void setVDistQP2(vector<string> v);
	vector<double> getVDistQP2();
	void setVDistQP3(vector<double> v);
	void setVDistQP3(vector<string> v);
	vector<double> getVDistQP3();

    double getValorMaisProvMax();
    void setValorMaisProvMax(double d);
    double getValorMaisProvMMin();
    void setValorMaisProvMin(double d);

	void setImportEnd(string importEnd);
	string getImportEnd();
	void setExportFormat(string exportFormat);
	string getExportFormat();

	void setTir(double tir);
	double getTir();
	void setPaybackSimples(double paybackSimples);
	double getPaybackSimples();
	void setPaybackDescontado(double paybackDescontado);
	double getPaybackDescontado();
	void setVpl(double vpl);
	double getVpl();
	void setRazaoCB(double razaoCB);
	double getRazaoCB();
};

}  // namespace view
#endif
