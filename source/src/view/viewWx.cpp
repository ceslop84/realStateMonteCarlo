#include "../../include/view/viewWx.h"

namespace view
{

viewWx::viewWx():view()
{
}

void viewWx::lerDados()
{
    //Limpa o conteúdo previamente salvo em dados.
    clean();

    //Carregamento do grupo ref. à classe transação.
    setValorBem(string(wxValorBem->GetValue()));
    setEntrada(string(wxEntrada->GetValue()));
    setAporteFgts(string(wxAporteFgts->GetValue()));

    //Carregamento do grupo ref. à classe capital externo.
    setFonte(string ((wxFonte->GetString(wxFonte->GetSelection())).mb_str()));
    setValorCapExt(string(wxValorCapExt->GetValue()));
    setTaxaJuros(string (wxTaxaJuros->GetValue()));
    setDistJuros(string ((wxDistJuros->GetString(wxDistJuros->GetSelection())).mb_str()));
    setDistJurosP1(string (wxDistJurosP1->GetValue()));
    setDistJurosP2(string (wxDistJurosP2->GetValue()));
    setDistJurosP3(string (wxDistJurosP3->GetValue()));
    setSistAmort(string ((wxSistAmort->GetString(wxSistAmort->GetSelection())).mb_str()));
    setPrazo(string (wxPrazo->GetValue()));
    setTaxaServicos(string (wxTaxaServicos->GetValue()));
    setCustoContratacao(string (wxCustoContratacao->GetValue()));

    //Carregamento do grupo ref. à classe de aval. econ.-fin.
    setCalcularAvef(string (wxCalcAVEF->GetString(wxCalcAVEF->GetSelection())));
    setNomeIndEcon(string (wxNomeIndEcon->GetValue()));
    setTaxaIndEcon(string (wxTaxaIndEcon->GetValue()));
    setTaxaOport(string (wxTaxaOport->GetValue()));
    setCustoEvitado(string (wxCustoEvitado->GetValue()));
    setPeriodo(string (wxPeriodo->GetValue()));

    //Carregamento do grupo ref. à classe simulação de monte carlo.
    setAmostras(string (wxAmostras->GetValue()));

    //Carregamento do formato de exportação.
    setExportFormat(string ((wxExportFormat->GetString(wxExportFormat->GetSelection())).mb_str()));

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
    int row;

    for (row = 0;row<50;row++){
        if ((string (wxValores->GetCellValue(row, 0)))!=""){
            vDescricao.push_back(string (wxValores->GetCellValue(row, 0)));
            vValorQ.push_back(string (wxValores->GetCellValue(row, 1)));
            vDistQ.push_back(string (wxValores->GetCellValue(row, 2)));
            vDistQP1.push_back(string (wxValores->GetCellValue(row, 3)));
            vDistQP2.push_back(string (wxValores->GetCellValue(row, 4)));
            vDistQP3.push_back(string (wxValores->GetCellValue(row, 5)));
            vValorU.push_back(string (wxValores->GetCellValue(row, 6)));
            vDistVU.push_back(string (wxValores->GetCellValue(row, 7)));
            vDistVUP1.push_back(string (wxValores->GetCellValue(row, 8)));
            vDistVUP2.push_back(string (wxValores->GetCellValue(row, 9)));
            vDistVUP3.push_back(string (wxValores->GetCellValue(row, 10)));
        }else{
            row = 50;
        }
    }

    setVDescricao(vDescricao);
    setVValorU(vValorU);
    setVDistVU(vDistVU);
    setVDistVUP1(vDistVUP1);
    setVDistVUP2(vDistVUP2);
    setVDistVUP3(vDistVUP3);
    setVValorQ(vValorQ);
    setVDistQ(vDistQ);
    setVDistQP1(vDistQP1);
    setVDistQP2(vDistQP2);
    setVDistQP3(vDistQP3);
}

void viewWx::lerDadosImp()
{
    setImportEnd(string (wxImportFile->GetPath()));
    setExportFormat(string ((wxExportFormat->GetString(wxExportFormat->GetSelection())).mb_str()));
}

void viewWx::exibirDados()
{
    //Carregamento do grupo ref. à classe transação.
    wxValorBem->SetValue(to_string(getValorBem()));
    wxEntrada->SetValue(to_string(getEntrada()));
    wxAporteFgts->SetValue(to_string(getAporteFgts()));

    //Carregamento do grupo ref. à classe capital externo.
    wxFonte->SetSelection(wxFonte->FindString(getFonte()));
    wxValorCapExt->SetValue(to_string(getValorCapExt()));
    wxTaxaJuros->SetValue(to_string(getTaxaJuros()));
    wxDistJuros->SetSelection(wxDistJuros->FindString(getDistJuros()));
    wxDistJurosP1->SetValue(to_string(getDistJurosP1()));
    wxDistJurosP2->SetValue(to_string(getDistJurosP2()));
    wxDistJurosP3->SetValue(to_string(getDistJurosP3()));
    wxSistAmort->SetSelection(wxSistAmort->FindString(getSistAmort()));
    wxPrazo->SetValue(to_string(getPrazo()));
    wxTaxaServicos->SetValue(to_string(getTaxaServicos()));
    wxCustoContratacao->SetValue(to_string(getCustoContratacao()));

    //Carregamento do grupo ref. à classe de aval. econ.-fin.
    wxCalcAVEF->SetSelection(getCalcularAvef());
    wxNomeIndEcon->SetValue(getNomeIndEcon());
    wxTaxaIndEcon->SetValue(to_string(getTaxaIndEcon()));
    wxTaxaOport->SetValue(to_string(getTaxaOport()));
    wxCustoEvitado->SetValue(to_string(getCustoEvitado()));
    wxPeriodo->SetValue(to_string(getPeriodo()));

//    //Carregamento do grupo ref. à classe simulação de monte carlo.
    wxAmostras->SetValue(to_string(getAmostras()));

    //Carga dos dados do elemento de grid de valores.
    int row;
    int lim;
    if ((getVDescricao().size()>0)&(getVDescricao().size()<=50)){
        lim = getVDescricao().size();
    }else if ((getVDescricao().size()>0)&(getVDescricao().size()>50)){
        lim = 50;
    }

    if (getVDescricao().size()>0){
        for (row = 0;row<lim;row++){
            wxValores->SetCellValue(row,0,getVDescricao()[row]);
            wxValores->SetCellValue(row,1,to_string(getVValorQ()[row]));
            wxValores->SetCellValue(row,2,getVDistQ()[row]);
            wxValores->SetCellValue(row,3,to_string(getVDistQP1()[row]));
            wxValores->SetCellValue(row,4,to_string(getVDistQP2()[row]));
            wxValores->SetCellValue(row,5,to_string(getVDistQP3()[row]));
            wxValores->SetCellValue(row,6,to_string(getVValorU()[row]));
            wxValores->SetCellValue(row,7,getVDistVU()[row]);
            wxValores->SetCellValue(row,8,to_string(getVDistVUP1()[row]));
            wxValores->SetCellValue(row,9,to_string(getVDistVUP2()[row]));
            wxValores->SetCellValue(row,10,to_string(getVDistVUP3()[row]));
        }
    }
}

void viewWx::exibirResSmc()
{
    wxValorMaisProv->ChangeValue(to_string(getValorMaisProvMax()));
}

void viewWx::exibirResAvef()
{
    wxTir->ChangeValue(to_string(getTir()));
    wxPayback->ChangeValue(to_string(getPaybackSimples()));
    wxPaybackDesc->ChangeValue(to_string(getPaybackDescontado()));
    wxVpl->ChangeValue(to_string(getVpl()));
    wxRazaoCb->ChangeValue(to_string(getRazaoCB()));
}

}  // namespace view
