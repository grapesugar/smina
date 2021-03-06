/*
 * SminaOBMolConverter.h
 *
 *  Created on: Jun 4, 2014
 *      Author: dkoes
 */

#ifndef SMINACONVERTER_H_
#define SMINACONVERTER_H_

#include <openbabel/mol.h>
#include <iostream>
#include "parsing.h"
#include "PDBQTUtilities.h"

/* Routines for converting a molecule to smina format.
 */
namespace SminaConverter
{
	//text output
	void convertText(OpenBabel::OBMol& mol, std::ostream& out, int rootatom=0);
	//binary output
	void convertBinary(OpenBabel::OBMol& mol, std::ostream& out, int rootatom=0);

	//convert obmol to smina parsing struct and context; return numtors
	unsigned convertParsing(OpenBabel::OBMol& mol, parsing_struct& p, context& c, int rootatom = 0);

	//class for efficiently converting multi-conformer molecule
	class MCMolConverter
	{
		OpenBabel::OBMol mol;
		std::vector<std::vector<int> > rigid_fragments; //the vector of all the rigid molecule fragments, using atom indexes
		std::map<unsigned int, obbranch> tree;
		unsigned torsdof;
	public:
		MCMolConverter(OpenBabel::OBMol& m);
		//output smina data for specified conformer
		void convertConformer(unsigned c, std::ostream& out);
	};
};

#endif /* SMINACONVERTER_H_ */
