// File:	AdvApp2Var_EvaluatorFunc2Var.hxx
// Created:	Thu Apr 18 10:31:26 1996
// Author:	Joelle CHAUVET
//		<jct@sgi38>

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_PrimitiveTypes_HeaderFile
#include <Standard_PrimitiveTypes.hxx>
#endif

#ifndef AdvApp2Var_EvaluatorFunc2Var_HeaderFile
#define AdvApp2Var_EvaluatorFunc2Var_HeaderFile

// History - the C function pointer converted to a virtual class
// in order to get rid of usage of static functions and static data
class AdvApp2Var_EvaluatorFunc2Var
{
public:

  //! Empty constructor
  AdvApp2Var_EvaluatorFunc2Var() {}

  //! Destructor should be declared as virtual
  virtual ~AdvApp2Var_EvaluatorFunc2Var () {}

  //! Function evaluation method to be defined by descendant
  virtual void Evaluate (Standard_Integer* theDimension,
                         Standard_Real*    theUStartEnd,
                         Standard_Real*    theVStartEnd,
                         Standard_Integer* theFavorIso,   //!< Choice of constante, 1 for U, 2 for V
                         Standard_Real*    theConstParam, //!< Value of constant parameter
                         Standard_Integer* theNbParams,   //!< Number of parameters N
                         Standard_Real*    theParameters, //!< Values of parameters,
                         Standard_Integer* theUOrder,     //!< Derivative Request in U
                         Standard_Integer* theVOrder,     //!< Derivative Request in V
                         Standard_Real*    theResult,     //!< Result[Dimension,N]
                         Standard_Integer* theErrorCode) const = 0;

  //! Shortcut for function-call style usage
  void operator() (Standard_Integer* theDimension,
                   Standard_Real*    theUStartEnd,
                   Standard_Real*    theVStartEnd,
                   Standard_Integer* theFavorIso,
                   Standard_Real*    theConstParam,
                   Standard_Integer* theNbParams,
                   Standard_Real*    theParameters,
                   Standard_Integer* theUOrder,
                   Standard_Integer* theVOrder,
                   Standard_Real*    theResult,
                   Standard_Integer* theErrorCode) const
  {
    Evaluate (theDimension, theUStartEnd, theVStartEnd, theFavorIso,
              theConstParam, theNbParams,
              theParameters, theUOrder, theVOrder, theResult, theErrorCode);
  }

private:

  //! Copy constructor is declared private to forbid copying
  AdvApp2Var_EvaluatorFunc2Var (const AdvApp2Var_EvaluatorFunc2Var& ) {}

  //! Assignment operator is declared private to forbid copying
  void operator= (const AdvApp2Var_EvaluatorFunc2Var& ) {}
};

#endif
