/***************************************************************
 * Name:      projetoFinalWxDebuggerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Cesar Rafael Lopes (ceslop84@gmail.com)
 * Created:   2019-04-01
 * Copyright: Cesar Rafael Lopes (cartotech.com.br)
 * License:
 **************************************************************/

#ifndef projetoFinalWxDebuggerMAIN_H
#define projetoFinalWxDebuggerMAIN_H

//(*Headers(projetoFinalWxDebuggerFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/radiobox.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include <wx/msgdlg.h>

#include <iostream>
#include <string>
#include <sstream>
#include "include/view/viewWx.h"
#include "include/view/viewFacade.h"
#include <ctime>


class projetoFinalWxDebuggerFrame: public wxFrame
{
    public:

        //Esta classe é a classe concreta da classe abstrata que é conectada à classe de fachada da camada de visualização.
        //Caso mude a implementação (outra toolkit de UI), esta classe deve ser implementada e alterada.
        view::viewWx dados;
        view::viewFacade viewFacade;

        projetoFinalWxDebuggerFrame(wxWindow* parent,wxWindowID id = -1);

        virtual ~projetoFinalWxDebuggerFrame();

    private:

        //(*Handlers(projetoFinalWxDebuggerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnbtnExecutarClick(wxCommandEvent& event);
        void OnbtnExpClick(wxCommandEvent& event);
        void OnbtnImpClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(projetoFinalWxDebuggerFrame)
        static const long ID_STATICBOX1;
        static const long ID_STATICBOX2;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL5;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_CHOICE3;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT14;
        static const long ID_TEXTCTRL11;
        static const long ID_STATICBOX3;
        static const long ID_GRID;
        static const long ID_STATICBOX4;
        static const long ID_STATICTEXT15;
        static const long ID_TEXTCTRL12;
        static const long ID_STATICTEXT16;
        static const long ID_TEXTCTRL13;
        static const long ID_STATICTEXT17;
        static const long ID_TEXTCTRL14;
        static const long ID_STATICTEXT18;
        static const long ID_TEXTCTRL15;
        static const long ID_STATICBOX5;
        static const long ID_STATICTEXT19;
        static const long ID_TEXTCTRL16;
        static const long ID_STATICTEXT20;
        static const long ID_STATICBOX7;
        static const long ID_STATICTEXT22;
        static const long ID_STATICTEXT21;
        static const long ID_BUTTON1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_BUTTON2;
        static const long ID_STATICBOX8;
        static const long ID_BUTTON3;
        static const long ID_CHOICE4;
        static const long ID_RADIOBOX1;
        static const long ID_STATICBOX9;
        static const long ID_STATICBOX10;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT24;
        static const long ID_TEXTCTRL17;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT26;
        static const long ID_STATICTEXT27;
        static const long ID_STATICTEXT28;
        static const long ID_STATICTEXT29;
        static const long ID_STATICTEXT30;
        static const long ID_TEXTCTRL22;
        static const long ID_TEXTCTRL21;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL19;
        static const long ID_TEXTCTRL18;
        static const long ID_STATICTEXT31;
        static const long ID_TEXTCTRL23;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(projetoFinalWxDebuggerFrame)
        wxButton* btnExecutar;
        wxButton* btnExp;
        wxButton* btnImp;
        wxChoice* cbExp;
        wxChoice* cbxAmort;
        wxChoice* cbxDistJuros;
        wxChoice* cbxFonte;
        wxFilePickerCtrl* fpImp;
        wxGrid* gridValores;
        wxRadioBox* rbCalcAVEF;
        wxStaticBox* bxAEF;
        wxStaticBox* bxAvef;
        wxStaticBox* bxCapitalExterno;
        wxStaticBox* bxExecutar;
        wxStaticBox* bxImportar;
        wxStaticBox* bxSMC;
        wxStaticBox* bxSmc;
        wxStaticBox* bxTransacao;
        wxStaticBox* bxValores;
        wxStaticText* lblAmostras;
        wxStaticText* lblCapExt1Amort;
        wxStaticText* lblCapExt1Fonte;
        wxStaticText* lblCapExt1Valor;
        wxStaticText* lblCaptExt1Juro;
        wxStaticText* lblCustoContrat;
        wxStaticText* lblCustoEvitado;
        wxStaticText* lblCustoOport;
        wxStaticText* lblDistJuros;
        wxStaticText* lblEntrada;
        wxStaticText* lblExpAvef;
        wxStaticText* lblExpSmc;
        wxStaticText* lblFgts;
        wxStaticText* lblFormatoExp;
        wxStaticText* lblFormatoImp;
        wxStaticText* lblIndEcon;
        wxStaticText* lblParam1;
        wxStaticText* lblParam2;
        wxStaticText* lblParam3;
        wxStaticText* lblPaybackDescontado;
        wxStaticText* lblPeriodo;
        wxStaticText* lblPrazo;
        wxStaticText* lblRcb;
        wxStaticText* lblServicos;
        wxStaticText* lblSobreSMC;
        wxStaticText* lblTir;
        wxStaticText* lblValor;
        wxStaticText* lblValorIndEcon;
        wxStaticText* lblValorMaisProv;
        wxStaticText* lblVpl;
        wxStaticText* lblpaybackSimples;
        wxStatusBar* sbBarra;
        wxTextCtrl* txtAmostras;
        wxTextCtrl* txtCapExt1Juro;
        wxTextCtrl* txtCapExt1Valor;
        wxTextCtrl* txtCustoContrat;
        wxTextCtrl* txtCustoEvitado;
        wxTextCtrl* txtCustoOport;
        wxTextCtrl* txtEntrada;
        wxTextCtrl* txtFgts;
        wxTextCtrl* txtIndEcon;
        wxTextCtrl* txtParam1;
        wxTextCtrl* txtParam2;
        wxTextCtrl* txtParam3;
        wxTextCtrl* txtPayback;
        wxTextCtrl* txtPaybackDesc;
        wxTextCtrl* txtPeriodo;
        wxTextCtrl* txtPrazo;
        wxTextCtrl* txtRcb;
        wxTextCtrl* txtServicos;
        wxTextCtrl* txtTir;
        wxTextCtrl* txtValorBem;
        wxTextCtrl* txtValorIndEcon;
        wxTextCtrl* txtValorMaisProvavel;
        wxTextCtrl* txtVpl;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // projetoFinalWxDebuggerMAIN_H
