   
            

            gradT  = fvc::grad(T);
            gradTx = gradT.component(vector::X);
            x      = mesh.C().component(vector::X);     

            fvScalarMatrix TEqn
            (
                fvm::ddt(T)
              - (rs*drs_dt*x/(rs*rs)) * gradTx
              - (UC_space*UC_space*2*alpha_LIQUID/(rs*rs*x) )* gradTx
              
             ==
                UC_space*UC_space*(alpha_LIQUID/(rs*rs))*fvm::laplacian(T)
            );

            TEqn.solve();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              
            grad_Y_PRE_L  = fvc::grad(Y_PRE_L);
            grad_Y_PRE_L_x = grad_Y_PRE_L.component(vector::X);
            
            fvScalarMatrix Y_PRE_LEqn
            (
                fvm::ddt(Y_PRE_L)
              - (rs*drs_dt*x/(rs*rs)) * grad_Y_PRE_L_x
              - (UC_space*UC_space*2*D_LIQUID/(rs*rs*x) )* grad_Y_PRE_L_x
             ==
                UC_space*UC_space*(D_LIQUID/(rs*rs))*fvm::laplacian(Y_PRE_L)
              - Omega/rho_LIQUID
            );
            Y_PRE_LEqn.solve();     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            
            
            
            grad_Y_PRE_L_1  = fvc::grad(Y_PRE_L_1);
            grad_Y_PRE_L_1_x = grad_Y_PRE_L_1.component(vector::X);
            
            fvScalarMatrix Y_PRE_L_1Eqn
            (
                fvm::ddt(Y_PRE_L_1)
              - (rs*drs_dt*x/(rs*rs)) * grad_Y_PRE_L_1_x
              - (UC_space*UC_space*2*D_LIQUID/(rs*rs*x) )* grad_Y_PRE_L_1_x
             ==
                UC_space*UC_space*(D_LIQUID/(rs*rs))*fvm::laplacian(Y_PRE_L_1)
              + (MW_PRE_1/MW_PRE)*(Omega/rho_LIQUID)
            );
            Y_PRE_L_1Eqn.solve();     

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            grad_Y_2EHA_L  = fvc::grad(Y_2EHA_L);
            grad_Y_2EHA_L_x = grad_Y_2EHA_L.component(vector::X);
            
            fvScalarMatrix Y_2EHA_LEqn
            (
                fvm::ddt(Y_2EHA_L)
              - (rs*drs_dt*x/(rs*rs)) * grad_Y_2EHA_L_x
              - (UC_space*UC_space*2*D_LIQUID/(rs*rs*x) )* grad_Y_2EHA_L_x
              
             ==
                UC_space*UC_space*(D_LIQUID/(rs*rs))*fvm::laplacian(Y_2EHA_L)
              + (MW_2EHA/MW_PRE)*(Omega/rho_LIQUID)
            );

            Y_2EHA_LEqn.solve();  

            Y_XYLENE_L = 1 - (Y_PRE_L + Y_PRE_L_1 + Y_2EHA_L);     

      














            
