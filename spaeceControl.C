/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2018 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "spaeceControl.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(spaeceControl, 0);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::spaeceControl::spaeceControl(fvMesh& mesh, const word& algorithmName)
:
    fluidSolutionControl(mesh, algorithmName),
    nCorrSPAeCE_(-1),
    corrSPAeCE_(0)
{
    read();
    Info << "SPAeCE algorithm constructor" << endl;
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::spaeceControl::~spaeceControl()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

bool Foam::spaeceControl::read()
{
    if (!fluidSolutionControl::read())
    {
        return false;
    }

    const dictionary& solutionDict = dict();

    nCorrSPAeCE_ = solutionDict.lookupOrDefault<label>("nCorrectors", 1);

    return true;
}


bool Foam::spaeceControl::correct()
{
    read();

    if (finalSPAeCEIter())
    {
        corrSPAeCE_ = 0;
        return false;
    }

    ++ corrSPAeCE_;

    return true;
}


bool Foam::spaeceControl::run(Time& time)
{
    return time.run();
}


bool Foam::spaeceControl::loop(Time& time)
{
    return time.loop();
}


// ************************************************************************* //
