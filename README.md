
## 🔥 OpenFOAM Project: Single Droplet Combustion (Precursor and Fuel Droplets)

### **Overview**

This repository contains the custom OpenFOAM solver **`SDCFoam_PRE_EHA_XYL_FLAME_Paper_Revised`** and its associated tutorial case.

The solver is developed using the foundation of OpenFOAM, with **all governing equations written manually** to allow for complex, coupled physics. It is specifically designed for simulating the combustion (burning) of:

  * **Pure fuel droplets** (e.g., Xylene, 2-EHA).
  * **Precursor droplets** (e.g., Sn-2EHA + Xylene).

-----

### **Solver Details**

  * **Solver Name:** `SDCFoam_PRE_EHA_XYL_FLAME_Paper_Revised`
  * **Base Solver:** Custom (built from scratch, not a modification of a standard utility).
  * **OpenFOAM Version:** This project was developed and tested using **OpenFOAM-v2006**. Compatibility with other versions is not guaranteed.
  * **Key Features/Modifications:**
      * Manual implementation of all conservation equations (mass, momentum, energy, species).
      * Handles multiple species phases (liquid fuel/precursor, decomposition products, and gas phase).
      * Solves for specific liquid-phase species mass fractions, including:
          * Y_PRE_L (Precursor)
          * Y_XYLENE_L (Xylene)
          * Y_2EHA_L (Decomposition product - 2EHA)
          * Y_PRE_L_1 (Decomposition product)

-----

### **Getting Started**

#### **1. Prerequisites**

  * A working installation of **OpenFOAM-v2006** on your system.
  * A C++ compiler (usually GCC).

#### **2. Compiling the Solver**

1.  **Navigate** to the solver directory (where `SDCFoam_PRE_EHA_XYL_FLAME_Paper_Revised.C` and the `Make` directory are located):
    ```bash
    cd [Path/to/SDCFoam_PRE_EHA_XYL_FLAME_Paper_Revised_Directory]
    ```
2.  Use the `wmake` command to compile the solver executable:
    ```bash
    wmake
    ```
      * **Note:** The compiled executable, `SDCFoam_PRE_EHA_XYL_FLAME_Paper_Revised`, will be placed in your `$FOAM_USER_APPBIN` directory.

-----

### **Running the Simulation Case**

The tutorial case, **`Case`**, is provided for immediate testing.

#### **1. Configuration for Single Fuel Droplets**

To run the solver for a **single, pure fuel** (and not a precursor mixture):

1.  **Initial Concentration:** In the `Case/0/` folder, set the appropriate initial concentration of the desired fuel, e.g., Y_XYLENE_L to 1, and **set all other species concentrations to 0**.
2.  **Lewis Numbers ($\text{Le}$):** The Lewis numbers, Le_2 and Le_eff, can be controlled in two ways:
      * **Option A: Transport Properties File:** Change the values directly in the `Case/constant/transport_properties` file. <img width="693" height="135" alt="image" src="https://github.com/user-attachments/assets/42ed987d-fc38-4c96-a49d-edbdd94c5a70" />

      * **Option B: Solver Source Code:** Modify the macro definitions **`Le_NUM_GAS_2`** and **`Le_NUM_GAS_eff`** within the solver's source code, specifically in the **`Properties.H`** file. You must recompile the solver (`wmake`) after changing these values in the source code. <img width="1277" height="47" alt="image" src="https://github.com/user-attachments/assets/3b4bfa36-3658-4d66-ad1e-e36db3ef9487" />


#### **2. Specifying Fluid Properties**

The physical and transport properties for all involved species are defined in:

  * **File location:** `Case/constant/transport_properties`

#### **3. Running the Case**

1.  **Navigate** to the case directory:
    ```bash
    cd [Path/to/Case]/Case
    ```
2.  **Generate the mesh** (if necessary, check for `blockMeshDict`):
    ```bash
    blockMesh
    ```
3.  **Run the simulation** (Serial):
    ```bash
    SDCFoam_PRE_EHA_XYL_FLAME_Paper_Revised
    ```

-----

### **Post-processing**

After the simulation is complete, you can visualize the results:

1.  Open the case in **ParaView**:
    ```bash
    paraFoam
    ```
2.  If the simulation was run in parallel, you may need to **reconstruct the fields** before visualization:
    ```bash
    reconstructPar
    ```
