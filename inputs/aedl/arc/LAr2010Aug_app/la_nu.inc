$version="3.0.0"
/* Cross sections */
include "./LAINPUT/cross_sections.inc"

/* ----------------------------------------------------------------- */
/*             Detector properties : Liquid Argon                    */
/* ----------------------------------------------------------------- */

/* Binning */
/* $emin =                 0.5 */
/*$emax =                20.0 */
/*$bins =               150 */

/*$sampling_min =        0.5 */
/*$sampling_max =       20.0 */

$emin =                 0.5
$emax =                 60.0
$binsize= {0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125,0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125,0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125,0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4}


$sampling_min =                 0.5
$sampling_max =                 60.0
$sampling_stepsize= {0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125,0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125,0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125,0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 
0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 2, 2, 2, 2, 2, 2, 2, 
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

/* Technical information */
$filter_state = 0
$filter_value = 0.125


/* Energy Resolution */

energy(#mucc)<
        @type = 1
        @sigma_e = {0.0,0.15,0.0}
>

energy(#muqe)<
        @type = 1
        @sigma_e = {0.0,0.05,0.0}
>

energy(#elec)<
        @type = 1
        @sigma_e = {0.0,0.15,0.0}
>

energy(#hadr)<
        @type = 1
        @sigma_e = {0.0,0.40,0.0}
>

energy(#nc)<>
include "./LAINPUT/nc_smear_nu_ereco.dat"

/* ----------------------------------------------------------------- */
/*                                Channels                           */
/* ----------------------------------------------------------------- */


channel(#nu_mu_cc)<
        @channel =      #fnal_plus:     +:      m:      m:      #CC:    #mucc
>

channel(#nu_mu_qe)<
        @channel =      #fnal_plus:     +:      m:      m:      #QE:    #muqe
>

channel(#nu_mu_nc)<
        @channel =      #fnal_plus:     +:      m:  NOSC_m:      #NC:    #nc
		@pre_smearing_efficiencies ={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
         	 1, 1, 1, 1, 1, 1}

        @post_smearing_efficiencies ={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	     1, 1, 1, 1, 1}

>

channel(#nu_e_beam)<
        @channel =      #fnal_plus:     +:      e:      e:      #CC:    #elec
>

channel(#nu_e_bar_beam)<
        @channel =      #fnal_plus:     -:      e:      e:      #CC:    #elec
>

channel(#nu_e_sig)<
        @channel =      #fnal_plus:     +:      m:      e:      #CC:    #elec
>


/* ----------------------------------------------------------------- */
/*                    Rules for a Liquid Argon Detector              */
/* ----------------------------------------------------------------- */

/* CC */
rule(#nu_e_appearance)<
        @signal = 0.80@#nu_e_sig
        @signalerror = 0.01 : 0.0001
        @background =  0.01@#nu_mu_cc  : 0.80@#nu_e_beam : 0.01@#nu_mu_nc 
        @backgrounderror = 0.05 : 0.0001
        @sys_on_function = "chiSpectrumTilt"
        @sys_off_function = "chiNoSysSpectrum"
>

rule(#nu_mu_disappearance)<
        @signal = 1.0@#nu_mu_cc
        @signalerror = 0.01 : 0.0001
        @background = 0.02@#nu_mu_nc
        @backgrounderror = 0.01 : 0.0001
        @sys_on_function = "chiSpectrumTilt"
        @sys_off_function = "chiNoSysSpectrum"
>
