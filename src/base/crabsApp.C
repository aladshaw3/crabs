#include "crabsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
crabsApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

crabsApp::crabsApp(InputParameters parameters) : MooseApp(parameters)
{
  crabsApp::registerAll(_factory, _action_factory, _syntax);
}

crabsApp::~crabsApp() {}

void
crabsApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"crabsApp"});
  Registry::registerActionsTo(af, {"crabsApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
crabsApp::registerApps()
{
  registerApp(crabsApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
crabsApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  crabsApp::registerAll(f, af, s);
}
extern "C" void
crabsApp__registerApps()
{
  crabsApp::registerApps();
}
