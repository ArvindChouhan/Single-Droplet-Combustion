
///////////////////////////////////////////////////////// GAS PHASE CALCULATIONS //////////////////////////////////////////////////////////////////////////
      Ts = UC_temp*T[999];           
      Y_XYLENE_L = 1 - (Y_PRE_L + Y_PRE_L_1 + Y_2EHA_L);
      rho_LIQUID = 1/(Y_XYLENE_L/rho_XYLENE + Y_2EHA_L/rho_2EHA + Y_PRE_L/rho_PRE + Y_PRE_L_1/rho_PRE_1);
             
      Y_PRE_sl = Y_PRE_L[999];
      Y_PRE_1_sl = Y_PRE_L_1[999];
      Y_2EHA_sl = Y_2EHA_L[999];
      Y_XYLENE_sl = Y_XYLENE_L[999];
         
      X_PRE_sl = (Y_PRE_sl/MW_PRE) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);
      X_PRE_1_sl = (Y_PRE_1_sl/MW_PRE_1) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);
      X_2EHA_sl = (Y_2EHA_sl/MW_2EHA) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);
      X_XYLENE_sl = (Y_XYLENE_sl/MW_XYLENE) / (Y_PRE_sl/MW_PRE + Y_PRE_1_sl/MW_PRE_1 + Y_2EHA_sl/MW_2EHA + Y_XYLENE_sl/MW_XYLENE);        
               
      X_PRE_sg = X_PRE_sl * exp((Hv_PRE*MW_PRE/R)*(1/Tb_PRE-1/Ts));
      X_2EHA_sg = X_2EHA_sl * exp((Hv_2EHA*MW_2EHA/R)*(1/Tb_2EHA-1/Ts));
      X_XYLENE_sg = X_XYLENE_sl * exp((Hv_XYLENE*MW_XYLENE/R)*(1/Tb_XYLENE-1/Ts));
      X_H2O_sg = ((15*X_PRE_sg + 5*X_XYLENE_sg + 8*X_2EHA_sg) / (31*X_PRE_sg + 13*X_XYLENE_sg + 16*X_2EHA_sg)) * (1-(X_PRE_sg + X_XYLENE_sg + X_2EHA_sg)); // Considering Pre, xylene and 2EHA forms water
      X_CO2_sg = 1 - (X_PRE_sg + X_XYLENE_sg + X_2EHA_sg + X_H2O_sg); //and CO2 at flame surface which diffuses to the surface in the ratio of mole fractions

      Y_PRE_sg = (X_PRE_sg * MW_PRE)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);
      Y_2EHA_sg = (X_2EHA_sg * MW_2EHA)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);
      Y_XYLENE_sg = (X_XYLENE_sg * MW_XYLENE)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);
      Y_H2O_sg = (X_H2O_sg * MW_H2O)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);
      Y_CO2_sg = (X_CO2_sg * MW_CO2)/(X_PRE_sg * MW_PRE + X_XYLENE_sg * MW_XYLENE + X_2EHA_sg * MW_2EHA + X_H2O_sg * MW_H2O + X_CO2_sg * MW_CO2);
   
      eps_PRE = Y_PRE_sg / (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg); 
      eps_2EHA = Y_2EHA_sg / (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg);
      eps_XYLENE = Y_XYLENE_sg / (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg);
             
      v = eps_PRE * v_PRE + eps_XYLENE * v_XYLENE + eps_2EHA * v_2EHA;
      Bm = ((Y_O2_Inf/v) + (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg)) / (1 - (Y_PRE_sg + Y_XYLENE_sg + Y_2EHA_sg));
            
      #include "Gas_Properties.H"
               
      Le_NUM_GAS_2 = eps_PRE * 1.5 + eps_XYLENE * 1.75 + eps_2EHA * 1.5;            // parametric study
      Le_NUM_GAS_eff = eps_PRE * 0.4 + eps_XYLENE * 0.3 + eps_2EHA * 0.4;           // parametric study
            
      Hv = eps_PRE*Hv_PRE + eps_XYLENE*Hv_XYLENE + eps_2EHA*Hv_2EHA; 
      Hc = eps_PRE*Hc_PRE + eps_XYLENE*Hc_XYLENE + eps_2EHA*Hc_2EHA;  
            
              
