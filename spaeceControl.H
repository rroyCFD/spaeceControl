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

Class
    Foam::spaeceControl

Description
    SPAeCE algorithm control class. Provides time-loop and SPAeCE-loop control 
    methods. Convergence check is NOT done.

SourceFiles
    spaeceControlI.H
    spaeceControl.C

\*---------------------------------------------------------------------------*/

#ifndef spaeceControl_H
#define spaeceControl_H

#include "fluidSolutionControl.H"

#define SPAeCE_CONTROL

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class spaeceControl Declaration
\*---------------------------------------------------------------------------*/

class spaeceControl
:
    public fluidSolutionControl
{
protected:

    // Protected data

        //- Maximum number of SPAeCE correctors
        label nCorrSPAeCE_;

        //- Current SPAeCE corrector
        label corrSPAeCE_;


public:

    // Static data members

        //- Run-time type information
        TypeName("spaeceControl");


    // Constructors

        //- Construct from a mesh and the name of the algorithm
        spaeceControl(fvMesh& mesh, const word& algorithmName="SPAeCE");

    //- Destructor
    virtual ~spaeceControl();


    // Member Functions

        // IO

            //- Read controls
            virtual bool read();

        // Access

            //- Maximum number of SPAeCE correctors
            inline label nCorrSPAeCE() const;

            //- Flag to indicate the first SPAeCE iteration
            inline bool firstSPAeCEIter() const;

            //- Flag to indicate the last SPAeCE iteration
            inline bool finalSPAeCEIter() const;

            //- Flag to indicate the last inner iteration (last SPAeCE and last
            //  non-orthogonal)
            inline bool finalInnerIter() const;


        // Evolution

            //- SPAeCE loop
            bool correct();

            //- Time run loop
            bool run(Time& time);

            //- Time loop loop
            bool loop(Time& time);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "spaeceControlI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
