#ifndef VIEW_VIEW_WX_H
#define VIEW_VIEW_WX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "../../include/view/view.h"

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

namespace view
{
class viewWx : public view
{
public:

	wxTextCtrl* wxValorBem;
	wxTextCtrl* wxEntrada;
	wxTextCtrl* wxAporteFgts;
    wxChoice* wxFonte;
	wxTextCtrl* wxValorCapExt;
	wxTextCtrl* wxTaxaJuros;
	wxChoice* wxDistJuros;
	wxTextCtrl* wxDistJurosP1;
	wxTextCtrl* wxDistJurosP2;
	wxTextCtrl* wxDistJurosP3;
	wxChoice* wxSistAmort;
	wxTextCtrl* wxPrazo;
	wxTextCtrl* wxTaxaServicos;
	wxTextCtrl* wxCustoContratacao;
	wxRadioBox* wxCalcAVEF;
    wxTextCtrl* wxNomeIndEcon;
    wxTextCtrl* wxTaxaIndEcon;
    wxTextCtrl* wxTaxaOport;
    wxTextCtrl* wxCustoEvitado;
    wxTextCtrl* wxPeriodo;
    wxTextCtrl* wxAmostras;
    wxGrid* wxValores;

    wxFilePickerCtrl* wxImportFile;
	wxChoice* wxExportFormat;

	wxTextCtrl* wxValorMaisProv;
	wxTextCtrl* wxTir;
	wxTextCtrl* wxPayback;
	wxTextCtrl* wxPaybackDesc;
	wxTextCtrl* wxVpl;
	wxTextCtrl* wxRazaoCb;

    viewWx();

	void lerDados();
	void lerDadosImp();
	void exibirDados();
	void exibirResSmc();
	void exibirResAvef();
};

}  // namespace view
#endif