//////////////////////////////////////////// Calculating rs    //////////////////////////////////////////////////////////
         
      rho_sl = 1/(Y_PRE_sl/rho_PRE + Y_PRE_1_sl/rho_PRE_1 + Y_2EHA_sl/rho_2EHA + Y_XYLENE_sl/rho_XYLENE);
      M_br = 4 * M_PI * rs * K_GAS_1 * Foam::log(1+Bm) / Cp_GAS_1; 
      rs_old = rs;
      float a = rs_old.value();
      float b = M_br.value();
      float c = runTime.deltaT().value();
      float d = rho_sl.value();
      float LN = Foam::pow((a*a*a - 3*b*c/(4*M_PI*d)),0.333333333);
      rs = LN * UC_space;  
      drs_dt = (rs-rs_old)/runTime.deltaT();
      
      rf_old = rf;   
      A_gas = Foam::pow((1+Y_O2_Inf/v),1/Le_NUM_GAS_2)-1;
      Tf = (Hc - Hv + Cp_GAS_2*Tinf/A_gas + Cp_GAS_1*Ts) / (Cp_GAS_1 + Cp_GAS_2/A_gas); 
  //  Tf = (Hc - Hv + Cp_GAS_2*Tinf*v*Le_NUM_GAS_2/Y_O2_Inf + Cp_GAS_1*Ts) / (Cp_GAS_1 + Cp_GAS_2*v*Le_NUM_GAS_2/Y_O2_Inf);                      // Variable property method
      rf = rs * (1 + Le_NUM_GAS_eff * (log(1+Cp_GAS_1*(Tf-Ts)/Hv)/(log(1+Y_O2_Inf/v))));
     
      Tf_D2 = (((Cp_GAS_1*(Tinf-Ts) + (Y_O2_Inf/v)*(Hc-Hv)) / (1+Y_O2_Inf/v)) + Cp_GAS_1*Ts) / Cp_GAS_1;
      rf_D2 = rs * (1 + (log(1+Cp_GAS_1*(Tf_D2-Ts)/Hv)/(log(1+Y_O2_Inf/v))));  
                  
      drf_dt = (rf-rf_old)/runTime.deltaT(); 
