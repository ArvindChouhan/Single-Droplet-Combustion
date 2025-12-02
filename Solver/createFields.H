
volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField T_BC
(
    IOobject
    (
        "T_BC",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Y_PRE_L
(
    IOobject
    (
        "Y_PRE_L",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Y_PRE_L_BC       // Mass fraction of precursor in the liquid 
(
    IOobject
    (
        "Y_PRE_L_BC",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Y_PRE_L_1
(
    IOobject
    (
        "Y_PRE_L_1",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Y_2EHA_L      // Mass fraction of 2EHA in the liquid
(
    IOobject
    (
        "Y_2EHA_L",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Y_2EHA_L_BC      // Mass fraction of 2EHA in the liquid
(
    IOobject
    (
        "Y_2EHA_L_BC",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Y_XYLENE_L     // Mass fraction of XYLENE in the liquid
(
    IOobject
    (
        "Y_XYLENE_L",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField p_mix         // Volume fraction of solid phase
(
    IOobject
    (
        "p_mix",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


volScalarField x
(
    IOobject
    (
        "x",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh
);  

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);


dimensionedScalar Hv_PRE("Hv_PRE", dimensionSet(0, 2, -2, 0, 0, 0, 0), transportProperties);
dimensionedScalar Hv_2EHA("Hv_2EHA", dimensionSet(0, 2, -2, 0, 0, 0, 0), transportProperties);
dimensionedScalar Hv_XYLENE("Hv_XYLENE", dimensionSet(0, 2, -2, 0, 0, 0, 0), transportProperties);

dimensionedScalar Hc_PRE("Hc_PRE", dimensionSet(0, 2, -2, 0, 0, 0, 0), transportProperties);
dimensionedScalar Hc_2EHA("Hc_2EHA", dimensionSet(0, 2, -2, 0, 0, 0, 0), transportProperties);
dimensionedScalar Hc_XYLENE("Hc_XYLENE", dimensionSet(0, 2, -2, 0, 0, 0, 0), transportProperties);

dimensionedScalar  R("R", dimensionSet(1, 2, -2, -1, -1, 0, 0), transportProperties);                          

dimensionedScalar Tb_PRE("Tb_PRE", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);
dimensionedScalar Tb_2EHA("Tb_2EHA", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);
dimensionedScalar Tb_XYLENE("Tb_XYLENE", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);

dimensionedScalar Tc_2EHA("Tc_2EHA", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);
dimensionedScalar Tc_XYLENE("Tc_XYLENE", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);

dimensionedScalar Tinf("Tinf", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);
dimensionedScalar Ta("Ta", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);                            

dimensionedScalar MW_PRE("MW_PRE", dimensionSet(1, 0, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar MW_PRE_1("MW_PRE_1", dimensionSet(1, 0, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar MW_2EHA("MW_2EHA", dimensionSet(1, 0, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar MW_XYLENE("MW_XYLENE", dimensionSet(1, 0, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar MW_H2O("MW_H2O", dimensionSet(1, 0, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar MW_CO2("MW_CO2", dimensionSet(1, 0, 0, 0, -1, 0, 0), transportProperties);

dimensionedScalar VM_PRE("VM_PRE", dimensionSet(0, 3, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar VM_PRE_1("VM_PRE_1", dimensionSet(0, 3, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar VM_2EHA("VM_2EHA", dimensionSet(0, 3, 0, 0, -1, 0, 0), transportProperties);
dimensionedScalar VM_XYLENE("VM_XYLENE", dimensionSet(0, 3, 0, 0, -1, 0, 0), transportProperties);

dimensionedScalar v_PRE("v_PRE", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar v_2EHA("v_2EHA", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar v_XYLENE("v_XYLENE", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);

dimensionedScalar Y_O2_Inf("Y_O2_Inf", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);  

dimensionedScalar ri("ri", dimensionSet(0, 1, 0, 0, 0, 0, 0), transportProperties); 

dimensionedScalar rho_XYLENE("rho_XYLENE", dimensionSet(1, -3, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar rho_2EHA("rho_2EHA", dimensionSet(1, -3, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar rho_PRE("rho_PRE", dimensionSet(1, -3, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar rho_PRE_1("rho_PRE_1", dimensionSet(1, -3, 0, 0, 0, 0, 0), transportProperties);

dimensionedScalar Le_NUM_LIQUID("Le_NUM_LIQUID", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar Le_NUM_GAS_2("Le_NUM_GAS_2", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);          // done
dimensionedScalar Le_NUM_GAS_eff("Le_NUM_GAS_eff", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);      // done 
dimensionedScalar Da_NUM("Da_NUM", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar Ar_NUM("Ar_NUM", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);

dimensionedScalar p_atm("p_atm", dimensionSet(1, 0, -2, 0, 0, 0, 0), transportProperties);

dimensionedScalar UC_temp("UC_temp", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);
dimensionedScalar UC_space("UC_space", dimensionSet(0, 1, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar UC_Cp("UC_Cp", dimensionSet(0, 2, -2, -1, 0, 0, 0), transportProperties);
dimensionedScalar UC_K("UC_K", dimensionSet(1, 1, -3, -1, 0, 0, 0), transportProperties);	
dimensionedScalar UC_rho("UC_rho", dimensionSet(1, -3, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar UC_D("UC_D", dimensionSet(0, 2, -1, 0, 0, 0, 0), transportProperties);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "createFvOptions.H"

dimensionedScalar     Ts = UC_temp*T[999];                // done
dimensionedScalar     Tref_GAS_1 = 0.33*Ts + 0.66*Ta;     // done 
dimensionedScalar     Tref_GAS_2 = 0.33*Ta + 0.66*Tinf;   // done

volScalarField        rho_LIQUID = 1/(Y_XYLENE_L/rho_XYLENE + Y_2EHA_L/rho_2EHA + Y_PRE_L/rho_PRE + Y_PRE_L_1/rho_PRE_1);    // done

dimensionedScalar     Y_PRE_sl = Y_PRE_L[999];           // done  
dimensionedScalar     Y_PRE_1_sl = Y_PRE_L_1[999];       // done 
dimensionedScalar     Y_2EHA_sl = Y_2EHA_L[999];         // done 
dimensionedScalar     Y_XYLENE_sl = Y_XYLENE_L[999];     // done 


dimensionedScalar     X_PRE_sl = (Y_PRE_sl/MW_PRE) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);            // done
dimensionedScalar     X_PRE_1_sl = (Y_PRE_1_sl/MW_PRE_1) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);      // done 
dimensionedScalar     X_2EHA_sl = (Y_2EHA_sl/MW_2EHA) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);         // done
dimensionedScalar     X_XYLENE_sl = (Y_XYLENE_sl/MW_XYLENE) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);   // done

dimensionedScalar     X_PRE_sg = X_PRE_sl * exp((Hv_PRE*MW_PRE/R)*(1/Tb_PRE-1/Ts));                                                           // done
dimensionedScalar     X_2EHA_sg = X_2EHA_sl * exp((Hv_2EHA*MW_2EHA/R)*(1/Tb_2EHA-1/Ts));                                                       // done  
dimensionedScalar     X_XYLENE_sg = X_XYLENE_sl * exp((Hv_XYLENE*MW_XYLENE/R)*(1/Tb_XYLENE-1/Ts));                                               // done 
dimensionedScalar     X_H2O_sg = ((5*X_XYLENE_sg + 8*X_2EHA_sg) / (13*X_XYLENE_sg + 16*X_2EHA_sg)) * (1-(X_XYLENE_sg + X_2EHA_sg));           // done  
dimensionedScalar     X_CO2_sg = 1 - (X_XYLENE_sg + X_2EHA_sg + X_H2O_sg);                                                                    // done   

dimensionedScalar     Y_PRE_sg = (X_PRE_sg * MW_PRE)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);         // done
dimensionedScalar     Y_2EHA_sg = (X_2EHA_sg * MW_2EHA)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);      // done
dimensionedScalar     Y_XYLENE_sg = (X_XYLENE_sg * MW_XYLENE)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);// done
dimensionedScalar     Y_H2O_sg = (X_H2O_sg * MW_H2O)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);         // done
dimensionedScalar     Y_CO2_sg = (X_CO2_sg * MW_CO2)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);         // done

dimensionedScalar     K_2EHA_GAS_1 = (1e-7*Tref_GAS_1.value()*Tref_GAS_1.value() + 1e-5*Tref_GAS_1.value() + 0.0031) * UC_K;    // done
dimensionedScalar     K_XYLENE_GAS_1 = (1e-7*Tref_GAS_1.value()*Tref_GAS_1.value() - 8e-6*Tref_GAS_1.value() + 0.0102) * UC_K;  // done
dimensionedScalar     K_PRE_GAS_1 = (1e-7*Tref_GAS_1.value()*Tref_GAS_1.value() - 8e-6*Tref_GAS_1.value() + 0.0102) * UC_K;     // done
dimensionedScalar     K_CO2_GAS_1 = (-3e-8*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0001*Tref_GAS_1.value() - 0.0155) * UC_K;  // done 
dimensionedScalar     K_H2O_GAS_1 = (3e-8*Tref_GAS_1.value()*Tref_GAS_1.value() + 8e-5*Tref_GAS_1.value() - 0.0107) * UC_K;     // done

dimensionedScalar     Cp_2EHA_GAS_1 = 1000*(-1e-6*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0035*Tref_GAS_1.value() + 0.6088) * UC_Cp;    // done
dimensionedScalar     Cp_XYLENE_GAS_1 = 1000*(-1e-6*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0037*Tref_GAS_1.value() + 0.3522) * UC_Cp;  // done
dimensionedScalar     Cp_PRE_GAS_1 = 1000*(-1e-6*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0037*Tref_GAS_1.value() + 0.3522) * UC_Cp;     // done
dimensionedScalar     Cp_CO2_GAS_1 = 1000*(-2e-7*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0007*Tref_GAS_1.value() + 0.7084) * UC_Cp;     // done
dimensionedScalar     Cp_H2O_GAS_1 = 1000*(-3e-8*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0007*Tref_GAS_1.value() + 1.5906) * UC_Cp;     // done 
   
dimensionedScalar     X_REF_2EHA_GAS_1 = 0.33*X_2EHA_sg;      // done            // taking mole fractions of ETH at flame 0                                                                                       
dimensionedScalar     X_REF_XYLENE_GAS_1 = 0.33*X_XYLENE_sg;  // done        // taking mole fractions of XYLENE at flame 0
dimensionedScalar     X_REF_PRE_GAS_1 = 0.66*X_PRE_sg;        // done
dimensionedScalar     X_REF_CO2_GAS_1 = 0.33*X_CO2_sg + 0.66*(16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)/(31*X_PRE_sg+13*X_XYLENE_sg+16*X_2EHA_sg); // done
dimensionedScalar     X_REF_H2O_GAS_1 = 0.33*X_H2O_sg + 0.66*(15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)/(31*X_PRE_sg+13*X_XYLENE_sg+16*X_2EHA_sg); // done
   
dimensionedScalar     Y_REF_2EHA_GAS_1 = 0.33*Y_2EHA_sg;       // done          // taking Mass fractions of ETH at flame 0 
dimensionedScalar     Y_REF_XYLENE_GAS_1 = 0.33*Y_XYLENE_sg;   // done         // taking Mass fractions of Xylene at flame 0
dimensionedScalar     Y_REF_PRE_GAS_1 = 0.66*Y_PRE_sg;         // done 
dimensionedScalar     Y_REF_CO2_GAS_1 = 0.33*Y_CO2_sg + 0.66*  ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);   // done
dimensionedScalar     Y_REF_H2O_GAS_1 = 0.33*X_H2O_sg + 0.66* ((15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);    // done
   
dimensionedScalar     K_GAS_1 = 0.5*(X_REF_XYLENE_GAS_1*K_XYLENE_GAS_1+X_REF_2EHA_GAS_1*K_2EHA_GAS_1+X_REF_CO2_GAS_1*K_CO2_GAS_1+X_REF_H2O_GAS_1*K_H2O_GAS_1) + 0.5*(1/(X_REF_XYLENE_GAS_1/K_XYLENE_GAS_1+X_REF_2EHA_GAS_1/K_2EHA_GAS_1+X_REF_CO2_GAS_1/K_CO2_GAS_1+X_REF_H2O_GAS_1/K_H2O_GAS_1));  // Ren supplementary
dimensionedScalar     Cp_GAS_1 = Y_REF_XYLENE_GAS_1*Cp_XYLENE_GAS_1+Y_REF_2EHA_GAS_1*Cp_2EHA_GAS_1+Y_REF_CO2_GAS_1*Cp_CO2_GAS_1+Y_REF_H2O_GAS_1*Cp_H2O_GAS_1;
   
dimensionedScalar     Cp_CO2_GAS_2 = 1000*(-2e-7*Tref_GAS_2.value()*Tref_GAS_2.value() + 0.0007*Tref_GAS_2.value() + 0.7084) * UC_Cp; // done
dimensionedScalar     Cp_H2O_GAS_2 = 1000*(-3e-8*Tref_GAS_2.value()*Tref_GAS_2.value() + 0.0007*Tref_GAS_2.value() + 1.5906) * UC_Cp; // done 
dimensionedScalar     Cp_O2_GAS_2 = 1000*(-5e-8*Tref_GAS_2.value()*Tref_GAS_2.value() + 0.0003*Tref_GAS_2.value() + 0.8558) * UC_Cp;  // done
dimensionedScalar     Y_REF_CO2_GAS_2 = 0.33*((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);      // taking mass fraction of Co2 at inifinite 0
dimensionedScalar     Y_REF_H2O_GAS_2 = 0.33*((15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);     // taking mass fraction of H2O at inifinite 0 
dimensionedScalar     Y_REF_O2_GAS_2 = 0.66*1;
dimensionedScalar     Cp_GAS_2 = Y_REF_CO2_GAS_2*Cp_CO2_GAS_2 + Y_REF_H2O_GAS_2*Cp_H2O_GAS_2 + Y_REF_O2_GAS_2*Cp_O2_GAS_2;

dimensionedScalar     eps_PRE = Y_PRE_sg / (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg);         // done
dimensionedScalar     eps_2EHA = Y_2EHA_sg / (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg);       // done
dimensionedScalar     eps_XYLENE = Y_XYLENE_sg / (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg);   // done
dimensionedScalar     v = eps_PRE * v_PRE + eps_XYLENE * v_XYLENE + eps_2EHA * v_2EHA;   // done
dimensionedScalar     Bm = ((Y_O2_Inf/v) + (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg)) / (1 - (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg)); // done

dimensionedScalar     rs = ri;      // done
dimensionedScalar     rs_old = rs;  // done
dimensionedScalar     M_br = 4 * 3.14 * rs * K_GAS_1 * Foam::log(1+Bm) / Cp_GAS_1;    // done
dimensionedScalar     rho_sl = 1/(Y_PRE_sl/rho_PRE + Y_PRE_1_sl/rho_PRE_1 + Y_2EHA_sl/rho_2EHA + Y_XYLENE_sl/rho_XYLENE); // done
dimensionedScalar     k = 2 * M_br / (3.14 * rs * rho_sl);    
dimensionedScalar     drs_dt = -k/(8*rs);   // done

dimensionedScalar     A_lambda_2EHA = 0.00319*Foam::pow(Tb_2EHA,1.2) / ( Foam::pow(1000*MW_2EHA,0.5) * Foam::pow(Tc_2EHA,0.167) );         // done
dimensionedScalar     A_lambda_XYLENE = 0.0035*Foam::pow(Tb_XYLENE,1.2) / ( Foam::pow(1000*MW_XYLENE,0.5) * Foam::pow(Tc_XYLENE,0.167) );  // done

volScalarField        Cp_PRE = (T/T) * UC_Cp;       // done 
volScalarField        Cp_PRE_1 = (T/T) * UC_Cp;       // done 
volScalarField        Cp_2EHA = (T/T) * UC_Cp;      // done
volScalarField        Cp_XYLENE = (T/T) * UC_Cp;    // done
volScalarField        K_PRE = (T/T) * UC_K;         // done
volScalarField        K_PRE_1 = (T/T) * UC_K;         // done
volScalarField        K_2EHA = (T/T) * UC_K;        // done
volScalarField        K_XYLENE = (T/T) * UC_K;      // done

volScalarField        Cp_LIQUID = Y_PRE_L * Cp_PRE + Y_2EHA_L * Cp_2EHA + Y_XYLENE_L * Cp_XYLENE;    // done              
volScalarField        K_LIQUID = Y_PRE_L * K_PRE + Y_2EHA_L * K_2EHA + Y_XYLENE_L * K_XYLENE;        // done
volScalarField        alpha_LIQUID = K_LIQUID/(rho_LIQUID*Cp_LIQUID);  // done
volScalarField        D_LIQUID = alpha_LIQUID / Le_NUM_LIQUID;   // done
 


dimensionedScalar     Hv = eps_PRE*Hv_PRE + eps_XYLENE*Hv_XYLENE + eps_2EHA*Hv_2EHA;   // done
dimensionedScalar     Hc = eps_PRE*Hc_PRE + eps_XYLENE*Hc_XYLENE + eps_2EHA*Hc_2EHA;   // done

volScalarField        Omega = Da_NUM*(D_LIQUID/(ri*ri))*rho_LIQUID*Y_PRE_L*exp(Ar_NUM*(1-Tb_XYLENE/T));   // done


volVectorField        gradT = fvc::grad(T);                      // done
volScalarField        gradTx = gradT.component(vector::X);       // done 

volVectorField       grad_Y_PRE_L  = fvc::grad(Y_PRE_L);    // done
volScalarField       grad_Y_PRE_L_x = grad_Y_PRE_L.component(vector::X);  // done

volVectorField       grad_Y_PRE_L_1  = fvc::grad(Y_PRE_L_1);                    // done
volScalarField       grad_Y_PRE_L_1_x = grad_Y_PRE_L_1.component(vector::X);    // done

volVectorField       grad_Y_2EHA_L  = fvc::grad(Y_2EHA_L);                       // done 
volScalarField       grad_Y_2EHA_L_x = grad_Y_2EHA_L.component(vector::X);       // done

volScalarField        X_PRE_L = (Y_PRE_L/MW_PRE) / (Y_PRE_L/MW_PRE + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);          // done
volScalarField        X_PRE_L_1 = (Y_PRE_L/MW_PRE) / (Y_PRE_L/MW_PRE + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);        // done 
volScalarField        X_2EHA_L = (Y_2EHA_L/MW_2EHA) / (Y_PRE_L/MW_PRE + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);       // done 
volScalarField        X_XYLENE_L = (Y_XYLENE_L/MW_XYLENE) / (Y_PRE_L/MW_PRE + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE); // done  

volScalarField      PHI_XYLENE_L = X_XYLENE_L*VM_XYLENE/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1); // done
volScalarField      PHI_2EHA_L = X_2EHA_L*VM_2EHA/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);   // done
volScalarField      PHI_PRE_L = X_PRE_L*VM_PRE/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);   // done
volScalarField      PHI_PRE_L_1 = X_PRE_L_1*VM_PRE_1/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);    // done   
              
dimensionedScalar     Tf = Ta;   // done
dimensionedScalar     rf = rs * (1 + Le_NUM_GAS_eff * (log(1+Cp_GAS_1*(Tf-Ts)/Hv)/(log(1+Y_O2_Inf/v))));   // done
dimensionedScalar     rf_old = rf;         // done
dimensionedScalar     A_gas = Foam::pow((1+Y_O2_Inf/v),1/Le_NUM_GAS_2)-1;   // done
dimensionedScalar     drf_dt = (rf-rf_old)/runTime.deltaT();       // done
dimensionedScalar     Tf_D2 = (((Cp_GAS_1*(Tinf-Ts) + (Y_O2_Inf/v)*(Hc-Hv)) / (1+Y_O2_Inf/v)) + Cp_GAS_1*Ts) / Cp_GAS_1;   // done
dimensionedScalar     rf_D2 = rs * (1 + (log(1+Cp_GAS_1*(Tf_D2-Ts)/Hv)/(log(1+Y_O2_Inf/v))));       // done
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



