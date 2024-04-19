#!/bin/bash

###
### NOvA CV
###

#NOM_DIR="/Users/vmikola/Downloads"
#NOM_DIR="/vols/t2k/users/ea2817/build/T2K_NOvA/FakeDataStudies/SK_inputs_bugfix/Asimov4/post_BANFF"
#FHC_NOM_NAME="${NOM_DIR}/SK_plots_T2K_NOvA_post-BANFF_Asimov4_FHC_spectra.root"
#RHC_NOM_NAME="${NOM_DIR}/SK_plots_T2K_NOvA_post-BANFF_Asimov4_RHC_spectra.root"
#COMP_LABEL="post-BANFF"

FDS_DIR="/Users/vmikola/Downloads"
#FDS_DIR="/vols/t2k/users/ea2817/build/T2K_NOvA/FakeDataStudies/SK_inputs_Q2_at_one/Asimov4/CRPA"
#FHC_FDS_NAME="${FDS_DIR}/SK_plots_T2K_NOvA_CRPA_Asimov4_FHC.root"
#RHC_FDS_NAME="${FDS_DIR}/SK_plots_T2K_NOvA_CRPA_Asimov4_RHC.root"

FHC_FDS_NAME="${FDS_DIR}/SK_plots_T2K_NOvA_FDS_CRPA_Asimov4_Q2_pars_at_one_combined.root"
#FHC_FDS_NAME="${FDS_DIR}/SK_plots_T2K_NOvA_FDS_CRPA_Asimov1_Q2_pars_at_one_combined.root"
FDS_LABEL="CRPA FDS"

#POS_PRED_FILE="/Users/vmikola/Downloads/CRPA-Asimov1-T2K-PostPred_noSK_fixed.root"
POS_PRED_FILE="/Users/vmikola/Downloads/CRPA-Asimov4-T2K-PostPred_noSK.root"
POSPRED_LABEL="Fit to FDS"
OUTNAME="CRPA_comp_Asimov4_T2KNOvA_posPred_FDS_fit_withratio"

#eval "root -l -b -q 'SK_FDS_comp_pos_pred_overlay.C(\"${FHC_FDS_NAME}\", \"${RHC_FDS_NAME}\", \"${FDS_LABEL}\", \"${FHC_NOM_NAME}\", \"${RHC_NOM_NAME}\", \"${POS_PRED_FILE}\", \"${COMP_LABEL}\", \"${OUTNAME}\", \"${POSPRED_LABEL}\", false)'"

eval "root -l -b -q 'SK_FDS_comp_pos_pred_overlay.C(\"${FHC_FDS_NAME}\", \"${FDS_LABEL}\", \"${POS_PRED_FILE}\", \"${COMP_LABEL}\", \"${OUTNAME}\", \"${POSPRED_LABEL}\", false)'"
