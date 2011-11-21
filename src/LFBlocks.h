#ifndef LFBLOCKS_H
#define LFBLOCKS_H

/**
 * FIFF - Blocknumbers
 */
enum fiffblock_t
{
    block_unknown = 0
    ,block_root = 999 /**< Root block of a file (has not been used so far). */
    ,block_meas = 100 /**< Measurement */
    ,block_meas_info = 101 /**< The information about the acquisition details. */
    ,block_raw_data = 102 /**< Raw data */
    ,block_processed_data = 103 /**< Processed data */
    ,block_evoked = 104 /**< Evoked response data */
    ,block_mcg_ave = 104 /**< Evoked MCG data */
    ,block_aspect = 105 /**< Used within evoked block to include one aspect of evoked responses like standard average, alter nating average, standard error of mean etc. */
    ,block_subject = 106 /**< Subject/patient information. */
    ,block_isotrak = 107 /**< Head digitization data */
    ,block_hpi_meas = 108 /**< HPI measurement */
    ,block_hpi_result = 109 /**< Result of a HPI fitting procedure. */
    ,block_hpi_coil = 110 /**< Data acquired from one HPI coil. */
    ,block_project = 111 /**< Information about the project under which the data were acquired. */
    ,block_continuous_data = 112 /**< Continuous data is processed raw data. */
    ,block_void = 114 /**< Nothing, reserved space, invalidated data etc. */
    ,block_events = 115 /**< Information about the events detected on the trigger channels during data acquisition. */
    ,block_index = 116 /**< An index of file id/file name pairs. */
    ,block_dacq_pars = 117 /**< The acquisition setup parameters. */
    ,block_ref = 118 /**< Reference mechanism. */
    ,block_maxshield_raw_data = 119 /**< Raw data collected with MaxShield system. */
    ,block_maxshield_aspect = 120 /**< Evoked data collected with MaxShield system. */
    ,block_hpi_subsystem = 121 /**< Data about HPI state. */
    ,block_phantom_subsystem = 122 /**< Data about phantom state. */
    ,block_structural_data = 200 /**< One or more volume_data. */
    ,block_volume_data = 201 /**< Volume data, e.g. MRI/CT set, segmentation etc. */
    ,block_volume_slice = 202 /**< Slice of a volume, e.g. MRI/CT image */
    ,block_scenery = 203 /**< A set of related (in DICOM terminology ‘secondary capture’) images like the 3D renderings of the brain surface. */
    ,block_scene = 204 /**< One image of a scenery. */
    ,block_mri_seg = 205 /**< MRI segmentation data */
    ,block_mri_seg_region = 206 /**< Description of one segmented region. */
    ,block_sphere = 300 /**< A spherically symmetric volume conductor description. */
    ,block_bem = 310 /**< A boundary-element model (BEM) description. */
    ,block_bem_surf = 311 /**< Describes one BEM surface. */
    ,block_conductor_model = 312 /**< One or more conductor model descriptions. */
    ,block_xfit_proj = 313 /**< The signal-space projection (SSP) data. */
    ,block_xfit_proj_item = 314 /**< One set of vectors of the SSP data. */
    ,block_xfit_aux = 315 /**< Auxiliary data created by the source modelling program XFit. */
    ,block_bad_channels = 359 /**< Bad channel namelist */
    ,block_vol_info = 400 /**< Volume info */
    ,block_data_correction = 500 /**< Correction was done to data. */
    ,block_channels_decoupler = 501 /**< Cross-talk compensation information. */
    ,block_sss_info = 502 /**< SSS information. */
    ,block_sss_cal_adjust = 503 /**< SSS calibration adjustments. */
    ,block_sss_st_info = 504 /**< Information of the SSST parameters. */
    ,block_sss_bases = 505 /**< SSS basis matrices. */
    ,block_maxshield = 510 /**< MaxShield information. */
    ,block_processing_history = 900 /**< Processing history. Can contain multiple processing_record’s. */
    ,block_processing_record = 901 /**< One processing record. */
};

#endif //LFBLOCKS_H
