/*
 *  Delphes: a framework for fast simulation of a generic collider experiment
 *  Copyright (C) 2012-2014  Universite catholique de Louvain (UCL), Belgium
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CTagging_h
#define CTagging_h

/** \class CTagging
 *
 *  Determines origin of jet,
 *  applies c-tagging efficiency (miss identification rate) formulas
 *  and sets c-tagging flags
 *
 *  \author
 *
 */

#include "classes/DelphesModule.h"

#include <map>

class TObjArray;
class DelphesFormula;

class CTagging: public DelphesModule
{
public:
  CTagging();
  ~CTagging();

  void Init();
  void Process();
  void Finish();

private:
  Int_t fBitNumber;

#if !defined(__CINT__) && !defined(__CLING__)
  std::map<Int_t, DelphesFormula *> fEfficiencyMap; //!
#endif

  TIterator *fItJetInputArray; //!

  const TObjArray *fJetInputArray; //!

  ClassDef(CTagging, 1)
};

#endif
