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
    Foam::fsiSolverFvMesh

Description
    Abstract base class for a fsi solver fvMesh

SourceFiles
    fsiSolverFvMesh.C

\*---------------------------------------------------------------------------*/

#ifndef fsiSolverFvMesh_H
#define fsiSolverFvMesh_H


#include "topoChangerFvMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class fsiSolverFvMesh Declaration
\*---------------------------------------------------------------------------*/

class fsiSolverFvMesh
:
    public topoChangerFvMesh
{
    // Private Member Functions

        //- Disallow default bitwise copy construct
        fsiSolverFvMesh(const fsiSolverFvMesh&);

        //- Disallow default bitwise assignment
        void operator=(const fsiSolverFvMesh&);


protected:

    // Protected Data

public:

    //- Runtime type information
    TypeName("fsiSolverFvMesh");


    // Constructors

        //- Construct from objectRegistry, and read/write options
        explicit fsiSolverFvMesh(const IOobject& io);


    //- Destructor
    virtual ~fsiSolverFvMesh();


    // Member Functions

        //- Update the mesh for both mesh motion and topology change
    virtual bool update();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
