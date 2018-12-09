/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::dynamicFSISolverFvMesh

Description
    The dynamicFSISolverFvMesh

SourceFiles
    dynamicFSISolverFvMesh.C

\*---------------------------------------------------------------------------*/

#ifndef dynamicFSISolverFvMesh_H
#define dynamicFSISolverFvMesh_H

#include "dynamicFvMesh.H"

#include "petscdmplex.h"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


namespace Foam
{

class motionSolver;
/*---------------------------------------------------------------------------*\
                           Class dynamicFSISolverFvMesh Declaration
\*---------------------------------------------------------------------------*/

class dynamicFSISolverFvMesh
:
    public dynamicFvMesh
{
    // Private data

        autoPtr<motionSolver> motionPtr_;

        dictionary  fsiSolverDict_;

	DM          dm_;

    // Private Member Functions

        //- Disallow default bitwise copy construct
        dynamicFSISolverFvMesh(const dynamicFSISolverFvMesh&);

        //- Disallow default bitwise assignment
        void operator=(const dynamicFSISolverFvMesh&);


public:

    //- Runtime type information
    TypeName("dynamicFSISolverFvMesh");


    // Constructors

        //- Construct from IOobject
        dynamicFSISolverFvMesh(const IOobject& io);


    //- Destructor
    ~dynamicFSISolverFvMesh();


    // Member Functions

        //- Return the motionSolver
        const motionSolver& motion() const;

        //- Update the mesh for both mesh motion and topology change
        virtual bool update();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