///////////////////////////////////////////////// DROPLET and LIQUID Properties ////////////////////////////////////////////////

 
      A_lambda_XYLENE = 0.0035*Foam::pow(Tb_XYLENE,1.2) / ( Foam::pow(1000*MW_XYLENE,0.5) * Foam::pow(Tc_XYLENE,0.167) );
      A_lambda_2EHA = 0.00319*Foam::pow(Tb_2EHA,1.2) / ( Foam::pow(1000*MW_2EHA,0.5) * Foam::pow(Tc_2EHA,0.167) );              

      forAll(mesh.C(), i)
        {
          Cp_XYLENE[i] = (R.value()/MW_XYLENE.value()) * (26.3916 - 7.7335*T[i]/100 + 2.8289*	(T[i]/100)*(T[i]/100));   
          Cp_2EHA[i] = (R.value()/MW_2EHA.value()) * (20.1095 + 3.2995*T[i]/100 + 0.9810*(T[i]/100)*(T[i]/100));                
          K_XYLENE[i] = A_lambda_XYLENE.value() * Foam::pow( (1- T[i]/Tc_XYLENE.value()), 0.38) / ( Foam::pow( T[i]/Tc_XYLENE.value(), 1/6) );
          K_2EHA[i] = A_lambda_2EHA.value() * Foam::pow( (1- T[i]/Tc_2EHA.value()), 0.38) / ( Foam::pow( T[i]/Tc_2EHA.value(), 1/6) );
        } 
    
      Cp_PRE = Cp_2EHA;
      Cp_PRE_1 = Cp_2EHA;
      K_PRE = K_2EHA;
      K_PRE_1 = K_2EHA;  
        
      rho_LIQUID = 1/(Y_XYLENE_L/rho_XYLENE + Y_2EHA_L/rho_2EHA + Y_PRE_L/rho_PRE + Y_PRE_L_1/rho_PRE_1);                // Ren supplementary
   
      X_PRE_L = (Y_PRE_L/MW_PRE) / (Y_PRE_L/MW_PRE + Y_PRE_L_1/MW_PRE_1 + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);
      X_PRE_L_1 = (Y_PRE_L_1/MW_PRE_1) / (Y_PRE_L/MW_PRE + Y_PRE_L_1/MW_PRE_1 + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);
      X_2EHA_L = (Y_2EHA_L/MW_2EHA) / (Y_PRE_L/MW_PRE + Y_PRE_L_1/MW_PRE_1 + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);
      X_XYLENE_L = (Y_XYLENE_L/MW_XYLENE) / (Y_PRE_L/MW_PRE + Y_PRE_L_1/MW_PRE_1 + Y_2EHA_L/MW_2EHA + Y_XYLENE_L/MW_XYLENE);
      
      Cp_LIQUID = X_PRE_L * Cp_PRE + X_PRE_L_1 * Cp_PRE_1 + X_2EHA_L * Cp_2EHA + X_XYLENE_L * Cp_XYLENE;                 // Rosebrock 
      
    /*  PHI_XYLENE_L = X_XYLENE_L*VM_XYLENE/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE);
      PHI_2EHA_L = X_2EHA_L*VM_2EHA/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE);
      PHI_PRE_L = X_PRE_L*VM_PRE/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE);      
      K_LIQUID = PHI_XYLENE_L*PHI_XYLENE_L*2*K_XYLENE*K_XYLENE/(K_XYLENE+K_XYLENE) + 
                       PHI_XYLENE_L*PHI_2EHA_L*2*K_XYLENE*K_2EHA/(K_XYLENE+K_2EHA) + 
                       PHI_XYLENE_L*PHI_PRE_L*2*K_XYLENE*K_PRE/(K_XYLENE+K_PRE) + 
                       PHI_2EHA_L*PHI_XYLENE_L*2*K_2EHA*K_XYLENE/(K_2EHA+K_XYLENE) + 
                       PHI_2EHA_L*PHI_2EHA_L*2*K_2EHA*K_2EHA/(K_2EHA+K_2EHA) + 
                       PHI_2EHA_L*PHI_PRE_L*2*K_2EHA*K_PRE/(K_2EHA+K_PRE) +
                       PHI_PRE_L*PHI_XYLENE_L*2*K_PRE*K_XYLENE/(K_PRE+K_XYLENE) + 
                       PHI_PRE_L*PHI_2EHA_L*2*K_PRE*K_2EHA/(K_PRE+K_2EHA) + 
                       PHI_PRE_L*PHI_PRE_L*2*K_PRE*K_PRE/(K_PRE+K_PRE) ;        */                     // Rosebrock
      
      PHI_XYLENE_L = X_XYLENE_L*VM_XYLENE/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);
      PHI_2EHA_L = X_2EHA_L*VM_2EHA/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);
      PHI_PRE_L = X_PRE_L*VM_PRE/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);
      PHI_PRE_L_1 = X_PRE_L_1*VM_PRE_1/(X_XYLENE_L*VM_XYLENE + X_2EHA_L*VM_2EHA + X_PRE_L*VM_PRE + X_PRE_L_1*VM_PRE_1);      
     
      K_LIQUID = PHI_XYLENE_L*PHI_XYLENE_L*2*K_XYLENE*K_XYLENE/(K_XYLENE+K_XYLENE) + 
                       PHI_XYLENE_L*PHI_2EHA_L*2*K_XYLENE*K_2EHA/(K_XYLENE+K_2EHA) + 
                       PHI_XYLENE_L*PHI_PRE_L*2*K_XYLENE*K_PRE/(K_XYLENE+K_PRE) + 
                       PHI_XYLENE_L*PHI_PRE_L_1*2*K_XYLENE*K_PRE_1/(K_XYLENE+K_PRE_1) +
                       PHI_2EHA_L*PHI_XYLENE_L*2*K_2EHA*K_XYLENE/(K_2EHA+K_XYLENE) + 
                       PHI_2EHA_L*PHI_2EHA_L*2*K_2EHA*K_2EHA/(K_2EHA+K_2EHA) + 
                       PHI_2EHA_L*PHI_PRE_L*2*K_2EHA*K_PRE/(K_2EHA+K_PRE) +
                       PHI_2EHA_L*PHI_PRE_L_1*2*K_2EHA*K_PRE_1/(K_2EHA+K_PRE_1) +
                       PHI_PRE_L*PHI_XYLENE_L*2*K_PRE*K_XYLENE/(K_PRE+K_XYLENE) + 
                       PHI_PRE_L*PHI_2EHA_L*2*K_PRE*K_2EHA/(K_PRE+K_2EHA) + 
                       PHI_PRE_L*PHI_PRE_L*2*K_PRE*K_PRE/(K_PRE+K_PRE) +
                       PHI_PRE_L*PHI_PRE_L_1*2*K_PRE*K_PRE_1/(K_PRE+K_PRE_1) +
                       PHI_PRE_L_1*PHI_XYLENE_L*2*K_PRE_1*K_XYLENE/(K_PRE_1+K_XYLENE) + 
                       PHI_PRE_L_1*PHI_2EHA_L*2*K_PRE_1*K_2EHA/(K_PRE_1+K_2EHA) + 
                       PHI_PRE_L_1*PHI_PRE_L*2*K_PRE_1*K_PRE/(K_PRE_1+K_PRE) +
                       PHI_PRE_L_1*PHI_PRE_L_1*2*K_PRE_1*K_PRE_1/(K_PRE_1+K_PRE_1); 
      
      alpha_LIQUID = K_LIQUID/(rho_LIQUID*Cp_LIQUID);
      D_LIQUID = alpha_LIQUID / Le_NUM_LIQUID;
             
      Omega = Da_NUM*(D_LIQUID/(ri*ri))*rho_LIQUID*Y_PRE_L*exp(Ar_NUM*(1-Tb_XYLENE/T));
                             
//////////////////////////////////////////// Temperature BC /////////////////////////////////////////////////////////

      T_BC = ((Cp_GAS_1*(Tinf - Ts) + Y_O2_Inf*Hc/v) * Foam::log(1+Bm)*K_GAS_1) / (Cp_GAS_1*Bm*K_LIQUID[999]*UC_K);
      T_BC = T_BC - Hv * Foam::log(1+Bm) * K_GAS_1 / (Cp_GAS_1 * K_LIQUID[999]*UC_K) ;                      

//////////////////////////////////////////// Species BC /////////////////////////////////////////////////////////
     
      Y_PRE_L_BC = M_br * (Y_PRE_sl-eps_PRE) /(4 *3.14*rho_LIQUID[999]*UC_rho*rs* D_LIQUID[999]*UC_D);
      Y_2EHA_L_BC = M_br * (Y_2EHA_sl-eps_2EHA) /(4 *3.14*rho_LIQUID[999]*UC_rho*rs* D_LIQUID[999]*UC_D);
      


                  
 
