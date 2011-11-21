#ifndef LFTAGS_H
#define LFTAGS_H
/**
 * FIFF - Tags
 */
enum fifftag_t
{
    tag_new_file = 1 /**< Type==void - New file should be started. */
    ,tag_close_file = 2 /**< Type==void - Done, close the file being saved. */
    ,tag_discard_file = 3 /**< Type==void - Done, discard the file being saved. */
    ,tag_error_message = 4 /**< Type==string - Acquisition error notifier. */
    ,tag_suspend_readin = 5 /**< Type==void - Transmission stops temporarily. */
    ,tag_fatal_error_mes = 6 /**< Type==string - Fatal acquisition error notifier. */
    ,tag_connection_che = 7 /**< Type==void - Dummy object for testing transmission. */
    ,tag_suspend_filing = 8 /**< Type==void - Stop filing data command. */
    ,tag_resume_filing = 9 /**< Type==void - Start filing data command. */
    ,tag_raw_prebase = 10 /**< Type==int32, unit==card - Prebase length (in buffers) change request. */
    ,tag_raw_pick_list = 11 /**< Type==int32* - Channel order in data. */
    ,tag_echo = 12 /**< Type==void - Channel probe, response expected. */
    ,tag_resume_reading = 13 /**< Type==void - Suspended transmission continues. */
    ,tag_dacq_system_ty = 14 /**< Type==enum(dacq_system) - Type of the acquitition system. */
    ,tag_select_raw_ch = 15 /**< Type==string - Instruct rawdisp to select this channel. */
    ,tag_playback_mode = 16 /**< Type==void - Data are being played back from the hard disks. */
    ,tag_continue_file = 17 /**< Type==string - Used to inform that data is saved into a continuation file. */
    ,tag_jitter_max = 18 /**< Type==float, Maximum jitter in data communication blocks (seconds) */
    ,tag_stream_segment = 19 /**< Type==int32 - Data stream segment */
    ,tag_file_id = 100 /**< Type==id1.1 - Id of the file */
    ,tag_dir_pointer = 101 /**< Type==int32 - Pointer to directory */
    ,tag_dir = 102 /**< Type==int32 - Tag directory */
    ,tag_block_id = 103 /**< Type==id1.1 - Id of a block */
    ,tag_block_start = 104 /**< Type==int32 enum - Start of a composite object (block) */
    ,tag_block_end = 105 /**< Type==int32 enum - End if composite object (block) */
    ,tag_free_list = 106 /**< Type==int32 ord - Pointer to fre block list. */
    ,tag_free_block = 107 /**< Type==void - Unused space */
    ,tag_nop = 108 /**< Type==void - Reserved space */
    ,tag_parent_file_id = 109 /**< Type==id1.1 - Id of the file from which this was generated */
    ,tag_parent_block_id = 110 /**< Type==id1.1 - Id of a block from which this data is derived from */
    ,tag_block_name = 111 /**< Type==string - Name of a block */
    ,tag_block_version = 112 /**< Type==string - Version number of the block format of this block */
    ,tag_creator = 113 /**< Type==string - Program that created the file (string) */
    ,tag_modifier = 114 /**< Type==string - Program that modified the file (string) */
    ,tag_ref_role = 115 /**< Type==enum(role) - What is the role of this reference */
    ,tag_ref_file_id = 116 /**< Type==id1.1 - File id of the referenced object */
    ,tag_ref_file_num = 117 /**< Type==int32 ord File number of the referenced file */
    ,tag_ref_file_name = 118 /**< Type==string - Name hint for the refereced file */
    ,tag_ref_block_id = 120 /**< Type==id1.1 - Id of a referenced block */
    ,tag_dacq_pars = 150 /**< Type==string - Megacq saves the parameters in these */
    ,tag_dacq_stim = 151 /**< Type==string - Megacq saves stimulus parameters in these */
    ,tag_nchan = 200 /**< Type==int32 card Number of channels */
    ,tag_sfreq = 201 /**< Type==float Hz Sampling frequency (Hz) */
    ,tag_data_pack = 202 /**< Type==int32 ord How the raw data is packed */
    ,tag_ch_info = 203 /**< Type==ch_info_rec - Channel descriptor */
    ,tag_meas_date = 204 /**< Type==int32 uxtime Measurement date (in Unix time encoding) */
    ,tag_subject = 205 /**< Type==string - <obsolete> */
    ,tag_description = 206 /**< Type==string - (Textual) Description of an object */
    ,tag_nave = 207 /**< Type==int32 card Number of averages */
    ,tag_first_sample = 208 /**< Type==int32 ord The first sample of an epoch */
    ,tag_last_sample = 209 /**< Type==int32 ord The last sample of an epoch */
    ,tag_aspect_kind = 210 /**< Type==enum(aspect) - Aspect label */
    ,tag_ref_event = 211 /**< Type==int32 ord Reference event */
    ,tag_experimenter = 212 /**< Type==string - Experimenter name */
    ,tag_dig_point = 213 /**< Type==dig_point m Digitization point */
    ,tag_ch_pos_vec = 214 /**< Type==ch_pos_rec - Channel positions (obsolete) */
    ,tag_hpi_slopes = 215 /**< Type==float* T,T/m HPI data */
    ,tag_hpi_ncoil = 216 /**< Type==int32 card Number of HPI coils */
    ,tag_req_event = 217 /**< Type==int32 ord Required event */
    ,tag_req_limit = 218 /**< Type==float s Window for required event */
    ,tag_lowpass = 219 /**< Type==float Hz Analog lowpass */
    ,tag_bad_chs = 220 /**< Type==int32* ord List of bad channels */
    ,tag_artef_removal = 221 /**< Type==int32 ord Artefact removal */
    ,tag_coord_trans = 222 /**< Type==coor_trans_rec - Coordinate transformation */
    ,tag_highpass = 223 /**< Type==float Hz Analog highpass */
    ,tag_ch_cals_vec = 224 /**< Type==float* rel Channel calibration (obsolete) */
    ,tag_hpi_bad_chs = 225 /**< Type==int32* ord List of channels considered to be bad in hpi */
    ,tag_hpi_corr_coeff = 226 /**< Type==float* rel Hpi curve fit correlations */
    ,tag_event_comment = 227 /**< Type==string - Comment about the events used in averaging */
    ,tag_no_samples = 228 /**< Type==int32 card - Number of samples in an epoch */
    ,tag_first_time = 229 /**< Type==float s Time scale minimum */
    ,tag_subave_size = 230 /**< Type==int32 card Size of a subaverage */
    ,tag_subave_first = 231 /**< Type==int32 ord The first epoch */
    ,tag_name = 233 /**< Type==string - Intended to be a short name */
    ,tag_dig_string = 234 /**< Type==dig_string - String of digitized points */
    ,tag_line_freq = 235 /**< Type==float Hz Basic line interference frequency */
    ,tag_hpi_coil_freq = 236 /**< Type==float Hz HPI coil excitation frequency */
    ,tag_signal_channel = 237 /**< Type==string - Signal channel name */
    ,tag_hpi_coil_moments = 240 /**< Type==float T/m Estimated moment vectors for the HPI coil magnetic dipoles */
    ,tag_hpi_fit_goodness = 241 /**< Type==float % Three floats indicating the goodness of fit */
    ,tag_hpi_fit_accept = 242 /**< Type==bit-mask(hpi_accept) - Bitmask indicating acceptance (see enum hpi_accept) */
    ,tag_hpi_fit_good_limit = 243 /**< Type==float % Limit for the goodness-of-fit */
    ,tag_hpi_fit_dist_limit = 244 /**< Type==float m Limit for the coil distance difference */
    ,tag_hpi_coil_no = 245 /**< Type==int32 ord Coil number listed by HPI measurement */
    ,tag_hpi_coils_used = 246 /**< Type==int32* ord List of coils finally used when the transformation was computed */
    ,tag_hpi_digitization_order = 247 /**< Type==int32* ord Which Isotrak digitization point corresponds to each of the coils energized */
    ,tag_ch_scan_no = 250 /**< Type==int32 ord Channel scan number. Corresponds to fiffChInfoRec.scanNo field */
    ,tag_ch_logical_no = 251 /**< Type==int32 ord Channel logical number. Corresponds to fiffChInfoRec.logNo field */
    ,tag_ch_kind = 252 /**< Type==enum(ch_type) - Channel type. Corresponds to fiffChInfoRec.kind field */
    ,tag_ch_range = 253 /**< Type==float rel Conversion from recorded number to (possibly virtual) voltage at the output */
    ,tag_ch_cal = 254 /**< Type==float rel Calibration coefficient from output voltage to some real units */
    ,tag_ch_pos = 255 /**< Type==ch_pos_rec - Channel position */
    ,tag_ch_unit = 256 /**< Type==enum(unit) - Unit of the data */
    ,tag_ch_unit_mul = 257 /**< Type==int32 rel Unit multiplier exponent. */
    ,tag_ch_dacq_name = 258 /**< Type==string - Name of the channel in the data acquisition system. Corresponds to fiffChInfoRec.name. */
    ,tag_sss_frame = 263 /**< Type==int32 - SSS expansion coordinate frame */
    ,tag_sss_job = 264 /**< Type==enum(sss_job) - SSS job selection */
    ,tag_sss_origin = 265 /**< Type==float*(3) m SSS expansion origin */
    ,tag_sss_ord_in = 266 /**< Type==int32 - SSS inside expansion order */
    ,tag_sss_ord_out = 267 /**< Type==int32 - SSS outside expansion order */
    ,tag_sss_nmag = 268 /**< Type==int32 - SSS number of MEG channels */
    ,tag_sss_components = 269 /**< Type==int32* - SSS expansion component selections */
    ,tag_sss_cal_chans = 270 /**< Type==int32[*,*] - SSS calibration ch nrs and types */
    ,tag_sss_cal_corrs = 271 /**< Type==float[*,*] - SSS calibration adjustments */
    ,tag_sss_st_corr = 272 /**< Type==float - SSS ST subspace correlation */
    ,tag_sss_base_in = 273 /**< Type==double[*,*] - SSS inside basis matrix */
    ,tag_sss_base_out = 274 /**< Type==double[*,*] - SSS outside basis matrix */
    ,tag_sss_base_virt = 275 /**< Type==double[*,*] - SSS virtual basis matrix */
    ,tag_sss_norm = 276 /**< Type==double - SSS froebious norm of inside basis */
    ,tag_sss_iterate = 277 /**< Type==int32 - SSS nr of iterations */
    ,tag_sss_nfree = 278 /**< Type==int32 - SSS number of degrees of freedom */
    ,tag_sss_st_length = 279 /**< Type==float - SSS ST buffer length */
    ,tag_gantry_type = 280 /**< Type==enum(gantry_type) - The type of the gantry */
    ,tag_gantry_model = 281 /**< Type==string - The modal of the gantry */
    ,tag_gantry_angle = 282 /**< Type==int - Tilt angle of the dewar in degrees */
    ,tag_data_buffer = 300 /**< Type==int16|int32|float - Buffer containing measurement data */
    ,tag_data_skip = 301 /**< Type==int32 card Data skip in buffers */
    ,tag_epoch = 302 /**< Type==float[*,*]|oldpack - Buffer containing one epoch and channel */
    ,tag_data_skip_samp = 303 /**< Type==int32 card Data skip in samples */
    ,tag_data_buffer2 = 304 /**< Type==databuffer2 - Data buffer with int32 time channel */
    ,tag_time_stamp = 305 /**< Type==int32[3] - Measurement time stamp, first element seconds, second microseconds, and third sample number */
    ,tag_subj_id = 400 /**< Type==int32 ord Subject ID */
    ,tag_subj_first_name = 401 /**< Type==string - First name of the subject */
    ,tag_subj_middle_name = 402 /**< Type==string - Middle name of the subject */
    ,tag_subj_last_name = 403 /**< Type==string - Last name of the subject */
    ,tag_subj_birth_day = 404 /**< Type==julian - Birthday of the subject */
    ,tag_subj_sex = 405 /**< Type==enum(sex) - Sex of the subject */
    ,tag_subj_hand = 406 /**< Type==enum(hand) - Handedness of the subject */
    ,tag_subj_weight = 407 /**< Type==float kg Weight of the subject */
    ,tag_subj_height = 408 /**< Type==float m Height of the subject */
    ,tag_subj_comment = 409 /**< Type==string - Comment about the subject */
    ,tag_subj_his_id = 410 /**< Type==string - ID used in the Hospital Information System */
    ,tag_proj_id = 500 /**< Type==int32 - Project ID */
    ,tag_proj_name = 501 /**< Type==string - Project name */
    ,tag_proj_aim = 502 /**< Type==string - Project description */
    ,tag_proj_persons = 503 /**< Type==string - Persons participating in the project */
    ,tag_proj_comment = 504 /**< Type==string - Comment about the project */
    ,tag_event_channels = 600 /**< Type==int32* ord Event channel numbers */
    ,tag_event_list = 601 /**< Type==int32*(n*3) - List of events, 3 integers per event: [number of samples, before, after] */
    ,tag_event_channel = 602 /**< Type==string - Event channel name */
    ,tag_event_bits = 603 /**< Type==int32*(4) - Event bits array describing transition, 4 integers: [from_mask, from_state, to_mask, to_state */
    ,tag_squid_bias = 701 /**< Type==int32 arb Bias setting of a squid */
    ,tag_squid_offset = 702 /**< Type==int32 arb Offset setting of a squid */
    ,tag_squid_gate = 703 /**< Type==int32 arb Gate setting of a squid */
    ,tag_decoupler_matrix = 800 /**< Type==sparse - Cross-talk correction matrix */
    ,tag_volume_type = 2001 /**< Type==enum(volume_type) - Type of the volume */
    ,tag_mri_source_format = 2002 /**< Type==enum(mri_format) - File format of referenced image data */
    ,tag_mri_pixel_encoding = 2003 /**< Type==enum(pixel_encoding) - Pixel type of the stored data */
    ,tag_mri_pixel_data_offset = 2004 /**< Type==int32 ord Offset to the pixel data in the referenced data */
    ,tag_mri_pixel_scale = 2005 /**< Type==float rel Scaling factor from the disk data to unsigned char format */
    ,tag_mri_pixel_data = 2006 /**< Type==byte* rel Pixel data stored in the Fiff file */
    ,tag_mri_pixel_overlay_encoding = 2007 /**< Type==enum(mri_pixel) - Pixel type of the stored overlay data */
    ,tag_mri_pixel_overlay_data = 2008 /**< Type==byte* rel Overlay data stored in the Fiff file */
    ,tag_mri_bounding_box = 2009 /**< Type==float m <obsolete> */
    ,tag_mri_width = 2010 /**< Type==int32 card Number of voxels in x direction */
    ,tag_mri_width_m = 2011 /**< Type==float m Size of the volume in x direction */
    ,tag_mri_height = 2012 /**< Type==int32 card Number of voxels in y direction */
    ,tag_mri_height_m = 2013 /**< Type==float m Size of the volume in y direction */
    ,tag_mri_depth = 2014 /**< Type==int32 card Number of voxels in z direction */
    ,tag_mri_depth_m = 2015 /**< Type==float m Size of the volume in z direction */
    ,tag_mri_thickness = 2016 /**< Type==float m Slice thickness */
    ,tag_mri_scene_aim = 2017 /**< Type==float[3] rel Direction to which the scene snapshot is taken */
    ,tag_mri_calibration_scale = 2018 /**< Type==float rel Scale from disk values to real world values */
    ,tag_mri_calibration_offset = 2019 /**< Type==float rel Offset for scaling to real world values */
    ,tag_mri_orig_source_path = 2020 /**< Type==string - Path to the source file, where this data is derived from. */
    ,tag_mri_orig_source_format = 2021 /**< Type==enum(mri_format) - Format of the source file. */
    ,tag_mri_orig_pixel_encoding = 2022 /**< Type==enum(pixel_encoding) - Pixel type of the source file */
    ,tag_mri_orig_pixel_data_offset = 2023 /**< Type==int32 ord Offset to the pixel data in the source file */
    ,tag_mri_time = 2024 /**< Type==float s Time point of the current volume */
    ,tag_mri_voxel_data = 2030 /**< Type==variable - Volumetric image data */
    ,tag_mri_voxel_encoding = 2031 /**< Type==enum(pixel_encoding) - Encoding for voxel data */
    ,tag_voxel_nchannels = 2032 /**< Type==int32 ord Number of channels in a voxel */
    ,tag_mri_diffusion_weight = 2040 /**< Type==float s/m^2 Diffusion weigting factor a la LeBihan [s/weight (m^2)] */
    ,tag_mri_diffusion_param = 2041 /**< Type==enum(diffusion_param) - What diffusion parameter is mapped in the volume */
    ,tag_mri_mrilab_setup = 2100 /**< <internal> - Used internally. */
    ,tag_mri_seg_region_id = 2200 /**< <internal> - Used internally. */
    ,tag_conductor_model_kind = 3000 /**< Type==enum(cond_model) - What kind of conductor model  */
    ,tag_sphere_origin = 3001 /**< Type==float*(3) - Origin of sphere model */
    ,tag_sphere_coord_frame = 3002 /**< Type==enum(coord) - Which coordinate frame are we using? */
    ,tag_sphere_layers = 3003 /**< Type==layer_struct* - Array of layer structures  */
    ,tag_bem_surf_id = 3101 /**< Type==enum(bem_surf_id) - surface type  */
    ,tag_bem_surf_name = 3102 /**< Type==string - surface name  */
    ,tag_bem_surf_nnode = 3103 /**< Type==int32 card Number of nodes on a surface  */
    ,tag_bem_surf_ntri = 3104 /**< Type==int32 card Number of triangles on a surface  */
    ,tag_bem_surf_nodes = 3105 /**< Type==float* card surface nodes (nnode,3)  */
    ,tag_bem_surf_triangles = 3106 /**< Type==int32* card surface triangles (ntri,3)  */
    ,tag_bem_surf_normals = 3107 /**< Type==float* rel surface node normal unit vectors (nnode,3)  */
    ,tag_bem_surf_curvs = 3108 /**< Type==float* 1/m surface node first principal curvature unit vectors (nnode,3)  */
    ,tag_bem_surf_curv_values = 3109 /**< Type==float 1/m the two curvature values (nnode,2)  */
    ,tag_bem_pot_solution = 3110 /**< Type==float[*,*] - The solution matrix  */
    ,tag_bem_approx = 3111 /**< Type==enum(bem_approx) - Approximation method for bem computation  */
    ,tag_bem_coord_frame = 3112 /**< Type==enum(coord) - The coordinate frame of the model  */
    ,tag_bem_sigma = 3113 /**< Type==float S/m Conductivity of a compartment  */
    ,tag_source_dipole = 3201 /**< Type==float*(6) m,Am Dipole definition. The dipole is six floats (position and dipole moment)  */
    ,tag_beamformer_instructions = 3300 /**< Type==string - Contents of the beamformer instruction file (prototype software)  */
    ,tag_xfit_lead_products = 3401 /**< Type==double* - Lead field matrix data */
    ,tag_xfit_map_products = 3402 /**< Type==double[*,*] - Mapping to isocontour map */
    ,tag_xfit_grad_map_products = 3403 /**< Type==double[*,*] - Mapping to gradient map */
    ,tag_xfit_vol_integration = 3404 /**< Type==bool - Was volume integration used */
    ,tag_xfit_integration_radius = 3405 /**< Type==float m Radius of integration sphere in MNE calculations */
    ,tag_xfit_conductor_model_name = 3406 /**< Type==string - Name of the conductor model used */
    ,tag_xfit_conductor_model_trans_name = 3407 /**< Type==string - Name of the model coordinate transform file */
    ,tag_xfit_cont_surf_type = 3408 /**< Type==enum(map_surf) - Contour surface type in Xfit */
    ,tag_proj_item_kind = 3411 /**< Type==enum(proj_item) - Type of the projection defintion. */
    ,tag_proj_item_time = 3412 /**< Type==float s Time of the field sample (only for proj_item_field) */
    ,tag_proj_item_ign_chs = 3413 /**< Type==int32* ord Channels ignored in the projection definition */
    ,tag_proj_item_nvec = 3414 /**< Type==int32 card Number of projection vectors. */
    ,tag_proj_item_vectors = 3415 /**< Type==float[*,*] rel Projection vectors */
    ,tag_proj_item_definition = 3416 /**< Type==enum(proj_by) - How the projection is defined (subspace or its complement) */
    ,tag_proj_item_ch_name_list = 3417 /**< Type==string - Names of the channels of the projection vectors */
    ,tag_xplotter_layout = 3501 /**< Type==string - Xplotter layout tag */
};

#endif //LFTAGS_H
