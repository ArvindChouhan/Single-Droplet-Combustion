

   float A_EHA_k = -5.052188005541947e-18;
   float B_EHA_k = 4.691699589460685e-12;
   float C_EHA_k = 8.80261942935515e-08;
   float D_EHA_k = -1.9280893241020242e-07;
   float E_EHA_k = 1.5442349029517487e-07;

   //Fit Params heat capacity
   float A_EHA_cp = -1.4421564212985837e-13;
   float B_EHA_cp = 1.1639081608198099e-09;
   float C_EHA_cp = -3.6672980224785963e-06;
   float D_EHA_cp = 0.00574324984641248;
   float E_EHA_cp = 0.012135766139848228;


   Tref_GAS_1 = 0.66*Ts + 0.33*Tf;
 //  K_2EHA_GAS_1 = (1e-7*Tref_GAS_1.value()*Tref_GAS_1.value() + 1e-5*Tref_GAS_1.value() + 0.0031) * UC_K;             
   K_2EHA_GAS_1 = (A_EHA_k*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + B_EHA_k*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + C_EHA_k*Tref_GAS_1.value()*Tref_GAS_1.value() + D_EHA_k*Tref_GAS_1.value() + E_EHA_k) * UC_K;
   K_XYLENE_GAS_1 = (1e-7*Tref_GAS_1.value()*Tref_GAS_1.value() - 8e-6*Tref_GAS_1.value() + 0.0102) * UC_K;
   K_PRE_GAS_1 = (A_EHA_k*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + B_EHA_k*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + C_EHA_k*Tref_GAS_1.value()*Tref_GAS_1.value() + D_EHA_k*Tref_GAS_1.value() + E_EHA_k) * UC_K;                  // 2EHA
   K_CO2_GAS_1 = (-3e-8*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0001*Tref_GAS_1.value() - 0.0155) * UC_K;
   K_H2O_GAS_1 = (3e-8*Tref_GAS_1.value()*Tref_GAS_1.value() + 8e-5*Tref_GAS_1.value() - 0.0107) * UC_K;

 //  Cp_2EHA_GAS_1 = 1000*(-1e-6*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0035*Tref_GAS_1.value() + 0.6088) * UC_Cp; 
   Cp_2EHA_GAS_1 = 1000*(A_EHA_cp*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + B_EHA_cp*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + C_EHA_cp*Tref_GAS_1.value()*Tref_GAS_1.value() + D_EHA_cp*Tref_GAS_1.value() + E_EHA_cp) * UC_Cp;
   Cp_XYLENE_GAS_1 = 1000*(-1e-6*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0037*Tref_GAS_1.value() + 0.3522) * UC_Cp;
   Cp_PRE_GAS_1 = 1000*(A_EHA_cp*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + B_EHA_cp*Tref_GAS_1.value()*Tref_GAS_1.value()*Tref_GAS_1.value() + C_EHA_cp*Tref_GAS_1.value()*Tref_GAS_1.value() + D_EHA_cp*Tref_GAS_1.value() + E_EHA_cp) * UC_Cp;        // 2EHA
   Cp_CO2_GAS_1 = 1000*(-2e-7*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0007*Tref_GAS_1.value() + 0.7084) * UC_Cp;
   Cp_H2O_GAS_1 = 1000*(-3e-8*Tref_GAS_1.value()*Tref_GAS_1.value() + 0.0007*Tref_GAS_1.value() + 1.5906) * UC_Cp;
   
   X_REF_2EHA_GAS_1 = 0.66*X_2EHA_sg;                // taking mole fractions of ETH at flame 0                                                                                       
   X_REF_XYLENE_GAS_1 = 0.66*X_XYLENE_sg;            // taking mole fractions of XYLENE at flame 0 
   X_REF_PRE_GAS_1 = 0.66*X_PRE_sg;
   X_REF_CO2_GAS_1 = 0.66*X_CO2_sg + 0.33*(16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)/(31*X_PRE_sg+13*X_XYLENE_sg+16*X_2EHA_sg);
   X_REF_H2O_GAS_1 = 0.66*X_H2O_sg + 0.33*(15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)/(31*X_PRE_sg+13*X_XYLENE_sg+16*X_2EHA_sg);
   
   Y_REF_2EHA_GAS_1 = 0.66*Y_2EHA_sg;                 // taking Mass fractions of ETH at flame 0 
   Y_REF_XYLENE_GAS_1 = 0.66*Y_XYLENE_sg;           // taking Mass fractions of Xylene at flame 0
   Y_REF_PRE_GAS_1 = 0.66*Y_PRE_sg;
   Y_REF_CO2_GAS_1 = 0.66*Y_CO2_sg + 0.33*((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);
   Y_REF_H2O_GAS_1 = 0.66*Y_H2O_sg + 0.33*((15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);
   
   K_GAS_1 = 0.5*(X_REF_PRE_GAS_1*K_PRE_GAS_1+X_REF_XYLENE_GAS_1*K_XYLENE_GAS_1+X_REF_2EHA_GAS_1*K_2EHA_GAS_1+X_REF_CO2_GAS_1*K_CO2_GAS_1+X_REF_H2O_GAS_1*K_H2O_GAS_1) + 0.5*(1/(X_REF_PRE_GAS_1/K_PRE_GAS_1+X_REF_XYLENE_GAS_1/K_XYLENE_GAS_1+X_REF_2EHA_GAS_1/K_2EHA_GAS_1+X_REF_CO2_GAS_1/K_CO2_GAS_1+X_REF_H2O_GAS_1/K_H2O_GAS_1));  // Ren supplementary
   Cp_GAS_1 = Y_REF_PRE_GAS_1*Cp_PRE_GAS_1+Y_REF_XYLENE_GAS_1*Cp_XYLENE_GAS_1+Y_REF_2EHA_GAS_1*Cp_2EHA_GAS_1+Y_REF_CO2_GAS_1*Cp_CO2_GAS_1+Y_REF_H2O_GAS_1*Cp_H2O_GAS_1;  // Ren supplementary
   
   Tref_GAS_2 = 0.33*Tf + 0.66*Tinf;
   Cp_CO2_GAS_2 = 1000*(-2e-7*Tref_GAS_2.value()*Tref_GAS_2.value() + 0.0007*Tref_GAS_2.value() + 0.7084) * UC_Cp;
   Cp_H2O_GAS_2 = 1000*(-3e-8*Tref_GAS_2.value()*Tref_GAS_2.value() + 0.0007*Tref_GAS_2.value() + 1.5906) * UC_Cp;
   Cp_O2_GAS_2 = 1000*(-5e-8*Tref_GAS_2.value()*Tref_GAS_2.value() + 0.0003*Tref_GAS_2.value() + 0.8558) * UC_Cp;
   Y_REF_CO2_GAS_2 = 0.33*((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);      // taking mass fraction of Co2 at inifinite 0
   Y_REF_H2O_GAS_2 = 0.33*((15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2) / ((16*X_PRE_sg+8*X_XYLENE_sg+8*X_2EHA_sg)*MW_CO2 + (15*X_PRE_sg+5*X_XYLENE_sg+8*X_2EHA_sg)*MW_H2O);      // taking mass fraction of H2O at inifinite 0 
   Y_REF_O2_GAS_2 = 0.66*1;
   Cp_GAS_2 = Y_REF_CO2_GAS_2*Cp_CO2_GAS_2 + Y_REF_H2O_GAS_2*Cp_H2O_GAS_2 + Y_REF_O2_GAS_2*Cp_O2_GAS_2;
   
  
