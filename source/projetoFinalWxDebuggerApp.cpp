/***************************************************************
 * Name:      projetoFinalWxDebuggerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Cesar Rafael Lopes (ceslop84@gmail.com)
 * Created:   2019-05-01
 * Copyright: Cesar Rafael Lopes (cartotech.com.br)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "projetoFinalWxDebuggerApp.h"

//(*AppHeaders
#include "projetoFinalWxDebuggerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(projetoFinalWxDebuggerApp);

bool projetoFinalWxDebuggerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	projetoFinalWxDebuggerFrame* Frame = new projetoFinalWxDebuggerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
