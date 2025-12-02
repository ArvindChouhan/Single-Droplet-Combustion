/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2019 OpenCFD Ltd.
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

Application
    laplacianFoam

Group
    grpBasicSolvers

Description
    Laplace equation solver for a scalar quantity.

    \heading Solver details
    The solver is applicable to, e.g. for thermal diffusion in a solid.  The
    equation is given by:

    \f[
        \ddt{T}  = \div \left( D_T \grad T \right)
    \f]

    Where:
    \vartable
        T     | Scalar field which is solved for, e.g. temperature
        D_T   | Diffusion coefficient
    \endvartable

    \heading Required fields
    \plaintable
        T     | Scalar field which is solved for, e.g. temperature
    \endplaintable

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "fvOptions.H"
#include "simpleControl.H"
#include <iostream>            // Added to write in a file
#include <fstream>             // Added to write in a file

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    argList::addNote
    (
        "Laplace equation solver for a scalar quantity."
    );

    #include "postProcess.H"

    #include "addCheckCaseOptions.H"
    #include "setRootCaseLists.H"
    #include "createTime.H"
    #include "createMesh.H"

    simpleControl simple(mesh);

    #include "createFields.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    

    while (simple.loop())
    {
        Info<< "Time = " << runTime.timeName() << endl;
                
        #include "Properties.H"
        #include "Eqn.H"
        
        Info<< "tim: " << runTime.value() << ", Y_PRE_sl: " << Y_PRE_L[999] << ", Y_2EHA_sl: " << Y_2EHA_L[999] << ", Y_XYLENE_sl: " << Y_XYLENE_L[999] << ", Y_PRE_1_sl: " << Y_PRE_L_1[999] <<  endl; 
        Info<< "tim1: " << runTime.value() << ", X_PRE_sl: " << X_PRE_sl.value() << ", X_2EHA_sl: " << X_2EHA_sl.value() << ", X_XYLENE_sl: " << X_XYLENE_sl.value() << ", X_PRE_1_sl: " << X_PRE_1_sl.value() << endl;
        Info<< "tim2: " << runTime.value() << ", X_PRE_sg: " << X_PRE_sg.value() << ", X_2EHA_sg: " << X_2EHA_sg.value() << ", X_XYLENE_sg: " << X_XYLENE_sg.value() << endl;
        Info<< "tim3: " << runTime.value() << ", Y_PRE_sg: " << Y_PRE_sg.value() << ", Y_2EHA_sg: " << Y_2EHA_sg.value() << ", Y_XYLENE_sg: " << Y_XYLENE_sg.value() << endl;
        Info<< "tim6: " << runTime.value() << ", eps_PRE: " << eps_PRE.value() << ", eps_2EHA: " << eps_2EHA.value() << ", eps_XYLENE: " << eps_XYLENE.value() << endl;
        Info<< "tim4: " << runTime.value() << ", rs: " << rs.value() << ", rf: " << rf.value() << ", Ts: " << Ts.value() << ", Tf: " << Tf.value() << ", M_br: " << M_br.value() << ", Y_PRE_1_sl: " << Y_PRE_1_sl.value()  << endl;
        #include "CheckExplosion.H"  
        Info<< "Max mixture pressure " << max(p_mix).value() << endl;
        Info<< "Le2: " << Le_NUM_GAS_2.value() << "Le_eff: " << Le_NUM_GAS_eff.value() << endl;
        Info<< "tim5: " << runTime.value() << " : " << rs.value() << " : " << rf.value() << " : " << rf_D2.value() << " : " << Ts.value() << " : " << Tf.value() << " : " << Tf_D2.value() << " : " << M_br.value() << " : " << max(p_mix).value() << " : " << Y_PRE_1_sl.value() << " : " << Y_PRE_sl.value() << " : " << Y_2EHA_sl.value() << " : " << Y_XYLENE_sl.value() << " : " << Y_PRE_sg.value() << " : " << Y_2EHA_sg.value() << " : " << Y_XYLENE_sg.value() << " : " << drs_dt.value() << " : " << drf_dt.value()  << endl; 
  //      if (max(p_mix).value() > 1) break;      

        

        #include "write.H" 
        runTime.printExecutionTime(Info);
    }

   
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
