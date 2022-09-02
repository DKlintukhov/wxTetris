
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/wx.h>
#include "simple.h"
#include "icon.h"
#include "button.h"
#include "tetris.h"

#include <wx/wx.h>

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/calctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/gauge.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/frame.h>

class MainFrame : public wxFrame
{
private:
protected:
  wxCalendarCtrl *m_calendar1;
  wxGauge *m_gauge1;
  wxGrid *m_grid1;

public:
  MainFrame(wxWindow *parent = nullptr, wxWindowID id = wxID_ANY, const wxString &title = wxT("Test wxWidgets program"), const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(1024, 768), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
  ~MainFrame();
};

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style)
{
  this->SetSizeHints(wxDefaultSize, wxDefaultSize);
  this->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Verdana")));

  wxGridSizer *gSizer1;
  gSizer1 = new wxGridSizer(0, 2, 0, 0);

  m_calendar1 = new wxCalendarCtrl(this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxSize(256, 150), wxCAL_SHOW_HOLIDAYS);
  m_calendar1->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Verdana")));

  gSizer1->Add(m_calendar1, 0, wxALL, 5);

  m_gauge1 = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
  m_gauge1->SetValue(50);
  gSizer1->Add(m_gauge1, 0, wxALL, 5);

  m_grid1 = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

  // Grid
  m_grid1->CreateGrid(5, 5);
  m_grid1->EnableEditing(true);
  m_grid1->EnableGridLines(true);
  m_grid1->EnableDragGridSize(false);
  m_grid1->SetMargins(15, 15);

  // Columns
  m_grid1->EnableDragColMove(false);
  m_grid1->EnableDragColSize(true);
  m_grid1->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

  // Rows
  m_grid1->AutoSizeRows();
  m_grid1->EnableDragRowSize(true);
  m_grid1->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

  // Label Appearance

  // Cell Defaults
  m_grid1->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
  gSizer1->Add(m_grid1, 0, wxALL, 5);

  this->SetSizer(gSizer1);
  this->Layout();

  this->Centre(wxBOTH);
}

MainFrame::~MainFrame()
{
}

class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  // srand(time(NULL));
  // Tetris *tetris = new Tetris(wxT("Tetris"));
  // tetris->Centre();
  MainFrame *frame = new MainFrame();
  frame->Show(true);

  return true;
}
