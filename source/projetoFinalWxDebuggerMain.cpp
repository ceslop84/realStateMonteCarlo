/***************************************************************
 * Name:      projetoFinalWxDebuggerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Cesar Rafael Lopes (ceslop84@gmail.com)
 * Created:   2019-04-01
 * Copyright: Cesar Rafael Lopes (cartotech.com.br)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "projetoFinalWxDebuggerMain.h"


//(*InternalHeaders(projetoFinalWxDebuggerFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(projetoFinalWxDebuggerFrame)
const long projetoFinalWxDebuggerFrame::ID_STATICBOX1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX2 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL2 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT2 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL3 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT3 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT4 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_CHOICE1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT5 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL4 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT6 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL5 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_CHOICE2 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT7 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT8 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_CHOICE3 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT9 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT10 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT11 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL6 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL7 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL8 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT12 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL9 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT13 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL10 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT14 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL11 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX3 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_GRID = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX4 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT15 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL12 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT16 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL13 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT17 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL14 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT18 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL15 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX5 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT19 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL16 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT20 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX7 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT22 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT21 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_BUTTON1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_BUTTON2 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX8 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_BUTTON3 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_CHOICE4 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_RADIOBOX1 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX9 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICBOX10 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT23 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT24 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL17 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT25 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT26 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT27 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT28 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT29 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT30 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL22 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL21 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL20 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL19 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL18 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATICTEXT31 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_TEXTCTRL23 = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_MENUITEM1 = wxNewId();
const long projetoFinalWxDebuggerFrame::idMenuAbout = wxNewId();
const long projetoFinalWxDebuggerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(projetoFinalWxDebuggerFrame,wxFrame)
    //(*EventTable(projetoFinalWxDebuggerFrame)
    //*)
END_EVENT_TABLE()

projetoFinalWxDebuggerFrame::projetoFinalWxDebuggerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(projetoFinalWxDebuggerFrame)
    wxMenu* mnAjuda;
    wxMenu* mnArquivo;
    wxMenuBar* mbMenu;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSIMPLE_BORDER, _T("wxID_ANY"));
    SetClientSize(wxSize(1654,1000));
    SetExtraStyle( GetExtraStyle() | wxWS_EX_VALIDATE_RECURSIVELY );
    bxTransacao = new wxStaticBox(this, ID_STATICBOX1, _("Transa��o"), wxPoint(16,24), wxSize(480,112), 0, _T("ID_STATICBOX1"));
    bxCapitalExterno = new wxStaticBox(this, ID_STATICBOX2, _("Capital Externo"), wxPoint(16,160), wxSize(480,368), 0, _T("ID_STATICBOX2"));
    txtValorBem = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(288,40), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtValorBem->SetToolTip(_("Valor do bem a ser adquirido."));
    lblValor = new wxStaticText(this, ID_STATICTEXT1, _("Valor do bem a ser adquirido (R$): "), wxPoint(24,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    txtEntrada = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(288,72), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    txtEntrada->SetToolTip(_("Inserir valor que ser� aplicado como entrada na transa��o."));
    lblEntrada = new wxStaticText(this, ID_STATICTEXT2, _("Entrada (R$):"), wxPoint(24,80), wxSize(160,13), 0, _T("ID_STATICTEXT2"));
    txtFgts = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(288,104), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    txtFgts->SetToolTip(_("Caso tenha direiro a aportas valores oriundos do FGTS, insira aqui o total dos valores."));
    lblFgts = new wxStaticText(this, ID_STATICTEXT3, _("Aporte FGTS (R$)"), wxPoint(24,112), wxSize(160,13), 0, _T("ID_STATICTEXT3"));
    lblCapExt1Fonte = new wxStaticText(this, ID_STATICTEXT4, _("Qual a fonte de capital externo\?"), wxPoint(24,192), wxSize(224,13), 0, _T("ID_STATICTEXT4"));
    cbxFonte = new wxChoice(this, ID_CHOICE1, wxPoint(288,184), wxSize(168,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    cbxFonte->Append(_("Financiamento"));
    cbxFonte->Append(_("Hipoteca"));
    cbxFonte->Append(_("Empr�stimo"));
    cbxFonte->Append(_("N�o aplic�vel"));
    cbxFonte->SetToolTip(_("Informe o tipo de aporte de capital externo."));
    lblCapExt1Valor = new wxStaticText(this, ID_STATICTEXT5, _("Valor aportado (R$):"), wxPoint(24,224), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    txtCapExt1Valor = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(288,216), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    txtCapExt1Valor->SetToolTip(_("Valor total do aporte."));
    lblCaptExt1Juro = new wxStaticText(this, ID_STATICTEXT6, _("Taxa de juros (%/ano):"), wxPoint(24,256), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    txtCapExt1Juro = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(288,248), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    txtCapExt1Juro->SetToolTip(_("Taxa de juros do aporte (ex: 9,5 % ao ano)."));
    cbxAmort = new wxChoice(this, ID_CHOICE2, wxPoint(288,392), wxSize(168,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    cbxAmort->Append(_("SAC"));
    cbxAmort->Append(_("PRICE"));
    cbxAmort->Append(_("N�o aplic�vel"));
    cbxAmort->SetToolTip(_("Informe o tipo de amortiza��o. No sistema SAC a amortiza��o � constante e as parcelas s�o vari�veis, sendo maior no in�cio e menos no final. No sistema PRICE a amortiza��o � vari�vel, contudo as parcelas s�o constantes do in�cio ao fim do per�odo de pagamento."));
    lblCapExt1Amort = new wxStaticText(this, ID_STATICTEXT7, _("Sistema de amortiza��o:"), wxPoint(24,400), wxSize(128,13), 0, _T("ID_STATICTEXT7"));
    lblCapExt1Amort->SetToolTip(_("Inserir o tipo de amortiza��o. O mais comum � o uso do sistema SAC, em que a amortiza��o � realizada de forma constante em cada parcela, e os valores das parcelas v�o diminuindo a cada m�s. No sistema PRICE o valor da amortiza��o � vari�vel mas o valor da parcela � constante."));
    lblDistJuros = new wxStaticText(this, ID_STATICTEXT8, _("Distribui��o taxa de juros:"), wxPoint(24,288), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    cbxDistJuros = new wxChoice(this, ID_CHOICE3, wxPoint(288,280), wxSize(168,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    cbxDistJuros->Append(_("Uniforme"));
    cbxDistJuros->Append(_("Normal"));
    cbxDistJuros->Append(_("N�o aplic�vel"));
    cbxDistJuros->SetToolTip(_("Informe qual a varia��o/distribui��o dos valores de taxa de juros."));
    lblParam1 = new wxStaticText(this, ID_STATICTEXT9, _("Par�metro 1:"), wxPoint(128,316), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    lblParam2 = new wxStaticText(this, ID_STATICTEXT10, _("Par�metro 2:"), wxPoint(128,340), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    lblParam3 = new wxStaticText(this, ID_STATICTEXT11, _("Par�metro 3:"), wxPoint(128,364), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    txtParam1 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(288,316), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    txtParam1->SetToolTip(_("Uniforme: valor m�nimo / Normal: m�dia"));
    txtParam2 = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(288,340), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    txtParam2->SetToolTip(_("Uniforme: valor m�dio ou realista /  Normal: desvio padr�o"));
    txtParam3 = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxPoint(288,364), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    txtParam3->SetToolTip(_("Uniforme: valor m�ximo / Normal: n�o aplic�vel"));
    lblServicos = new wxStaticText(this, ID_STATICTEXT12, _("Taxa servi�os (%/m�s):"), wxPoint(24,464), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    txtServicos = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxPoint(288,456), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    txtServicos->SetToolTip(_("Informe a taxa a ser paga em servi�os contratados com o aporte do capital externo (ex: seguro residencial, seguro de vida, etc.)."));
    lblCustoContrat = new wxStaticText(this, ID_STATICTEXT13, _("Custo contrata��o (R$):"), wxPoint(24,496), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    txtCustoContrat = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxPoint(288,488), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    txtCustoContrat->SetToolTip(_("Custo pago no momento da contrata��o. Normalmente � chamado popularmente de \"abertura de cadastro\"."));
    lblPrazo = new wxStaticText(this, ID_STATICTEXT14, _("Prazo de pagamento (meses):"), wxPoint(24,432), wxSize(152,13), 0, _T("ID_STATICTEXT14"));
    txtPrazo = new wxTextCtrl(this, ID_TEXTCTRL11, wxEmptyString, wxPoint(288,424), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    txtPrazo->SetToolTip(_("Prazo total de pagamento previsto, informado em meses"));
    bxValores = new wxStaticBox(this, ID_STATICBOX3, _("Despesas e receitas"), wxPoint(24,544), wxSize(1608,384), 0, _T("ID_STATICBOX3"));
    gridValores = new wxGrid(this, ID_GRID, wxPoint(48,568), wxSize(1560,336), 0, _T("ID_GRID"));
    gridValores->CreateGrid(50,11);
    gridValores->EnableEditing(true);
    gridValores->EnableGridLines(true);
    gridValores->SetDefaultColSize(121, true);
    gridValores->SetColLabelValue(0, _("Descri��o"));
    gridValores->SetColLabelValue(1, _("Quant. (qtd)"));
    gridValores->SetColLabelValue(2, _("Dist. qtd"));
    gridValores->SetColLabelValue(3, _("Dist. qtd P1"));
    gridValores->SetColLabelValue(4, _("Dist. qtd P2"));
    gridValores->SetColLabelValue(5, _("Dist. qtd P3"));
    gridValores->SetColLabelValue(6, _("Valor (R$) (v)"));
    gridValores->SetColLabelValue(7, _("Dist.v"));
    gridValores->SetColLabelValue(8, _("Dist. v P1"));
    gridValores->SetColLabelValue(9, _("Dist. v P2"));
    gridValores->SetColLabelValue(10, _("Dist. v P3"));
    gridValores->SetDefaultCellFont( gridValores->GetFont() );
    gridValores->SetDefaultCellTextColour( gridValores->GetForegroundColour() );
    bxAEF = new wxStaticBox(this, ID_STATICBOX4, _("Avalia��o Econ�mico-Financeira"), wxPoint(520,24), wxSize(480,240), 0, _T("ID_STATICBOX4"));
    lblIndEcon = new wxStaticText(this, ID_STATICTEXT15, _("Indicador econ�mico:"), wxPoint(536,112), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    txtIndEcon = new wxTextCtrl(this, ID_TEXTCTRL12, wxEmptyString, wxPoint(800,104), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    txtIndEcon->SetToolTip(_("Ex: IPCA, INPC, IGP-M, etc."));
    lblValorIndEcon = new wxStaticText(this, ID_STATICTEXT16, _("Valor indicador econ�mico (%/ano):"), wxPoint(536,144), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    txtValorIndEcon = new wxTextCtrl(this, ID_TEXTCTRL13, wxEmptyString, wxPoint(800,136), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    txtValorIndEcon->SetToolTip(_("Taxa anualizada. Ex: 6,5 % ao ano."));
    lblCustoOport = new wxStaticText(this, ID_STATICTEXT17, _("Taxa de custo de oportunidade (%/ano):"), wxPoint(536,176), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    txtCustoOport = new wxTextCtrl(this, ID_TEXTCTRL14, wxEmptyString, wxPoint(800,168), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    txtCustoOport->SetToolTip(_("Valor anualizado da taxa m�dia de retorno dos investimentos atuais. Ex: 8,5 % ao ano."));
    lblCustoEvitado = new wxStaticText(this, ID_STATICTEXT18, _("Custos mensais evitados (R$):"), wxPoint(536,208), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    txtCustoEvitado = new wxTextCtrl(this, ID_TEXTCTRL15, wxEmptyString, wxPoint(800,200), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    txtCustoEvitado->SetToolTip(_("Custos mensais evitados, por m�s. Ex: aluguel de R$ 1.000,00 ao m�s."));
    bxSMC = new wxStaticBox(this, ID_STATICBOX5, _("Simula��o de Monte Carlo"), wxPoint(520,280), wxSize(480,248), 0, _T("ID_STATICBOX5"));
    lblAmostras = new wxStaticText(this, ID_STATICTEXT19, _("Valor de amostras:"), wxPoint(536,312), wxSize(96,13), 0, _T("ID_STATICTEXT19"));
    txtAmostras = new wxTextCtrl(this, ID_TEXTCTRL16, wxEmptyString, wxPoint(800,304), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    txtAmostras->SetToolTip(_("Valor de amostras para a simula��o de Monte Carlo. Ex: 1000"));
    lblSobreSMC = new wxStaticText(this, ID_STATICTEXT20, _("A Simula��o de Monte Carlo, ou ainda Modelagem ou M�todo de Monte Carlo, refere-se a uma metodologia para resolver problemas matem�ticos usando amostras aleat�rias. Um exemplo desse conceito � o c�lculo do valor de expectativa de uma vari�vel aleat�ria, sendo que ao inv�s de calcularmos o valor desta expectativa conforme sua defini��o te�rica, que pode envolver a resolu��o de integrais complexas, � realizada a coleta de uma grande quantidade de amostras aleat�rias e seu valor esperado � estimado baseado nessas amostras.\n\nObviamente que esta an�lise considerada exclusivamente aspectos objetivos e determin�sticos de um projeto, neste caso a compra de um im�vel, desconsiderando aspectos relevantes, mas, de cunho pessoal e subjetivo."), wxPoint(536,368), wxSize(424,152), 0, _T("ID_STATICTEXT20"));
    bxImportar = new wxStaticBox(this, ID_STATICBOX7, _("Importar/Exportar"), wxPoint(1024,24), wxSize(248,272), 0, _T("ID_STATICBOX7"));
    lblFormatoImp = new wxStaticText(this, ID_STATICTEXT22, _("Arquivo:"), wxPoint(1040,48), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    lblFormatoExp = new wxStaticText(this, ID_STATICTEXT21, _("Formato:"), wxPoint(1040,128), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    btnExp = new wxButton(this, ID_BUTTON1, _("Exportar"), wxPoint(1040,232), wxSize(216,21), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnExp->SetToolTip(_("Favor selecionar formato."));
    fpImp = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxPoint(1040,72), wxSize(176,21), wxFLP_CHANGE_DIR|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    btnImp = new wxButton(this, ID_BUTTON2, _("Importar"), wxPoint(1040,176), wxSize(216,21), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnImp->SetToolTip(_("Favor selecionar arquivo e formato."));
    bxExecutar = new wxStaticBox(this, ID_STATICBOX8, _("Executar"), wxPoint(1024,312), wxSize(248,216), 0, _T("ID_STATICBOX8"));
    btnExecutar = new wxButton(this, ID_BUTTON3, _("Executar"), wxPoint(1040,408), wxSize(216,21), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    cbExp = new wxChoice(this, ID_CHOICE4, wxPoint(1088,120), wxSize(174,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    cbExp->Append(_("CSV"));
    cbExp->Append(_("TXT"));
    wxString __wxRadioBoxChoices_1[2] =
    {
    	_("N�o"),
    	_("Sim")
    };
    rbCalcAVEF = new wxRadioBox(this, ID_RADIOBOX1, _("Calcular avalia��o econ�mico-financeira\?"), wxPoint(536,48), wxSize(440,48), 2, __wxRadioBoxChoices_1, 2, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    rbCalcAVEF->SetSelection(0);
    bxSmc = new wxStaticBox(this, ID_STATICBOX9, _("Resultado - Simula��o de Monte Carlo"), wxPoint(1288,24), wxSize(344,184), 0, _T("ID_STATICBOX9"));
    bxAvef = new wxStaticBox(this, ID_STATICBOX10, _("Resultado - Avalia��o Econ�mico-Financeira"), wxPoint(1288,224), wxSize(344,304), 0, _T("ID_STATICBOX10"));
    lblValorMaisProv = new wxStaticText(this, ID_STATICTEXT23, _("Valor mais prov�vel:"), wxPoint(1304,48), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    lblExpSmc = new wxStaticText(this, ID_STATICTEXT24, _("Conforme dados inseridos e Simula��o de Monte Carlo realizada o comprador, com 95% de probabilidade, ir� despendero valor acima informado como limite m�ximo para realizar o projeto de aquisi��o da resid�ncia pretendida. "), wxPoint(1296,80), wxSize(328,88), 0, _T("ID_STATICTEXT24"));
    txtValorMaisProvavel = new wxTextCtrl(this, ID_TEXTCTRL17, _("N�o calculado"), wxPoint(1440,40), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    txtValorMaisProvavel->Disable();
    lblTir = new wxStaticText(this, ID_STATICTEXT25, _("TIR (%):"), wxPoint(1304,248), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    lblTir->SetToolTip(_("TIR ou Taxa Interna de Rentabilidade � a taxa de atualiza��o do projeto que d� o VPL nulo. Deve ser comparada com a Taxa M�nima de Atratividade - TMA do adquirente.\n\nPara esta an�lise a TMA � equivalente � taxa de custo de oportunidade.\n\nSe a TIR for mais que a TMA o projeto � considerado vantajoso."));
    lblpaybackSimples = new wxStaticText(this, ID_STATICTEXT26, _("Payback Simples (meses):"), wxPoint(1304,280), wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    lblpaybackSimples->SetToolTip(_("Payback refere-se ao tempo que um investimento leva para pagar o seu investimento inicial. \n\nNo m�todo simples � definido como o n�mero de per�odos para se recuperar o investimento inicial.\n\nQuanto menor for este prazo melhor!"));
    lblPaybackDescontado = new wxStaticText(this, ID_STATICTEXT27, _("Payback Desc. (meses):"), wxPoint(1304,312), wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    lblPaybackDescontado->SetToolTip(_("Payback refere-se ao tempo que um investimento leva para pagar o seu investimento inicial.\n\nNo m�todo descontado emprega-se uma taxa de desconto antes de se proceder � soma dos fluxos de caixa.  Neste caso � empregado a taxa informada no campo do valor do indicador econ�mico.\n\nQuanto menor for este prazo melhor!"));
    lblVpl = new wxStaticText(this, ID_STATICTEXT28, _("VPL (R$):"), wxPoint(1304,344), wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    lblVpl->SetToolTip(_("VPL ou Valor Presente L�quido � a f�rmula financeira capaz de determinar o valor presente de pagamentos futuros descontados a uma taxa de interessa apropriada, menos o custo do investimento inicial. \n\nA taxa emprega neste caso � a taxa de custo de oportunidade.\n\nSe o VPL for mais que zero o projeto � vantajoso!"));
    lblRcb = new wxStaticText(this, ID_STATICTEXT29, _("Raz�o custo/benef�cio:"), wxPoint(1304,376), wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    lblRcb->SetToolTip(_("A rela��o de custo-beneficio � um indicador que relaciona os benef�cios de um projeto ou proposta, expressos em termos monet�rios, e o seus custos, tamb�m expressos em termos monet�rios. \n\nTanto os benef�cios como os custos devem ser expressos em valores presentes. \n\nEm regra geral, se essa rela��o � > 1 o projeto � considerado vantajoso.\n\n"));
    lblExpAvef = new wxStaticText(this, ID_STATICTEXT30, _("Premissas:\n1 - S�o considerados os valores cadastrados nos campos valor, ou seja n�o se considera a distribui��o de dispers�o para estes c�lculos;\n2 - O per�odo total de analise (n) � sempre acrescido de 2, referentes ao desembolso inicial (t=n-1) e o retorno final do investimento (t=n+1);\n3 - O valor do im�veil � ajustado pela taxa do indicador econ�mico para o �ltimo per�odo da an�lise como uma receita.\n\n"), wxPoint(1296,400), wxSize(328,120), wxST_NO_AUTORESIZE|wxNO_BORDER|wxVSCROLL|wxALWAYS_SHOW_SB, _T("ID_STATICTEXT30"));
    wxFont lblExpAvefFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_NORMAL,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
    lblExpAvef->SetFont(lblExpAvefFont);
    txtTir = new wxTextCtrl(this, ID_TEXTCTRL22, _("N�o calculado"), wxPoint(1440,240), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    txtTir->Disable();
    txtPayback = new wxTextCtrl(this, ID_TEXTCTRL21, _("N�o calculado"), wxPoint(1440,272), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    txtPayback->Disable();
    txtPaybackDesc = new wxTextCtrl(this, ID_TEXTCTRL20, _("N�o calculado"), wxPoint(1440,304), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    txtPaybackDesc->Disable();
    txtVpl = new wxTextCtrl(this, ID_TEXTCTRL19, _("N�o calculado"), wxPoint(1440,336), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    txtVpl->Disable();
    txtRcb = new wxTextCtrl(this, ID_TEXTCTRL18, _("N�o calculado"), wxPoint(1440,368), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    txtRcb->Disable();
    lblPeriodo = new wxStaticText(this, ID_STATICTEXT31, _("Periodo de an�lise:"), wxPoint(536,240), wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    txtPeriodo = new wxTextCtrl(this, ID_TEXTCTRL23, wxEmptyString, wxPoint(800,232), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    mbMenu = new wxMenuBar();
    mnArquivo = new wxMenu();
    MenuItem1 = new wxMenuItem(mnArquivo, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    mnArquivo->Append(MenuItem1);
    mbMenu->Append(mnArquivo, _("&Arquivo"));
    mnAjuda = new wxMenu();
    MenuItem2 = new wxMenuItem(mnAjuda, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    mnAjuda->Append(MenuItem2);
    mbMenu->Append(mnAjuda, _("&Ajuda"));
    SetMenuBar(mbMenu);
    sbBarra = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    sbBarra->SetFieldsCount(1,__wxStatusBarWidths_1);
    sbBarra->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(sbBarra);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projetoFinalWxDebuggerFrame::OnbtnExpClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projetoFinalWxDebuggerFrame::OnbtnImpClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projetoFinalWxDebuggerFrame::OnbtnExecutarClick);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&projetoFinalWxDebuggerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&projetoFinalWxDebuggerFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&projetoFinalWxDebuggerFrame::OnClose);
    //*)

    //Inicia a implementa��o da classe que faz a liga��o entre a camada de visualiza��o e a camada de controle.
    dados = view::viewWx();
    viewFacade = view::viewFacade();
    viewFacade.setDados(&dados);

    //Faz o mapeamento dos campos da classe da camada de visualiza��o com os elementos gr�ficos da UI.
    dados.wxAmostras = txtAmostras;
    dados.wxAporteFgts = txtFgts;
    dados.wxCalcAVEF = rbCalcAVEF;
    dados.wxCustoContratacao = txtCustoContrat;
    dados.wxCustoEvitado = txtCustoEvitado;
    dados.wxDistJuros = cbxDistJuros;
    dados.wxDistJurosP1 = txtParam1;
    dados.wxDistJurosP2 = txtParam2;
    dados.wxDistJurosP3 = txtParam3;
    dados.wxSistAmort = cbxAmort;
    dados.wxPrazo = txtPrazo;
    dados.wxTaxaServicos = txtServicos;
    dados.wxEntrada = txtEntrada;
    dados.wxExportFormat = cbExp;
    dados.wxFonte = cbxFonte;
    dados.wxImportFile = fpImp;
    dados.wxNomeIndEcon = txtIndEcon;
    dados.wxPeriodo = txtPeriodo;
    dados.wxPayback = txtPayback;
    dados.wxPaybackDesc = txtPaybackDesc;
    dados.wxValores = gridValores;
    dados.wxRazaoCb = txtRcb;
    dados.wxValorMaisProv = txtValorMaisProvavel;
    dados.wxTir = txtTir;
    dados.wxValorBem = txtValorBem;
    dados.wxVpl = txtVpl;
    dados.wxValorCapExt = txtCapExt1Valor;
    dados.wxTaxaJuros = txtCapExt1Juro;
    dados.wxTaxaOport = txtCustoOport;
    dados.wxTaxaIndEcon = txtValorIndEcon;

    //Carrega as combobox do grid de valores.
    wxString choices[3]={wxT("Uniforme"), wxT("Normal"), wxT("")};
    for (int i = 0; i<50; i++){
        gridValores->SetCellEditor(i,2, new wxGridCellChoiceEditor(3, choices, false));
        gridValores->SetCellEditor(i,7, new wxGridCellChoiceEditor(3, choices, false));
    }
    gridValores->Refresh();


}

projetoFinalWxDebuggerFrame::~projetoFinalWxDebuggerFrame()
{
    //(*Destroy(projetoFinalWxDebuggerFrame)
    //*)
}

void projetoFinalWxDebuggerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void projetoFinalWxDebuggerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Sistema para Simula��o de Monte Carlo."));
}

void projetoFinalWxDebuggerFrame::OnClose(wxCloseEvent& event)
{
     Close();
}

void projetoFinalWxDebuggerFrame::OnbtnExecutarClick(wxCommandEvent& event)
{
    std::stringstream s;
    clock_t begin = clock();

    //L� os dados dispon�veis nos objetos da UI. Esta leitura se d� cfe mapeamento e implementa��o da classe viewWx.
    dados.lerDados();

    //Se houverem erros de formato, ser� mostrado uma lista de corre'~oes ao usu�rio.
    if (dados.isErro()){
        wxMessageBox(dados.getMsg(), _("ATEN��O"));
    }else{
        wxMessageBox("Dados cadastrados com sucesso. Iniciando o processamento...!", _("Informa��o"));
        viewFacade.executar();
         if (dados.isErro()){
            wxMessageBox(dados.getMsg(), _("ATEN��O"));
            dados.cleanMsg();
         }else{
            dados.exibirResSmc();
            dados.exibirResAvef();
            clock_t end = clock();
            double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
            s << "Execu��o conclu�da em " << elapsed_secs << " segundos!";
            wxMessageBox(s.str(), _("Informa��o"));
        }
    }

}

void projetoFinalWxDebuggerFrame::OnbtnExpClick(wxCommandEvent& event)
{
    //L� os dados dispon�veis nos objetos da UI. Esta leitura se d� cfe mapeamento e implementa��o da classe viewWx.
    dados.lerDados();

    if (dados.isErro()){
        wxMessageBox(dados.getMsg(), _("ATEN��O"));
     }else{
        viewFacade.exportar();
        if (dados.isErro()){
            wxMessageBox(dados.getMsg(), _("ATEN��O"));
            dados.cleanMsg();
        }else{
            wxMessageBox("Exporta��o conclu�da!", _("Informa��o"));
        }
    }
}

void projetoFinalWxDebuggerFrame::OnbtnImpClick(wxCommandEvent& event)
{
    dados.lerDadosImp();
    viewFacade.importar();
    if (dados.isErro()){
        wxMessageBox(dados.getMsg(), _("ATEN��O"));
        dados.cleanMsg();
    }else{
        dados.exibirDados();
        wxMessageBox("Importa��o conclu�da!", _("Informa��o"));
    }
}
